#pragma once
#include <frc/Joystick.h>
#include <frc/PWMVictorSPX.h>
#include "frc/Victor.h"
#include "frc/CAN.h"
#include <frc/livewindow/LiveWindow.h>
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"
#include "frc/smartdashboard/SmartDashboard.h"
#include <frc/smartdashboard/SendableChooser.h>
#include "frc/smartdashboard/SendableBuilderImpl.h"
#include "ctre/Phoenix.h"
#include "frc/PIDController.h"
#include <iostream> 
#include <string> 

class Vision
{
private:
  frc::Joystick auxilary{1};
	WPI_VictorSPX * spin = new WPI_VictorSPX(4);
  std::shared_ptr<NetworkTable> ITable = nt::NetworkTableInstance::GetDefault().GetTable("limelight");

public:
  Vision();
  void AutoTarget();
  void visionStop();
  void leftManual();
  void rightManual();
};