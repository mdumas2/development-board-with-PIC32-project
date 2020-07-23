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

void Envia_Valores_Serial(void){
    int valor_max_1,valor_max_2,valor_min_1,valor_min_2;
    int alarme_1,alarme_2,dia,mes,ano,hora,minuto,segundo,linguagem;
    valor_max_1 = getV1M();
    printf("1");
    printf("%d\n",valor_max_1);
    
    valor_max_2 = getV2M();
    printf("2");
    printf("%d\n",valor_max_2);
    
    valor_min_1 = getV1m();
    printf("3");
    printf("%d\n",valor_min_1);
    
    valor_min_2 = getV2m();
    printf("4");
    printf("%d\n",valor_min_2);
    
    alarme_1 = getT1();
    printf("5");
    printf("%d\n",alarme_1);
    
    alarme_2 = getT2();
    printf("6");
    printf("%d\n",alarme_2);
    
    dia = rtcGetDay();
    printf("7");
    printf("%d\n",dia);
    
    mes = rtcGetMonth();
    printf("8");
    printf("%d\n",mes);
    
    ano = rtcGetYear();
    printf("9");
    printf("%d\n",ano);
    
    hora = rtcGetHours();
    printf("A");
    printf("%d\n",hora);
    
    minuto = rtcGetMinutes();
    printf("B");
    printf("%d\n",minuto);
    
    segundo = rtcGetSeconds();
    printf("C");
    printf("%d\n",segundo);
    
    linguagem = getLanguage();
    if(linguagem == 0){
        printf("D");
        printf("portugues");
    }
    else{
        printf("E");
        printf("english");
    }
}
