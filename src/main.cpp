#include <Arduino.h>
#include "servo/TourchTrigger.h"
#include "button/StartButton.h"
#include "steppers/SpinTable.h"

void setup() {

  init_servo_motor();
  init_start_button();
  init_spin_motor();

}

void loop() {
  debounceHandle();
}

