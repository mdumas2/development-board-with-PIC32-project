#include "mcc_generated_files/system.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/rtcc.h"
#include "LCD_1.h"
#include "Teclado.h"
#include "lm35.h"
#include "dht22.h"
#include "mcc_generated_files/uart1.h"
#include <stdio.h>

struct tm currentTime;
struct tm initialTime;

void rtcPutSeconds(int segundos){
    if (segundos > 60){
        initialTime.tm_sec = 0;        //função que envia o valor de segundos para o rtc
        RTCC_TimeSet(&initialTime);   // primeiro verifica se o valor da variável é válida
    }                                // e se for envia o valor dado, se não envia 0,
    else if(segundos < 0){           // que foi definido como padrão
        initialTime.tm_sec = 0;
        RTCC_TimeSet(&initialTime);
    }
    else{
        initialTime.tm_sec = segundos;
        RTCC_TimeSet(&initialTime);
    }
}
// repete o algoritmo para os minutos e horas cada um com sua respectiva função
void rtcPutMinutes(int minutos){
    if (minutos > 60){
        initialTime.tm_min =  0;
        RTCC_TimeSet(&initialTime);
    }
    else if(minutos < 0){
        initialTime.tm_min = 0;
        RTCC_TimeSet(&initialTime);
    }
    else{
        initialTime.tm_min = minutos;
        RTCC_TimeSet(&initialTime);
    }
}

void rtcPutHour(int hora){
    if (hora > 24){
        initialTime.tm_hour = 0;
        RTCC_TimeSet(&initialTime);
    }
    else if(hora < 0){
        initialTime.tm_hour = 0;
        RTCC_TimeSet(&initialTime);
    }
    else{
        initialTime.tm_hour = hora;
        RTCC_TimeSet(&initialTime);
    }
}

int rtcGetSeconds(void){
    RTCC_TimeGet(&currentTime);  // função que retorna o valor de segundos atual do rtc
    return currentTime.tm_sec;
}

int rtcGetMinutes(void){
    RTCC_TimeGet(&currentTime);  // função que retorna o valor de minutos atual do rtc
    return currentTime.tm_min;
}

int rtcGetHours(void){
    RTCC_TimeGet(&currentTime);  // função que retorna o valor de horas atual do rtc
    return currentTime.tm_hour;
}