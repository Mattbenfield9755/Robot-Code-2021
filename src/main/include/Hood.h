#pragma once
#include <frc/Joystick.h>
#include <frc/PWMVictorSPX.h>
#include "frc/Victor.h"
#include "frc/CAN.h"
#include "ctre/Phoenix.h"
#include "frc/Timer.h"
#include <rev/CANSparkMax.h>


class Hood {
private:
  frc::Joystick drive{0};
	WPI_VictorSPX hoodMotor{4};
  frc::Timer t_timer;

 public:
  Hood();
  void hoodUp();
  void hoodDown();
  void hoodNo();
};