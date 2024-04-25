//taskA1
#include <Arduino_FreeRTOS.h>

void setup() {
Serial.begin(9600);
pinMode(5, OUTPUT);
xTaskCreate(task,"task", 128, NULL, 1, NULL); 

}


//-------------------------

void task()
{
  while(1)
  {

    digitalWrite(5, HIGH);
    Serial.println("On");
    

    delay(3000);
    digitalWrite(5, LOW);
    Serial.println("Off");
    delay(4000);
  }
}



//---------------------------------
void loop() {
 


  }


 
