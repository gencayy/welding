#include "SpinTable.h"
#include "potansiyometer/SpeedPot.h"

AccelStepper spinMotor(1, SPIN_MOTOR_PUL, SPIN_MOTOR_DIR);


void init_spin_motor()
{
    spinMotor.setMaxSpeed(100);
    spinMotor.setAcceleration(100);
    spinMotor.setSpeed(100);
}

void spinCW()
{
  spinMotor.move(200);

  while(spinMotor.currentPosition() != 200){

    int potValue = (int) readPotVaules();

    // Potansiyometre değerini hız aralığına dönüştürün
    // Örneğin, 0-1023 arasındaki analog değeri 1000-2000 adım/s arasındaki hıza dönüştürebilirsiniz
    float speed = map(potValue, 0, 1023, 1000, 2000);

    // Adım motorunun hızını güncelleyin
    spinMotor.setSpeed(speed);

    // Adım motorunu belirtilen hızda hareket ettirin
    spinMotor.runSpeed();
  }
  return;
}

void spinCCW()
{
   spinMotor.move(-200);

  while(spinMotor.currentPosition() != -200){

    int potValue = (int) readPotVaules();

    // Potansiyometre değerini hız aralığına dönüştürün
    // Örneğin, 0-1023 arasındaki analog değeri 1000-2000 adım/s arasındaki hıza dönüştürebilirsiniz
    float speed = map(potValue, 0, 1023, 1000, 2000);

    // Adım motorunun hızını güncelleyin
    spinMotor.setSpeed(speed);

    // Adım motorunu belirtilen hızda hareket ettirin
    spinMotor.runSpeed();
  }
  return;
}
