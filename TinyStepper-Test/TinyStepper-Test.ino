/*
  TinyStepper - Stepper Motor Test
 comment for version abc
  by Jason A. Cox - @jasonacox
comment branch 1
  Date: 19 July 2020

*/

#include <TinyStepper.h>
uint32_t tmr1 = 0;
uint32_t tmr2 = 0;
boolean flag1 = 0;
boolean flag2 = 0;
boolean flag3 = 0;
boolean flag4 = 0;
boolean flag5 = 0;
boolean flag6 = 0;
float coef = 1;
uint32_t tmp = 0;
// Define Arduino Pin Outputs to to the ULN2003 Darlington Array to drive a 28BYJ-48 Stepper Motor
#define IN1 A3
#define IN2 A2
#define IN3 A1
#define IN4 A0
#define red 10
#define yellow 11
#define green 12
#define HALFSTEPS 4096  // Number of half-steps for a full rotation
#define buzzer 8
#define zero_sensor 13
// Initialize the TinyStepper Class
TinyStepper stepper(HALFSTEPS, IN1, IN2, IN3, IN4);

void setup()
{
  Serial.begin(9600);
  stepper.Enable();
  delay(1000);
  pinMode(buzzer, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(zero_sensor, INPUT);
  
  while(digitalRead(zero_sensor) != 0){
    stepper.Move(3);    
    delay(100);
  }

  digitalWrite(green, 1);
}
void yield(){
  

}
void loop() {  
  if(tmp == 0){
    
    digitalWrite(buzzer, HIGH);
    Serial.println("HIGH");
      
    }
    if (millis() - tmr1 >= (2000*coef)) {  // ищем разницу
    tmr1 = millis();                   // сброс таймера
    stepper.Move(3);
    Serial.println(millis());
    
  }
  if (millis() - tmr2 >= (500*coef)) {  // ищем разницу
    tmr2 = millis();                   // сброс таймера

    tmp++;
    
  }

  // Random back and forth
if(tmp ==340){
    
    
    digitalWrite(buzzer, HIGH);
    Serial.println("HIGH");
digitalWrite(green, 0);
digitalWrite(yellow, 1);
  }
  if(tmp == 341){
    
    
    digitalWrite(buzzer, LOW);
    Serial.println("LOW");

  }

  if(tmp == 360){
    

    
    digitalWrite(buzzer, HIGH);
    Serial.println("HIGH");
    digitalWrite(yellow, 0);
digitalWrite(red, 1);
  } 
  if(tmp == 366){
    
    digitalWrite(buzzer, LOW);
    Serial.println("LOW");
      
    }    
  if(tmp == 480){
    digitalWrite(buzzer, HIGH);
    Serial.println("HIGH");
        digitalWrite(red, 0);
digitalWrite(green, 1);

    tmp = 0;
  }    
   
  if(tmp == 6){
    
    digitalWrite(buzzer, LOW);
    Serial.println("LOW");
      
    }
   
  
}
