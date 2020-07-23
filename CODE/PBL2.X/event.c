#include "mcc_generated_files/system.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/clock.h"
#include "LCD_1.h"
#include "event.h"
#include "adc.h"
#include "keypad.h"
#include "mcc_generated_files/adc1.h"

static unsigned int key_ant;
int key;
int ev;

void eventInit(void) {
    key_ant = 0;
    key = 0;
    ev = 0;
}

unsigned int eventRead(void) {
    ev = EV_NOEVENT;
    
    key = adcRead_Teclado();

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
        if (key > 1003 && key < 1024){
            ev = EV_B1; //enter
        }
    }
    key_ant = key;
    return ev;
}
