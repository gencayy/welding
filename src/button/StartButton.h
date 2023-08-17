#ifndef START_BUTTON
#define START_BUTTON

#include <Arduino.h>


#define BUTTON_PIN 19

extern int buttonState = LOW;
extern long lastDebounceTime = 0;
extern long debounceDelay = 200;

void init_start_button();
void debounceHandle();

#endif