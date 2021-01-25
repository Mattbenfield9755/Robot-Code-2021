#include "Robot.h"
#include "frc/WPILib.h"
#include "RobotDriveSwerve.h"
#include "CANTalonEnclosure.h"
#include "ctre/Phoenix.h"

  const double GEAR_RATIO = (1988/1.2);
  const double L = 19;
  const double W = 27.5; 
  
  WPI_TalonSRX speedMotor1 {11}; 
  WPI_TalonSRX speedMotor2 {21};
  WPI_TalonSRX speedMotor3 {31};
  WPI_TalonSRX speedMotor4 {41};

  WPI_VictorSPX angleMotor1 {12};
  WPI_VictorSPX angleMotor2 {22};
  WPI_VictorSPX angleMotor3 {32};
  WPI_VictorSPX angleMotor4 {42};


  frc::Encoder motor1Encoder{1,0};
  frc::Encoder motor2Encoder{3,2};
  frc::Encoder motor3Encoder{5,4};
  frc::Encoder motor4Encoder{7,6};
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

void Robot::TeleopInit() {}
void Robot::TeleopPeriodic() {

        CANTalonEnclosure swerveEnclosure1{"enc 1", speedMotor1, angleMotor1,  GEAR_RATIO};
  //      CANTalonEnclosure swerveEnclosure2{"enc 2", GEAR_RATIO};
      //  CANTalonEnclosure swerveEnclosure3{"enc 3", GEAR_RATIO};
      //  CANTalonEnclosure swerveEnclosure4{"enc 4", GEAR_RATIO};

	//Swerve Drive initialization
        RobotDriveSwerve * swerveDrive= new SwerveDrive(swerveEnclosure1, swerveEnclosure2, swerveEnclosure3, swerveEnclosure4,
					W, L);

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
