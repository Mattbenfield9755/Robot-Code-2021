#include "Robot.h"
#include "frc/WPILib.h"
#include "RobotDriveSwerve.h"
#include "GenericEnclosure.h"
#include "RobotDriveSwerve.h"
#include "ctre/Phoenix.h"

  const double GEAR_RATIO = (1988/1.2);
  const double L = 19;
  const double W = 27.5; 
  double fwd, str, rcw;


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


void Robot::RobotInit() {
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
void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {}
 
void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {

  static GenericEnclosure *frontLeftWheel = new GenericEnclosure("frontLeftWheel", speedMotor1, angleMotor1, motorEncoder1, GEAR_RATIO);
  static GenericEnclosure *frontRightWheel = new GenericEnclosure("frontRightWheel", speedMotor2, angleMotor2, motorEncoder2, GEAR_RATIO);
 static  GenericEnclosure *rearLeftWheel = new GenericEnclosure("rearLeftWheel", speedMotor3, angleMotor3, motorEncoder3, GEAR_RATIO); 
  static GenericEnclosure *rearRightWheel = new GenericEnclosure("rearRightWheel", speedMotor4, angleMotor4, motorEncoder4, GEAR_RATIO);

   static RobotDriveSwerve *swervy = new RobotDriveSwerve(frontLeftWheel, frontRightWheel, rearLeftWheel, rearRightWheel,W,L);

    swervy->SetMode();
     //     swervy->move();
        //swervy->move(1,1,1,1);
         //swervy->StopMotor();
        swervy->SetMode();

        swervy->move(drive.GetRawAxis(1),drive.GetRawAxis(0),drive.GetRawAxis(2),-999.0);

      fwd = -drive.GetRawAxis(5);
    	str = drive.GetRawAxis(4);
    	rcw = drive.GetRawAxis(0);
    	
    	//Square the values for finer movement
    /*	if(fwd < 0)
    		fwd *= fwd * -1;
    	else
    		fwd *= fwd;
    	
    	if(str < 0)
    		str *= str * -1;
    	else
    		str *= str;
    	
    	if(rcw < 0)
    		rcw *= rcw * -1;
    	else
      */
    		rcw *= rcw;
        swervy->move(fwd,str,rcw);
        frc::SmartDashboard::PutNumber("x1",drive.GetRawAxis(1));
        frc::SmartDashboard::PutNumber("x2",drive.GetRawAxis(0));
        frc::SmartDashboard::PutNumber("rotate",drive.GetRawAxis(2));

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
