#include <Arduino_FreeRTOS.h>


void setup() {
Serial.begin(9600);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
xTaskCreate(task_a,"task_1", 128, NULL, 1, NULL);
xTaskCreate(task_b,"task_2", 128, NULL, 1, NULL);



}

//---------------------------------
void task_a()
{
  while(1)
  {

    digitalWrite(5, LOW);
    Serial.println("On");
    
    delay(3000);
    digitalWrite(5, HIGH);
    Serial.println("Off");
    delay(4000);
  }  
}



void task_b()
{
  while(1)
  {

    digitalWrite(6, HIGH);
    Serial.println("On");
    
    delay(3000);
    digitalWrite(6, LOW);
    Serial.println("Off");
    delay(4000);
  }
}

//---------------------
void loop() {
 
  }
