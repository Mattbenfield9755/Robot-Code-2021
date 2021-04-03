#include "Robot.h"
#include "frc/WPILib.h"
#include "Swerve/RobotDriveSwerve.h"
#include "Swerve/GenericEnclosure.h"
#include "Swerve/RobotDriveSwerve.h"
#include <frc/livewindow/LiveWindow.h>
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"
#include "ctre/Phoenix.h"
#include "Vision.h"
#include "Intake.h"
#include "Pneumatics.h"
#include "Transport.h"
#include "Hood.h"
#include "Shooter.h"
#include "Turn.h"

  const double GEAR_RATIO = 1;
  const double L = 19;
  const double W = 27.5; 
  double fwd, str, rcw;

  Vision v;
  Intake i;
  Pneumatics p;
  Transport t;
  Turn z;
  Shooter s;
  Hood h;

  frc::Joystick drive{0};
  frc::Joystick auxilary{1};
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



  void limeLight()
  {
    nt::NetworkTableInstance::GetDefault().GetTable("limelight")->PutNumber("ledMode", 1);
    if (auxilary.GetRawButton(1))
    {
      v.AutoTarget();
    }
    else
    {
      v.visionStop();
    }
  }

  void pullUp(){
    i.intakeJoy();
  }

  void air(){
    if(auxilary.GetRawButton(5)){
      p.up();
    }else if(auxilary.GetRawButton(6)){
      p.down();
    }
  }

  void trans(){
   t.transportJoy();
  }

  void shoot(){
    s.shooterJoy();
  }

  void table(){

    z.turnNo();
  }

  void hoodBruh(){
    if(auxilary.GetRawButton(7)){
      h.hoodUp();
    }else
    {
      h.hoodNo();
    }
    
  }



void Robot::RobotInit() {
  ahrs = new AHRS(SPI::Port::kMXP);

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
 
void Robot::AutonomousPeriodic() {
  
  static GenericEnclosure *frontLeftWheel = new GenericEnclosure("frontLeftWheel", speedMotor1, angleMotor1, motorEncoder1, GEAR_RATIO);
  static GenericEnclosure *frontRightWheel = new GenericEnclosure("frontRightWheel", speedMotor2, angleMotor2, motorEncoder2, GEAR_RATIO);
  static  GenericEnclosure *rearLeftWheel = new GenericEnclosure("rearLeftWheel", speedMotor3, angleMotor3, motorEncoder3, GEAR_RATIO); 
  static GenericEnclosure *rearRightWheel = new GenericEnclosure("rearRightWheel", speedMotor4, angleMotor4, motorEncoder4, GEAR_RATIO);
    
  
    
    frontLeftWheel->MoveWheel(.2, 0);
    frontRightWheel->MoveWheel(.2, 0);
    rearRightWheel->MoveWheel(.2, 0);
    rearLeftWheel->MoveWheel(.2, 0);
  

    while(drive.GetRawButton(1)){
    frontLeftWheel->MoveWheel(-drive.GetRawAxis(2), 152);
    frontRightWheel->MoveWheel(-drive.GetRawAxis(2), 52);
    rearRightWheel->MoveWheel(-drive.GetRawAxis(2), -52);
    rearLeftWheel->MoveWheel(-drive.GetRawAxis(2), 52);

  }
    frontLeftWheel->MoveWheel(drive.GetRawAxis(1)*(drive.GetRawAxis(3)*-1), drive.GetRawAxis(0)*-100);
    frontRightWheel->MoveWheel(drive.GetRawAxis(1)*(drive.GetRawAxis(3)*-1), drive.GetRawAxis(0)*-100);
    rearRightWheel->MoveWheel(drive.GetRawAxis(1)*(drive.GetRawAxis(3)*-1), drive.GetRawAxis(0)*-100);
    rearLeftWheel->MoveWheel(drive.GetRawAxis(1)*(drive.GetRawAxis(3)*-1), drive.GetRawAxis(0)*-100);
  
    
}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {
  
  
  static GenericEnclosure *enc1 = new GenericEnclosure("enc1", speedMotor1, angleMotor1, motorEncoder1, GEAR_RATIO);
  static GenericEnclosure *enc2 = new GenericEnclosure("enc2", speedMotor2, angleMotor2, motorEncoder2, GEAR_RATIO);
  static GenericEnclosure *enc3 = new GenericEnclosure("enc3", speedMotor3, angleMotor3, motorEncoder3, GEAR_RATIO); 
  static GenericEnclosure *enc4 = new GenericEnclosure("enc4", speedMotor4, angleMotor4, motorEncoder4, GEAR_RATIO);
  
  static RobotDriveSwerve *swervy = new RobotDriveSwerve(enc1, enc2, enc3, enc4,W,L);

  
  if(auxilary.GetRawButton(5)){
    p.down();
  }
  if(auxilary.GetRawButton(6)){
    p.up();
  }
  limeLight();
  pullUp();
  //air();
  trans();
  shoot();
  hoodBruh();
  table();
  
  frc::SmartDashboard::PutNumber("enc1", motorEncoder1->GetDistance());
	frc::SmartDashboard::PutNumber("en2", motorEncoder2->GetDistance());
	frc::SmartDashboard::PutNumber("end3", motorEncoder3->GetDistance());
	frc::SmartDashboard::PutNumber("enc4",motorEncoder4->GetDistance());

  while(drive.GetRawButton(1)){
    enc1->MoveWheel(-drive.GetRawAxis(2), 152);
    enc2->MoveWheel(-drive.GetRawAxis(2), 52);
    enc3->MoveWheel(-drive.GetRawAxis(2), -52);
    enc4->MoveWheel(-drive.GetRawAxis(2), 52);
     limeLight();
  pullUp();
  //air();
  trans();
  shoot();

  }
    enc1->MoveWheel(drive.GetRawAxis(1)*(drive.GetRawAxis(3)*-1), drive.GetRawAxis(0)*-100);
    enc2->MoveWheel(drive.GetRawAxis(1)*(drive.GetRawAxis(3)*-1), drive.GetRawAxis(0)*-100);
    enc3->MoveWheel(drive.GetRawAxis(1)*(drive.GetRawAxis(3)*-1), drive.GetRawAxis(0)*-100);
    enc4->MoveWheel(drive.GetRawAxis(1)*(drive.GetRawAxis(3)*-1), drive.GetRawAxis(0)*-100);
  SmartDashboard::PutNumber("IMU_Yaw", ahrs->GetYaw());

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