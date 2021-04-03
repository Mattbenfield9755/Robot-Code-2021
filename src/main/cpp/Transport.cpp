#include "Transport.h"

Transport::Transport() {}

void Transport::transportRun(){
    transportMotor.Set(10);
}

void Transport::transportStop(){
    transportMotor.Set(0);
}

void Transport::transportJoy(){
    transportMotor.Set(-auxilary.GetRawAxis(5));
}