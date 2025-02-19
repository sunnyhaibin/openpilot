"""
The MIT License

Copyright (c) 2021-, Haibin Wen, sunnypilot, and a number of other contributors.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

Last updated: July 29, 2024
"""

from cereal import car, log, custom

from opendbc.car.hyundai.values import HyundaiFlags
from opendbc.sunnypilot.car.hyundai.values import HyundaiFlagsSP

from openpilot.sunnypilot.mads.helpers import MadsParams
from openpilot.sunnypilot.mads.state import StateMachine, GEARS_ALLOW_PAUSED_SILENT

State = custom.ModularAssistiveDrivingSystem.ModularAssistiveDrivingSystemState
ButtonType = car.CarState.ButtonEvent.Type
EventName = log.OnroadEvent.EventName
EventNameSP = custom.OnroadEventSP.EventName
SafetyModel = car.CarParams.SafetyModel

SET_SPEED_BUTTONS = (ButtonType.accelCruise, ButtonType.resumeCruise, ButtonType.decelCruise, ButtonType.setCruise)
IGNORED_SAFETY_MODES = (SafetyModel.silent, SafetyModel.noOutput)


class ModularAssistiveDrivingSystem:
  def __init__(self, selfdrive):
    self.mads_params = MadsParams()

    self.enabled = False
    self.active = False
    self.available = False
    self.allow_always = False
    self.selfdrive = selfdrive
    self.selfdrive.enabled_prev = False
    self.state_machine = StateMachine(self)
    self.events = self.selfdrive.events
    self.events_sp = self.selfdrive.events_sp

    if self.selfdrive.CP.brand == "hyundai":
      if (self.selfdrive.CP_SP.flags & HyundaiFlagsSP.HAS_LFA_BUTTON) or \
            (self.selfdrive.CP.flags & HyundaiFlags.CANFD):
        self.allow_always = True

    # read params on init
    self.enabled_toggle = self.mads_params.read_param("Mads")
    self.main_enabled_toggle = self.mads_params.read_param("MadsMainCruiseAllowed")
    self.pause_lateral_on_brake_toggle = self.mads_params.read_param("MadsPauseLateralOnBrake")
    self.unified_engagement_mode = self.mads_params.read_param("MadsUnifiedEngagementMode")

  def read_params(self):
    self.main_enabled_toggle = self.mads_params.read_param("MadsMainCruiseAllowed")
    self.unified_engagement_mode = self.mads_params.read_param("MadsUnifiedEngagementMode")

  def update_events(self, CS: car.CarState):
    def update_unified_engagement_mode():
      uem_blocked = self.enabled or (self.selfdrive.enabled and self.selfdrive.enabled_prev)
      if (self.unified_engagement_mode and uem_blocked) or not self.unified_engagement_mode:
        self.events.remove(EventName.pcmEnable)
        self.events.remove(EventName.buttonEnable)

    def transition_paused_state():
      if self.state_machine.state != State.paused:
        self.events_sp.add(EventNameSP.silentLkasDisable)

    def replace_event(old_event: int, new_event: int):
      self.events.remove(old_event)
      self.events_sp.add(new_event)

    if not self.selfdrive.enabled and self.enabled:
      if self.events.has(EventName.doorOpen):
        replace_event(EventName.doorOpen, EventNameSP.silentDoorOpen)
        transition_paused_state()
      if self.events.has(EventName.seatbeltNotLatched):
        replace_event(EventName.seatbeltNotLatched, EventNameSP.silentSeatbeltNotLatched)
        transition_paused_state()
      if self.events.has(EventName.wrongGear):
        replace_event(EventName.wrongGear, EventNameSP.silentWrongGear)
        transition_paused_state()
      if self.events.has(EventName.reverseGear):
        replace_event(EventName.reverseGear, EventNameSP.silentReverseGear)
        transition_paused_state()
      if self.events.has(EventName.brakeHold):
        replace_event(EventName.brakeHold, EventNameSP.silentBrakeHold)
        transition_paused_state()
      if self.events.has(EventName.parkBrake):
        replace_event(EventName.parkBrake, EventNameSP.silentParkBrake)
        transition_paused_state()

      if self.pause_lateral_on_brake_toggle:
        if CS.brakePressed:
          transition_paused_state()

      if not (self.pause_lateral_on_brake_toggle and CS.brakePressed) and \
         not self.events_sp.contains_in_list(GEARS_ALLOW_PAUSED_SILENT):
        if self.state_machine.state == State.paused:
          self.events_sp.add(EventNameSP.silentLkasEnable)

      self.events.remove(EventName.preEnableStandstill)
      self.events.remove(EventName.belowEngageSpeed)
      self.events.remove(EventName.speedTooLow)
      self.events.remove(EventName.cruiseDisabled)
      self.events.remove(EventName.manualRestart)

    if self.events.has(EventName.pcmEnable) or self.events.has(EventName.buttonEnable):
      update_unified_engagement_mode()
    else:
      if self.main_enabled_toggle:
        if CS.cruiseState.available and not self.selfdrive.CS_prev.cruiseState.available:
          self.events_sp.add(EventNameSP.lkasEnable)

    for be in CS.buttonEvents:
      if be.type == ButtonType.cancel:
        if not self.selfdrive.enabled and self.selfdrive.enabled_prev:
          self.events_sp.add(EventNameSP.manualLongitudinalRequired)
      if be.type == ButtonType.lkas and be.pressed and (CS.cruiseState.available or self.allow_always):
        if self.enabled:
          if self.selfdrive.enabled:
            self.events_sp.add(EventNameSP.manualSteeringRequired)
          else:
            self.events_sp.add(EventNameSP.lkasDisable)
        else:
          self.events_sp.add(EventNameSP.lkasEnable)

    if not CS.cruiseState.available:
      self.events.remove(EventName.buttonEnable)
      if self.selfdrive.CS_prev.cruiseState.available:
        self.events_sp.add(EventNameSP.lkasDisable)

    self.events.remove(EventName.pcmDisable)
    self.events.remove(EventName.buttonCancel)
    self.events.remove(EventName.pedalPressed)
    self.events.remove(EventName.wrongCruiseMode)
    if not any(be.type in SET_SPEED_BUTTONS for be in CS.buttonEvents):
      self.events.remove(EventName.wrongCarMode)

  def update(self, CS: car.CarState):
    if not self.enabled_toggle:
      return

    self.update_events(CS)

    if not self.selfdrive.CP.passive and self.selfdrive.initialized:
      self.enabled, self.active = self.state_machine.update()

    # Copy of previous SelfdriveD states for MADS events handling
    self.selfdrive.enabled_prev = self.selfdrive.enabled
