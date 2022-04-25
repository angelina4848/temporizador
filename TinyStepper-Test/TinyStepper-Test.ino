/*
  TinyStepper - Stepper Motor Test
 comment for version
  by Jason A. Cox - @jasonacox

  Date: 19 July 2020

*/

#include <TinyStepper.h>
uint32_t tmr1 = 0;
uint32_t tmr2 = 0;
uint32_t tmr3 = 0;
uint32_t tmr4 = 0;
uint32_t tmr5 = 0;
uint32_t tmr6 = 0;
uint32_t tmr7 = 0;
float coef = 0.25;
// Define Arduino Pin Outputs to to the ULN2003 Darlington Array to drive a 28BYJ-48 Stepper Motor
#define IN1 A0
#define IN2 A1
#define IN3 A2
#define IN4 A3
#define HALFSTEPS 4096  // Number of half-steps for a full rotation
#define buzzer 8
// Initialize the TinyStepper Class
TinyStepper stepper(HALFSTEPS, IN1, IN2, IN3, IN4);

void setup()
{
  Serial.begin(38400);
  stepper.Enable();
  delay(1000);
  pinMode(buzzer, OUTPUT);
}
void yield(){
  

}
void loop() {
    if (millis() - tmr1 >= (1000*coef)) {  // ищем разницу
    tmr1 = millis();                   // сброс таймера
    stepper.Move(1.5);
    Serial.println(millis());
    
  }
  // Random back and forth
if(millis() - tmr2 >= (170000*coef)){
    tmr2 = millis();
    
    digitalWrite(buzzer, HIGH);

  }
  if(millis() - tmr4 >= (170500*coef)){
    tmr4 = millis();
    
    digitalWrite(buzzer, LOW);

  }
    if(millis() - tmr3 >= (171000*coef)){
    tmr3 = millis();
    
    digitalWrite(buzzer, HIGH);

  }
    if(millis() - tmr5 >= (171500*coef)){
    tmr5 = millis();
    
    digitalWrite(buzzer, LOW);

  }

    
  if(millis() - tmr6 >= (240000*coef)){
    tmr6 = millis();

    
    digitalWrite(buzzer, HIGH);
  } 
  if(millis() - tmr7 >= (3000*coef)){
    tmr7 = millis();
    digitalWrite(buzzer, LOW);
        tmr1 = 3000;
    tmr2 = 3000;
    tmr3 = 3000;
    tmr4 = 3000;
    tmr5 = 3000;
    }
  
}
