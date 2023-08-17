#ifndef SPIN_MOTOR
#define SPIN_MOTOR

#include <Arduino.h>
#include <AccelStepper.h>

//Z MOTORA BAXLANACAK
#define SPIN_MOTOR_PUL 46
#define SPIN_MOTOR_DIR 48

#define STEP_PER_REV 200

extern AccelStepper spinMotor(1, SPIN_MOTOR_PUL, SPIN_MOTOR_DIR);

void init_spin_motor();

void spinCW();
void spinCCW();

#endif