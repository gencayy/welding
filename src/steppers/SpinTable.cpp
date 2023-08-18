#include "SpinTable.h"
#include "potansiyometer/SpeedPot.h"

#define NUM_STEPS 1600

AccelStepper spinMotor(1, SPIN_MOTOR_PUL, SPIN_MOTOR_DIR);


void init_spin_motor()
{
    //spinMotor.setEnablePin(SPIN_MOTOR_ENA);
    spinMotor.setMaxSpeed(1000);
    spinMotor.setAcceleration(100);
    spinMotor.setSpeed(100);
    pinMode(SPIN_MOTOR_ENA, OUTPUT);
    digitalWrite(SPIN_MOTOR_ENA, LOW);
    //spinMotor.enableOutputs();
}

void spinCW()
{
  delay(1000);
  digitalWrite(SPIN_MOTOR_ENA, LOW);
  spinMotor.move(NUM_STEPS);

  while(spinMotor.currentPosition() != NUM_STEPS){

    int potValue = (int) readPotVaules();

    // Potansiyometre değerini hız aralığına dönüştürün
    // Örneğin, 0-1023 arasındaki analog değeri 1000-2000 adım/s arasındaki hıza dönüştürebilirsiniz
    float speed = map(potValue, 0, 1023, 0,800);


    // Adım motorunun hızını güncelleyin
    spinMotor.setSpeed(speed);
    //Serial.println(speed);

    // Adım motorunu belirtilen hızda hareket ettirin
    spinMotor.runSpeed();
  }
  spinMotor.setCurrentPosition(0);
  delay(1000);

  return;
}

void spinCCW()
{
   spinMotor.move(-200);

  while(spinMotor.currentPosition() != -200){

    int potValue = (int) readPotVaules();

    // Potansiyometre değerini hız aralığına dönüştürün
    // Örneğin, 0-1023 arasındaki analog değeri 1000-2000 adım/s arasındaki hıza dönüştürebilirsiniz
    float speed = map(potValue, 0, 1023, 0, 1000);

    // Adım motorunun hızını güncelleyin
    spinMotor.setSpeed(speed);

    // Adım motorunu belirtilen hızda hareket ettirin
    spinMotor.runSpeed();
  }
  return;
}

void stopStepper()
{
    spinMotor.stop();
    spinMotor.setCurrentPosition(0);
    return;
}
