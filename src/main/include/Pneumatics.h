#pragma once
#include <frc/Joystick.h> 
#include <frc/TimedRobot.h> // Timed Robot Library
#include <iostream> // IO Stream Library 
#include <string> // String Library 
#include "frc/WPILib.h" // WPI Library
#include <math.h> // Math Library 

class Pneumatics {
 public:
  Pneumatics();
    frc::Joystick auxilary{1};

  frc::Compressor compress{0};
  frc::DoubleSolenoid Transport{0,0,1};
  void up();
  void down();
}; 
 