#pragma once

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/Joystick.h.>
#include <frc/DriverStation.h>
#include "AHRS.h"

using namespace frc;

class Robot : public TimedRobot
{
public:
 
  void RobotInit() override;
  void RobotPeriodic() override;

  void AutonomousInit() override;
  void AutonomousPeriodic() override;

  void TeleopInit() override;
  void TeleopPeriodic() override;

  void DisabledInit() override;
  void DisabledPeriodic() override;

  void TestInit() override;
  void TestPeriodic() override;

private:
  const static int joystickChannel = 0;
  AHRS *ahrs;
  int autoLoopCounter;
};

