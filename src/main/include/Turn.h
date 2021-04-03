#pragma once
#include <frc/Joystick.h>
#include <frc/PWMVictorSPX.h>
#include "frc/Victor.h"
#include "frc/CAN.h"
#include "ctre/Phoenix.h"
#include "frc/Timer.h"
#include <rev/CANSparkMax.h>


class Turn {
private:
  frc::Joystick auxilary{1};
	WPI_VictorSPX turnMotor{9};
  //shooterMotor->GetEncoder(); 
  frc::Timer t_timer;

 public:
  Turn();
  void turnLeft();
  void turnRight();
  void turnNo();
};