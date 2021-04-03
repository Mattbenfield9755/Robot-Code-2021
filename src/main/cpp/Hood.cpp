#include "Hood.h"

Hood::Hood() {}

void Hood::hoodDown(){
    hoodMotor.Set(-.5);
}

void Hood::hoodUp(){
    hoodMotor.Set(.5);
}

void Hood::hoodNo(){
    hoodMotor.Set(0);
}