#include "Intake.h"

Intake::Intake() {}

void Intake::intakeRun(){
    intakeMotor.Set(10);
}

void Intake::intakeStop(){
    intakeMotor.Set(0);
}

void Intake::intakeJoy(){
        intakeMotor.Set(-auxilary.GetRawAxis(1));
}