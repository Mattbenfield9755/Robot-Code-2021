#pragma once
#include <frc/Joystick.h>
#include <frc/PWMVictorSPX.h>
#include "frc/Victor.h"
#include "frc/CAN.h"
#include "ctre/Phoenix.h"
#include "frc/Timer.h"

class Transport {
private:
  frc::Joystick auxilary{1};
	WPI_TalonSRX transportMotor{3};
  frc::Timer t_timer;

 public:
  Transport();
  void transportRun();
  void transportStop();
  void transportJoy();
};