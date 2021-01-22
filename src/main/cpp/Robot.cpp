// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"
#include "frc/WPILib.h"

#include "RobotDriveSwerve.h"
#include "CANTalonEnclosure.h"
#include "ctre/Phoenix.h"

    const double GEAR_RATIO = (1988/1.2);
    const double L = 19;
    const double W = 27.5;

  WPI_TalonSRX * speedMotor1 = new WPI_TalonSRX(11);
  WPI_TalonSRX * speedMotor2 = new WPI_TalonSRX(21);
  WPI_TalonSRX * speedMotor3 = new WPI_TalonSRX(31);
  WPI_TalonSRX * speedMotor4 = new WPI_TalonSRX(41);

  WPI_VictorSPX * angleMotor1 = new WPI_VictorSPX(12);
  WPI_VictorSPX * angleMotor2 = new WPI_VictorSPX(22);
  WPI_VictorSPX * angleMotor3 = new WPI_VictorSPX(32);
  WPI_VictorSPX * angleMotor4 = new WPI_VictorSPX(42);


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

        CANTalonEnclosure swerveEnclosure1* = new CANTalonEnclosure("enc1", speedMotor1, angleMotor1, GEAR_RATIO);
        CANTalonEnclosure swerveEnclosure2* = new CANTalonEnclosure("enc 2", speedMotor2, angleMotor2, GEAR_RATIO);
        CANTalonEnclosure swerveEnclosure3* = new CANTalonEnclosure("enc 3", speedMotor3, angleMotor3, GEAR_RATIO);
        CANTalonEnclosure swerveEnclosure4* = new CANTalonEnclosure("enc 4", speedMotor4, angleMotor4, GEAR_RATIO);

	//Swerve Drive initialization
        RobotDriveSwerve swerveDrive* = new SwerveDrive(	swerveEnclosure1, swerveEnclosure2, swerveEnclosure3, swerveEnclosure4,
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
