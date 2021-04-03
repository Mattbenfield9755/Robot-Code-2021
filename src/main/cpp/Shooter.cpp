#include "Shooter.h"

Shooter::Shooter() {}

void Shooter::shooterRun(){
    shooterMotor1.Set(-1);
    shooterMotor2.Set(-1);
}

void Shooter::shooterStop(){
    shooterMotor1.Set(0);
}

void Shooter::shooterJoy(){
    shooterMotor1.Set(auxilary.GetRawAxis(3));
    shooterMotor2.Set(auxilary.GetRawAxis(3));
}