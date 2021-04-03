// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Pneumatics.h"

Pneumatics::Pneumatics() = default;

void Pneumatics::up()
  {
      Transport.Set(frc::DoubleSolenoid::Value::kForward);
  }

void Pneumatics::down()
  {
      Transport.Set(frc::DoubleSolenoid::Value::kReverse);
  }