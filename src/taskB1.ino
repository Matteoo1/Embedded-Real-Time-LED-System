//TaskB1

#include <Arduino_FreeRTOS.h>

  float f ;         //float_number to put strong of led
  int task;
  int pwm;          //to put Analog_n 0-255



void setup() {
Serial.begin(9600);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);

xTaskCreate(task_a,"task_1", 128, NULL, 2, NULL);
xTaskCreate(task_b,"task_2", 128, NULL, 2, NULL);
xTaskCreate(task_c,"task_3", 128, NULL, 1, NULL);

}

//---------------------------------
void task_a()
{
  while(1)
  {
    if (task == 1) {
      analogWrite(5, pwm);}
  
    
    vTaskDelay(pdMS_TO_TICKS(100));


  }
}



void task_b()
{
  while(1)
  {
    if (task == 2) {
      analogWrite(6, pwm);}
  
    
    vTaskDelay(pdMS_TO_TICKS(100));


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
    vTaskDelay(pdMS_TO_TICKS(100));

    
  }
}
//---------------------------------
void loop() {
 

  }
