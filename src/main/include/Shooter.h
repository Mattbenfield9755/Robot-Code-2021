#pragma once
#include <frc/Joystick.h>
#include <frc/PWMTalonSRX.h>
#include <frc/Victor.h>
#include "frc/Victor.h"
#include "frc/CAN.h"
#include "ctre/Phoenix.h"
#include "frc/Timer.h"
#include <rev/CANSparkMax.h>


class Shooter {
private:
  frc::Joystick drive{0};
    frc::Joystick auxilary{1};

	WPI_TalonSRX shooterMotor1{27};
  WPI_VictorSPX shooterMotor2{14};

  frc::Timer t_timer;

 public:
  Shooter();
  void shooterRun();
  void shooterStop();
  void shooterJoy();
};