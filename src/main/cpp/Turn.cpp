#include "Turn.h"

Turn::Turn() {}

void Turn::turnLeft(){
    turnMotor.Set(-10);
}

void Turn::turnRight(){
    turnMotor.Set(10);
}

void Turn::turnNo(){
    turnMotor.Set(auxilary.GetRawAxis(0));
}