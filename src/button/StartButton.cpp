#include "StartButton.h"


int buttonState = LOW;
long lastDebounceTime = 0;
long debounceDelay = 200;

void init_start_button()
{
    pinMode(BUTTON_PIN, INPUT);
}


// başlama koşulu belirlenecek.
void debounceHandle()
{
    buttonState = digitalRead(BUTTON_PIN);

  if ( (millis() - lastDebounceTime) > debounceDelay) {
    // Eger butona basılmışsa ve makine çalışır durumda değilse
    if( buttonState  == HIGH){

      closeTourch();
      delay(1000);

      spinCW();
      delay(1000);
 
      openTourch();

      lastDebounceTime = millis();
      
    }
    // eger butona basılmışsa ve makine çalışır durumdaysa
    else if (buttonState == HIGH){

      stopStepper();
    
      lastDebounceTime = millis();
    
    }
  }
}
