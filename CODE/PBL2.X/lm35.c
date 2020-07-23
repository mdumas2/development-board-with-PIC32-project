#include "mcc_generated_files/system.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/uart1.h"
#include "LCD_1.h"
#include "mcc_generated_files/adc1.h"
#include "adc.h"
#include <stdio.h>
#include <math.h>
#include "var.h"
#define conversion (3.3 * 100)/1024

void temperatura_LM35(void){
    int digital_result;
    digital_result = adcRead1();
    temp = digital_result * conversion;
  //  send_string("T");
  //  printf("%f",temp);
   //  printf("Temperatura : %2.2f \r", temp);
    printf("T");
    printf("%0.2f\n",temp);
}

void gas_sensor(void){
    int gas;
    gas = adcRead2();
    gas = gas/4;
    printf("G");
    printf("%d\n",gas);
}

void temperatura_LM35_display(void){
     char *temperatura;
    // sprintf(temperatura, "temp = %2.4", temp);
   //  send_string(temperatura);
  //   LCD_Set_Cursor(1,1);
   //  lcdString(temperatura);
}
