#include <PKAE_Timer.h>

#define MY_POWER   2       // NPN
#define Switch     4       // Button
#define RELAY_PIN  3       // Relay

#define RED_PIN    9
#define GREEN_PIN 10
#define BLUE_PIN  11

void setup() {
  pinMode(MY_POWER, OUTPUT);
  digitalWrite(MY_POWER, HIGH);   

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);  

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(Switch, INPUT_PULLUP);

  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void loop() {
  setColor(255, 0, 0);   //Red
  delay(1000);
  setColor(0, 255, 0);   // Green
  delay(1000);
  setColor(0, 0, 255);   // Blue
  delay(1000);
  setColor(255, 255, 0); // Yellow
  delay(1000);
  setColor(0, 255, 255); // Cyan
  delay(1000);
  setColor(255, 0, 255); // Purple
  delay(1000);
  setColor(255, 255, 255); // White
  delay(1000);
  setColor(0, 0, 0);     // Off
  delay(1000);
  boolean lLEDstate = LOW, lReleased = true;

  PKAE_Timer StableLED(0);
  PKAE_Timer ButtonHeld(3000);
  PKAE_Timer AutoShutdown(10000); 

  while (true) {
    if (digitalRead(Switch) == LOW) {
      if (lReleased && StableLED.IsTimeUp()) {
        lLEDstate = !lLEDstate;
        digitalWrite(LED_BUILTIN, lLEDstate);
      }
      lReleased = false;
    } 
    else {
      lReleased = true;
      ButtonHeld.Reset();
    }

    if (ButtonHeld.IsTimeUp() || AutoShutdown.IsTimeUp()) KillPower();
  }
}

void setColor(int red, int green, int blue) {
  analogWrite(RED_PIN, red);
  analogWrite(GREEN_PIN, green);
  analogWrite(BLUE_PIN, blue);
}
void KillPower() {
  digitalWrite(MY_POWER, LOW);    
  digitalWrite(RELAY_PIN, LOW);   

  
}
