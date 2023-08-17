#ifndef TOURCH_MOTOR
#define TOURCH_MOTOR

#include <Arduino.h>
#include <AccelStepper.h>

//E0 MOTORA BAXLANACAK
#define TOURCH_MOTOR_PUL 26
#define TOURCH_MOTOR_DIR 28

extern AccelStepper tourchMotor(1, TOURCH_MOTOR_PUL, TOURCH_MOTOR_DIR);


#endif