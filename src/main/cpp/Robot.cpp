#include "Robot.h"
#include "frc/WPILib.h"
#include "RobotDriveSwerve.h"
#include "GenericEnclosure.h"
#include "RobotDriveSwerve.h"
#include "ctre/Phoenix.h"

  const double GEAR_RATIO = (1988/1.2);
  const double L = 19;
  const double W = 27.5; 

  frc::Joystick drive{0};
  
  std::shared_ptr<WPI_TalonSRX> speedMotor1; 
  std::shared_ptr<WPI_TalonSRX> speedMotor2; 
  std::shared_ptr<WPI_TalonSRX> speedMotor3; 
  std::shared_ptr<WPI_TalonSRX> speedMotor4; 

  std::shared_ptr<WPI_VictorSPX> angleMotor1;
  std::shared_ptr<WPI_VictorSPX> angleMotor2; 
  std::shared_ptr<WPI_VictorSPX> angleMotor3; 
  std::shared_ptr<WPI_VictorSPX> angleMotor4; 

  std::shared_ptr<frc::Encoder> motorEncoder1;
  std::shared_ptr<frc::Encoder> motorEncoder2; 
  std::shared_ptr<frc::Encoder> motorEncoder3; 
  std::shared_ptr<frc::Encoder> motorEncoder4;  
    // --- MOTOR LAYOUT ---
    /*
	 *                  Front
	 *      Wheel 2 -------------- Wheel 1
	 *          |                   |
	 *          |                   |
	 *          |                   |
	 *   Left   |                   |   Right
	 *          |                   |
	 *          |                   |
	 *          |                   |
	 *      Wheel 3 -------------- Wheel 4
	 *                  Back
	 */


void Robot::RobotInit() {}
void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {}
 
void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {
  //Enclosure 1
  speedMotor1= std::make_shared<WPI_TalonSRX>(11);
  angleMotor1= std::make_shared<WPI_VictorSPX>(12);
  motorEncoder1= std::make_shared<frc::Encoder>(1,0);

  //Enclosure 2
  speedMotor2= std::make_shared<WPI_TalonSRX>(21);
  angleMotor2= std::make_shared<WPI_VictorSPX>(22);
  motorEncoder2= std::make_shared<frc::Encoder>(3,2);

  //Enclosure 3
  speedMotor3= std::make_shared<WPI_TalonSRX>(31);
  angleMotor3= std::make_shared<WPI_VictorSPX>(32);
  motorEncoder3= std::make_shared<frc::Encoder>(5,4);

  //Enclosure 4
  speedMotor4= std::make_shared<WPI_TalonSRX>(41);
  angleMotor4= std::make_shared<WPI_VictorSPX>(42);
  motorEncoder4= std::make_shared<frc::Encoder>(7,6);


}
void Robot::TeleopPeriodic() {

        GenericEnclosure frontLeftWheel{"FrontLeftWheel", speedMotor1, angleMotor1, motorEncoder1, GEAR_RATIO};
        GenericEnclosure frontRightWheel{"FrontRightWheel", speedMotor2, angleMotor2, motorEncoder2, GEAR_RATIO};
        GenericEnclosure rearLeftWheel{"RearLeftWheel", speedMotor3, angleMotor3, motorEncoder3, GEAR_RATIO}; 
        GenericEnclosure rearRightWheel{"RearRightWheel", speedMotor4, angleMotor4, motorEncoder4, GEAR_RATIO};

	//Swerve Drive initialization
     RobotDriveSwerve * swerveDrive{frontRightWheel, frontLeftWheel, rearLeftWheel, rearRightWheel,W, L} 
          //swerveDrive->SetMode();
          //swerveDrive->move(drive.GetRawAxis(1), drive.GetRawAxis(2), drive.GetRawAxis(3), 0);

}

void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
