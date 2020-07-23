#include "mcc_generated_files/system.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/rtcc.h"
#include "LCD_1.h"
#include "memoria_i2c.h"
#include "Teclado.h"
#include "lm35.h"
#include "dht22.h"
#include "mcc_generated_files/uart1.h"
#include "calendario.h"
#include <stdio.h>

struct tm currentTime;
struct tm initialTime;

void rtcPutDay(int dia){
    if (dia < 0){
      initialTime.tm_mday = 0;
      RTCC_TimeSet(&initialTime);  
    }
    else if(dia > 31){
      initialTime.tm_mday = 1;
      RTCC_TimeSet(&initialTime);  
    }
    else if (dia <= 28){                 //função que seta o valor do dia no rtc
        initialTime.tm_mday = dia;   //primeiramente analisa se o valor enviado é valido
        RTCC_TimeSet(&initialTime); // se não for coloca como padrão 0 na variável 
    }                               // se for válida, envia o valor dado 
    else if((dia > 28) && (rtcGetMonth() == 2)){
        if (((rtcGetYear() % 4)== 0)){
            if(rtcGetYear() == 00){
            initialTime.tm_mday = 28;
            RTCC_TimeSet(&initialTime);
            }
            else {
            initialTime.tm_mday = 29;
            RTCC_TimeSet(&initialTime);  
            }
        }
        else{
        initialTime.tm_mday = 28;
        RTCC_TimeSet(&initialTime);
        }
    }
    else if((dia > 28) && ((rtcGetMonth() == 1) || (rtcGetMonth() == 12) || (rtcGetMonth() == 10) || (rtcGetMonth() == 8) || (rtcGetMonth() == 7) || (rtcGetMonth() == 5) || (rtcGetMonth() == 3))){
        initialTime.tm_mday = dia; 
        RTCC_TimeSet(&initialTime);
    }
    else  if((dia > 30) && ((rtcGetMonth() == 11) || (rtcGetMonth() == 9) || (rtcGetMonth() == 6) || (rtcGetMonth() == 4))){
        initialTime.tm_mday = 30; 
        RTCC_TimeSet(&initialTime);
    }
    else  {
        initialTime.tm_mday = dia; 
        RTCC_TimeSet(&initialTime);
    }
 }

// realiza o mesmo processo para o mês e para o ano
void rtcPutMonth(int mes){
    if (mes < 1){
        initialTime.tm_mon = 1;
        RTCC_TimeSet(&initialTime);
    }
    else if ((rtcGetDay() > 28) && (mes == 2)){
        if (((rtcGetYear() % 4)== 0)){
            if(rtcGetYear() == 0){
            initialTime.tm_mday = 28; 
            initialTime.tm_mon = mes;
            RTCC_TimeSet(&initialTime);
            }
            else{
            initialTime.tm_mday = 29; 
            initialTime.tm_mon = mes;
            RTCC_TimeSet(&initialTime);
            }
        }
        else{
        initialTime.tm_mday = 28; 
        initialTime.tm_mon = mes;
        RTCC_TimeSet(&initialTime);    
        }
    }
    else if (((rtcGetDay()) > 30)&&((mes == 11))){
        initialTime.tm_mday = 30; 
        initialTime.tm_mon = mes;
        RTCC_TimeSet(&initialTime);
    }
    else if (((rtcGetDay()) > 30)&&((mes == 9))){
        initialTime.tm_mday = 30; 
        initialTime.tm_mon = mes;
        RTCC_TimeSet(&initialTime);
    }
    else if (((rtcGetDay()) > 30)&&((mes == 6))){
        initialTime.tm_mday = 30; 
        initialTime.tm_mon = mes;
        RTCC_TimeSet(&initialTime);
    }
    else if (((rtcGetDay()) > 30)&&((mes == 4))){
        initialTime.tm_mday = 30; 
        initialTime.tm_mon = mes;
        RTCC_TimeSet(&initialTime);
    }
    else if (mes > 12){
        initialTime.tm_mon = 1;
        RTCC_TimeSet(&initialTime);
    }
    else {
        initialTime.tm_mon = mes;
        RTCC_TimeSet(&initialTime);
    }
}

void rtcPutYear(int ano){
    if (ano > 99){
        initialTime.tm_year = 0;
        RTCC_TimeSet(&initialTime);
    }
    else if(ano < 0){
        initialTime.tm_year = 0;
        RTCC_TimeSet(&initialTime);
    }
    else{
        initialTime.tm_year = ano;
        memWrite(0x0012,initialTime.tm_year);
        RTCC_TimeSet(&initialTime);
    }
}

int rtcGetDay(void){
 //   currentTime.tm_mday = memRead(0x0010);
    RTCC_TimeGet(&currentTime); 
    if (currentTime.tm_mday < 1){
        currentTime.tm_mday = 1;
    }
  //  memWrite(0x0010,currentTime.tm_mday);               //função que retorna o valor do dia apontado pelo rtc
    return currentTime.tm_mday;
}

int rtcGetMonth(void){
 //   currentTime.tm_mon = memRead(0x0011);
    RTCC_TimeGet(&currentTime);    //função que retorna o valor do mês apontado pelo rtc
 //   memWrite(0x0011,currentTime.tm_mon);
    if (currentTime.tm_mon < 1){
        currentTime.tm_mon = 1;
    }
    return currentTime.tm_mon;
}

int rtcGetYear(void){
 //   currentTime.tm_year = memRead(0x0012);
    RTCC_TimeGet(&currentTime);    //função que retorna o valor do ano apontado pelo rtc
 //   memWrite(0x0012,currentTime.tm_year);
    return currentTime.tm_year;
}
