#pragma once
#include <frc/Joystick.h>
#include <frc/PWMVictorSPX.h>
#include "frc/Victor.h"
#include "frc/CAN.h"
#include "ctre/Phoenix.h"
#include "frc/Timer.h"

class Intake {
private:
  frc::Joystick auxilary{1};
	WPI_TalonSRX intakeMotor{10};
  frc::Timer t_timer;

 public:
  Intake();
  void intakeRun();
  void intakeStop();
  void intakeJoy();
};