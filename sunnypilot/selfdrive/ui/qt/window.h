/**
 * Copyright (c) 2021-, Haibin Wen, sunnypilot, and a number of other contributors.
 *
 * This file is part of sunnypilot and is licensed under the MIT License.
 * See the LICENSE.md file in the root directory for more details.
 */

#pragma once

#include "selfdrive/ui/qt/window.h"
#include "../../sunnypilot/selfdrive/ui/qt/home.h"
#include "../../sunnypilot/selfdrive/ui/qt/offroad/settings/settings.h"
#include "offroad/settings/onboarding.h"

class MainWindowSP : public MainWindow {
  Q_OBJECT

public:
  explicit MainWindowSP(QWidget *parent = 0);

private:
  HomeWindowSP *homeWindow;
  SettingsWindowSP *settingsWindow;
  OnboardingWindowSP *onboardingWindow;
  void closeSettings() override;
};
