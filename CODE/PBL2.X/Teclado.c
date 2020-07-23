#include "mcc_generated_files/system.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/clock.h"
#include "LCD_1.h"
#include "Teclado.h"
#include "mcc_generated_files/adc1.h"
#include "dht22.h"

static unsigned int key_ant;
static unsigned int valor;
int key;
int ev;
int i;

void eventInit(void) {
    key_ant = 0;
    ev = EV_NOEVENT;
    valor = 0;
    key = 0;
}

unsigned int eventRead(void) {

    ADC1_ChannelSelect(ADC1_TECLADO);
    ADC1_Start();
    for (i = 0; i < 10000; i++) {
    }
    ADC1_Stop();
    while (!ADC1_IsConversionComplete()) {
        ADC1_Tasks();
    }
    key = ADC1_ConversionResultGet();

    if (key != key_ant) {
        if (key > 185 && key < 225) {
            ev = EV_B5;  //-
        }

        if (key > 234 && key < 274) {
            ev = EV_B2;  //back
        }

        if (key > 321 && key < 361) {
            ev = EV_B3;  //next
        }
        if (key > 492 && key < 532) {
            ev = EV_B4;  //+
        }
        if (key > 1003 && key < 1024) {
            ev = EV_B1; //enter
        }
    }
    key_ant = key;
    return ev;
}

unsigned int kpRead(void) {
    return valor;
}

void kpDebounce(void) {
    static unsigned int tempo;
    static unsigned int valorNovo = 0x0000;
    static unsigned int valorAntigo = 0x0000;
    valorNovo = eventRead();
    if (valorAntigo == valorNovo) {
        tempo--;
    } else {
        tempo = 10;
        valorAntigo = valorNovo;
    }
    if (tempo == 0) {
        valor = valorAntigo;
    }
}
