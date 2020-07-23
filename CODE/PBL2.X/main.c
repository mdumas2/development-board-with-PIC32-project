/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.125.1
        Device            :  PIC32MM0064GPM048
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.36B
        MPLAB 	          :  MPLAB X v5.20
 */

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
 */

/**
  Section: Included Files
 */
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/rtcc.h"
#include "mcc_generated_files/ext_int.h"
#include "mcc_generated_files/tmr1.h"
#include "mcc_generated_files/mccp1_compare.h"
#include "LCD_1.h"
#include "lm35.h"
#include "dht22.h"
#include "memoria_i2c.h"
#include "mcc_generated_files/uart1.h"
#include <stdio.h>

#include "adc.h"
#include "alarme.h"
#include "keypad.h"
#include "RecebeSerial.h"
#include "event.h"
#include "var.h"
#include "stateMachine.h"
#include "output.h"
#include "relogio.h"
#include "calendario.h"
#include "EnviaSerial.h"

#define BitSet(arg,bit) ((arg) |= (1<<bit))
#define BitClr(arg,bit) ((arg) &= ~(1<<bit)) 
#define BitFlp(arg,bit) ((arg) ^= (1<<bit)) 
#define BitTst(arg,bit) ((arg) & (1<<bit)) 

/*
                         Main application
 */
    void myTimer1ISR(void){
        Alarme1Tst();
        Alarme2Tst();
        TMR1_GetElapsedThenClear();
}
void main(void) {
    unsigned int t = 0;
    int valor_1M,valor_1m,valor_2M,valor_2m;
    int x;
    temp = 0;
    //init das bibliotecas
    SYSTEM_Initialize();
    TMR1_SetInterruptHandler(myTimer1ISR);
    eventInit();
    lcdInit();
    lcdClear();
    lcdInit();
    varInit();
    eventInit();
    outputInit();
    lcdInit();
    smInit();
    for (;;) {
        
         MCCP1_COMPARE_Start();
        // DelayMiliS(1000);
        //temperatura_LM35();
        //valor_1M = getV1M();
        //valor_1m = getV1m();
        //valor_2M = getV2M();
        //valor1_2m = getV2m();
        //printf("valor alarme alto 1: %d\r\n",valor_1M);
        //printf("valor alarme baixo 1: %d\r\n",valor_1m);
        //printf("valor alarme alto 2: %d\r\n",valor_2M);
        //printf("valor alarme baixo 2: %d\r\n",valor_2M);
               
        //  buzzer_SetHigh();
        //  DelayMiliS(100);
        //  buzzer_SetLow();
        // gas_sensor();
        //adcRead_Pot();
        // x = getV2M();
        //printf("%d\n", x);
        //  Envia_Valores_Serial();
        //Recebe_Valores_Serial();
        smLoop();
    }
}

/**
 End of File
 */


