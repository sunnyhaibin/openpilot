# The MIT License
#
# Copyright (c) 2019-, Rick Lan, dragonpilot community, and a number of other of contributors.
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.

# Last updated: August 12, 2024
from cereal import custom
from openpilot.common.numpy_fast import interp
from openpilot.common.realtime import DT_MDL
from openpilot.common.params import Params

AccelPersonality = custom.LongitudinalPlanSP.AccelerationPersonality

# Accel personality by @arne182 modified by cgw and kumar

_DP_CRUISE_MIN_V_ECO =    [-0.02, -0.02, -0.85, -0.85, -0.85, -0.85, -1.2,  -1.2]
_DP_CRUISE_MIN_V_NORMAL = [-0.02, -0.02, -0.90, -0.90, -0.90, -0.90, -1.2,  -1.2]
_DP_CRUISE_MIN_V_SPORT =  [-0.02, -0.02, -1.0,  -1.0,  -1.0,  -1.0,  -1.2,  -1.2]
_DP_CRUISE_MIN_BP =       [0.,     2.0,    2.01,   15.,   15.01, 20.,   20.01, 40.]

_DP_CRUISE_MAX_V_ECO =    [1.60, 1.60, 1.58, 1.58, 0.86, .532, .432, .32,  .28,  .085]
_DP_CRUISE_MAX_V_NORMAL = [1.80, 1.80, 1.75, 1.75, 0.92, .65,  .56,  .36,  .30,  .12]
_DP_CRUISE_MAX_V_SPORT =  [2.00, 2.00, 2.00, 2.00, 1.05, .79,  .61,  .42,  .333, .2]
_DP_CRUISE_MAX_BP =       [0.,   1.,   6.,   8.,   11.,  16,   20.,  25.,  30.,  55.]


class AccelController:
  def __init__(self):
    self._params = Params()
    self._personality = AccelPersonality.stock
    self._frame = 0

  def _read_params(self):
    if self._frame % int(1. / DT_MDL) == 0:
      personality_str = self._params.get("AccelPersonality", encoding='utf-8')
      if personality_str is not None:
        personality_int = int(personality_str)
        if personality_int in [AccelPersonality.stock, AccelPersonality.normal, AccelPersonality.eco, AccelPersonality.sport]:
          self._personality = personality_int

  def _dp_calc_cruise_accel_limits(self, v_ego: float) -> tuple[float, float]:
    self._read_params()  # Ensure personality updates

    if self._personality == AccelPersonality.eco:
      min_v = _DP_CRUISE_MIN_V_ECO
      max_v = _DP_CRUISE_MAX_V_ECO
      #print("ECO")
    elif self._personality == AccelPersonality.sport:
      min_v = _DP_CRUISE_MIN_V_SPORT
      max_v = _DP_CRUISE_MAX_V_SPORT
      #print("SPORT")
    else:
      min_v = _DP_CRUISE_MIN_V_NORMAL
      max_v = _DP_CRUISE_MAX_V_NORMAL
      #print("NORMAL")

    a_cruise_min = interp(v_ego, _DP_CRUISE_MIN_BP, min_v)
    a_cruise_max = interp(v_ego, _DP_CRUISE_MAX_BP, max_v)

    return a_cruise_min, a_cruise_max

  def get_accel_limits(self, v_ego: float, accel_limits: list[float]) -> tuple[float, float]:
    self._read_params()
    return accel_limits if self._personality == AccelPersonality.stock else self._dp_calc_cruise_accel_limits(v_ego)

  def is_enabled(self, accel_personality: int = AccelPersonality.stock) -> bool:
    self._personality = accel_personality
    return self._personality != AccelPersonality.stock

  def update(self):
    self._frame += 1