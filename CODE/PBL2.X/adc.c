#include "mcc_generated_files/system.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/rtcc.h"
#include "LCD_1.h"
#include "Teclado.h"
#include "lm35.h"
#include "dht22.h"
#include "mcc_generated_files/uart1.h"
#include "mcc_generated_files/adc1.h"
#include <stdio.h>

int i;
int key;
int pot,envia;

unsigned int adcRead_Teclado(void){
    ADC1_ChannelSelect(ADC1_TECLADO);
    ADC1_Start();
    for (i = 0; i < 10000; i++) {
    }
    ADC1_Stop();
    while (!ADC1_IsConversionComplete()) {
        ADC1_Tasks();
    }
    key = ADC1_ConversionResultGet();
}

unsigned int adcRead1(void){
    ADC1_ChannelSelect(ADC1_ANAOUT_1);
    ADC1_Start();
    for (i = 0; i < 10000; i++) {
    }
    ADC1_Stop();
    while (!ADC1_IsConversionComplete()) {
        ADC1_Tasks();
    }
    key = ADC1_ConversionResultGet();
}

unsigned int adcRead2(void){
    ADC1_ChannelSelect(ADC1_ANAOUT_2);
    ADC1_Start();
    for (i = 0; i < 10000; i++) {
    }
    ADC1_Stop();
    while (!ADC1_IsConversionComplete()) {
        ADC1_Tasks();
    }
    key = ADC1_ConversionResultGet();
}

unsigned int adcRead_Pot(void){
    ADC1_ChannelSelect(ADC1_ANAPOT);
    ADC1_Start();
    for (i = 0; i < 10000; i++) {
    }
    ADC1_Stop();
    while (!ADC1_IsConversionComplete()) {
        ADC1_Tasks();
    }
    pot = ADC1_ConversionResultGet();
    envia = pot/4;
   // send_string("P");
    printf("P");
    printf("%d\n",envia);
  //  printf("valor do potenciometro: %d\n", pot);
}