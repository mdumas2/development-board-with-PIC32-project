#include "mcc_generated_files/system.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/clock.h"
#include "LCD_1.h"
#include "event.h"
#include "keypad.h"
#include "mcc_generated_files/adc1.h"

static unsigned int valor=0;

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
        tempo = 3;
        valorAntigo = valorNovo;
    }
    if (tempo == 0) {
        valor = valorAntigo;
    }
}

