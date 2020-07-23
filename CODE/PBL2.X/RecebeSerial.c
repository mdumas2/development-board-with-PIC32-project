#include "mcc_generated_files/system.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/rtcc.h"
#include "LCD_1.h"
#include "lm35.h"
#include "dht22.h"
#include "mcc_generated_files/uart1.h"
#include <stdio.h>
#include "adc.h"
#include "alarme.h"
#include "keypad.h"
#include "event.h"
#include "var.h"
#include "stateMachine.h"
#include "output.h"
#include "relogio.h"
#include "calendario.h"
#define MAX_LENGTH_UART 16

char data;
int data_2;
char readBuf[MAX_LENGTH_UART];

uint8_t UARTReadString(char *buf, uint8_t max_length) {
    uint8_t i = 0;
    char tmp = 1;
    for (i=0 ; i<max_length-1 ; i++) {
        tmp = UART1_Read();
        // para de ler quando a string estiver terminada
        if (tmp == '\0' || tmp == '\n' || tmp == '\r') {
            break;
        }
        buf[i] = tmp; 
    }
    
    buf[i] = '\0';
    
    return i;
}

void send_string(const char *x)
{ 
    while(*x)
    {
        UART1_Write(*x++);
    }
}

void Recebe_Valores_Serial(void){
    data = UART1_Read();
    UART1_Write(data);
    switch(data){
        case '1' : setState(STATE_IDLE);
                   break;
        case '2' : setState(STATE_DISPLAY);
                   break;
        case 'A' : UARTReadString(readBuf, MAX_LENGTH_UART);
                   data_2 = atoi(readBuf);
                   setV1M(data_2);
                   break;
        case 'B' : UARTReadString(readBuf, MAX_LENGTH_UART);
                   data_2 = atoi(readBuf);
                   setV1m(data_2);
                   break;
        case 'C' : UARTReadString(readBuf, MAX_LENGTH_UART);
                   data_2 = atoi(readBuf);
                   setV2M(data_2);
                   break;
        case 'D' : UARTReadString(readBuf, MAX_LENGTH_UART);
                   data_2 = atoi(readBuf);
                   setV2m(data_2);
                   break;
        case 'E' : UARTReadString(readBuf, MAX_LENGTH_UART);
                   data_2 = atoi(readBuf);
                   setT1(data_2);
                   break;
        case 'F' : UARTReadString(readBuf, MAX_LENGTH_UART);
                   data_2 = atoi(readBuf);
                   setT2(data_2);
                   break;
        case 'G' : if (getLanguage() == 0) { //WE DO THE VERIFICATION TO NOTHING GO WRONG IN THE LANGUAGE CHANGE
                    setLanguage(getLanguage());
                   } else {
                    setLanguage(getLanguage() + 1);
                   }
                   break;
        case 'H' : if (getLanguage() == 1) { //WE DO THE VERIFICATION TO NOTHING GO WRONG IN THE LANGUAGE CHANGE
                    setLanguage(getLanguage());
                   } else {
                    setLanguage(getLanguage() + 1);
                   }
                   break;
        case 'I' : UARTReadString(readBuf, MAX_LENGTH_UART);
                   data_2 = atoi(readBuf);
                   rtcPutDay(data_2);
                   break;
        case 'J' : UARTReadString(readBuf, MAX_LENGTH_UART);
                   data_2 = atoi(readBuf);
                   rtcPutMonth(data_2);
                   break;
        case 'K' : UARTReadString(readBuf, MAX_LENGTH_UART);
                   data_2 = atoi(readBuf);
                   data_2 = data_2 - 2000;
                   rtcPutYear(data_2);
                   break;
        case 'L' : UARTReadString(readBuf, MAX_LENGTH_UART);
                   data_2 = atoi(readBuf);
                   rtcPutHour(data_2);
                   break;
        case 'M' : UARTReadString(readBuf, MAX_LENGTH_UART);
                   data_2 = atoi(readBuf);
                   rtcPutMinutes(data_2);
                   break;
        case 'N' : UARTReadString(readBuf, MAX_LENGTH_UART);
                   data_2 = atoi(readBuf);
                   rtcPutSeconds(data_2);
                   break;
        //default : LED_1_SetHigh();
          //         break;
    }
}