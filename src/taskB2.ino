//TaskB2

#include <Arduino_FreeRTOS.h>
#include "queue.h"

  float f ;         //float_number to put strong of led
  int task;
  int pwm;          //to put Analog_n 0-255

  QueueHandle_t firstQ = NULL;
  QueueHandle_t secondQ = NULL;


void setup() {
Serial.begin(9600);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);

xTaskCreate(task_a,"task_1", 128, NULL, 2, NULL);
xTaskCreate(task_b,"task_2", 128, NULL, 2, NULL);
xTaskCreate(task_c,"task_3", 128, NULL, 1, NULL);


firstQ = xQueueCreate (5, 4);   //the Q is 5 values , 4 is the size of integer number, Q1
secondQ = xQueueCreate (5, 4);  // Q2



}

//---------------------------------
void task_a()
{
  while(1)
  
  {
   xQueueReceive(firstQ, &pwm, 100);     //take the last value from Q to use the number (pwm) to turn on the LED
   analogWrite(5, pwm);                  // tern on Led 5 useing pwm
   vTaskDelay(pdMS_TO_TICKS(5000));      // delay 5 sec, thes function let to another task to run while this task is sleeping


  }
}



void task_b()
{
  while(1)
  {
    xQueueReceive(secondQ, &pwm, 100);     //take the last value from Q to use the number (pwm) to turn on the LED
   analogWrite(6, pwm);                  // tern on Led 6 useing pwm
   vTaskDelay(pdMS_TO_TICKS(5000));      // delay 5 sec, thes function let to another task to run while this task is sleeping

  }
}



void task_c()
{



  while(1)
  {
    f = Serial.parseFloat();            // to read the floating nuber 
    task = (int)f;                    //to read the integer nuber from the floating number,1.3 _here the int is 1
    f = f-task;                       // 1.3 -1=0.3 the strong of LED
    f = f*=255  ;                      // to multiply the 0.3 floating number with 255(the highest analong nubmber)
    pwm =(int) f;
    if (task == 1) {
      xQueueSend(firstQ, &pwm, 0);     // take the numbers and stor thirs pwm in first Q , 0 no waiting and if Q is full throw away the value                      
    }

    else if (task == 2){
      xQueueSend(secondQ, &pwm, 0);

    }
  }
}
//---------------------------------
void loop() {
 

  }
