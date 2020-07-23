/*------------------------------------------------------------------------------------------------ */
/*                                             STATE MACHINE INCLUDES                              */

#include "alarme.h"
#include "var.h"
#include "stateMachine.h"
#include "event.h"
#include "memoria_i2c.h"
#include "output.h"
#include "LCD_1.h"
#include "keypad.h"
#include "stdio.h"
#include "relogio.h"
#include "calendario.h"
#include "mcc_generated_files/uart1.h"
#include "mcc_generated_files/pin_manager.h"

int valor_alto_2;
/*------------------------------------------------------------------------------------------------ */
/*STATE MACHINE INIT                                                                               */

/*SET CURSOR IN THE FIRST POSITION OF THE LCD, SET MENUDISPLAY AS THE FIRST DISPLAY IN THE LCD     */

void smInit(void) {
    valor_alto_2 = 0;
    setState(STATE_MENUDISPLAY);
    setCursor(1);
}

/*------------------------------------------------------------------------------------------------ */

/*STATE MACHINE LOOP                                                                               */
void smLoop(void) {

    unsigned char evento;
    evento = eventRead(); //READ THE kpReadEY
    switch (getState()) { //READ THE STATE

            /*------------------------------------------------------------------------------------------------ */

        case STATE_MENUDISPLAY: //CASE STATE MENU DISPLAY
            if (evento == EV_B1) { //IF WE PRESS THE KEY B1(ENTER) IN THE MENU DISPLAY WE ENTER IN THE DISPLAY MENU
                setState(STATE_DISPLAY); //SET THE PRESENT STATE AS THE DISPLAY STATE
            }
            if (evento == EV_B3) { //IF WE PRESS THE KEY B3(NEXT) IN THE MENU DISPLAY WE CHANGE TO THE LANGUAGE MENU
                setState(STATE_MENULINGUAGEM); //SET THE PRESENT STATE AS THE LANGUAGE MENU STATE
            }
            break; //BREAK OF THE STATE MENU DISPLAY

            /*------------------------------------------------------------------------------------------------ */

        case STATE_DISPLAY: //CASE STATE DISPLAY
            if (evento == EV_B2) { //IF WE PRESS THE KEY B2(BACK) IN THE DISPLAY STATE WE RETURN TO THE DISPLAY MENU
                setState(STATE_MENUDISPLAY); //SET THE PRESENT STATE AS THE MENU DISPLAY
            }
            break; //BREAK OF THE STATE DISPLAY

            /*------------------------------------------------------------------------------------------------ */

        case STATE_MENULINGUAGEM: //CASE STATE LANGUAGE MENU
            if (evento == EV_B1) { //IF WE PRESS B1(ENTER) IN THE LANGUAGE MENU STATE WE ENTER IN THE LANGUAGE OPTIONS
                setState(STATE_IDIOMAPT); //SET THE PRESENT STATE AS THE PORTUGUESE LANGUAGE
            }
            if (evento == EV_B3) { //IF WE PRESS B3(NEXT) IN THE LANGUAGE MENU STATE WE CHANGE TO THE VALUE CONFIGURATION MENU
                setState(STATE_MENUCONFIGVALORES); //SET THE PRESENT STATE AS THE VALUE CONFIGURATION MENU
            }
            break; //BREAK OF THE STATE LANGUAGE MENU

            /*------------------------------------------------------------------------------------------------ */

        case STATE_IDIOMAPT: //CASE STATE PORTUGUESE LANGUAGE
            if (evento == EV_B3) { //IF WE PRESS B3(NEXT) IN THE PORTUGUESE LANGUAGE STATE WE CHANGE TO THE ENGLISH LANGUAGE STATE 
                setState(STATE_IDIOMAEN); //SET THE PRESENT STATE AS THE ENGLISH LANGUAGE STATE
            }
            if (evento == EV_B2) { //IF WE PRESS B2(BACK) IN THE PORTUGUESE LANGUAGE STATE WE GO BACK TO THE LANGUAGE MENU
                setState(STATE_MENULINGUAGEM); //SET THE PRESENT STATE AS THE LANGUAGE MENU STATE
            }
            if (evento == EV_B1) { //IF WE PRESS B1(ENTER) IN THE PORTUGUESE LANGUAGE STATE WE CHANGE THE WHOLE SYSTEM LANGUAGE TO PORTUGUESE
                if (getLanguage() == 0) { //WE DO THE VERIFICATION TO NOTHING GO WRONG IN THE LANGUAGE CHANGE
                    setLanguage(getLanguage());
                } else {
                    setLanguage(getLanguage() + 1);
                }
                setState(STATE_MENULINGUAGEM); //SET THE PRESENT STATE AS THE LANGUAGE MENU
            }
            break; //BREAK OF THE PORTUGUESE LANGUAGE STATE

            /*------------------------------------------------------------------------------------------------ */

        case STATE_IDIOMAEN: //CASE STATE ENGLISH LANGUAGE                            
            if (evento == EV_B3) { //IF WE PRESS B3(NEXT) IN THE ENGLISH LANGUAGE STATE WE CHANGE TO THE PORTUGUESE LANGUAGE STATE
                setState(STATE_IDIOMAPT); //SET THE PRESENT STATE AS THE PORTUGUESE LANGUAGE STATE
            }
            if (evento == EV_B2) { //IF WE PRESS B2(BACK) IN THE ENGLISH LANGUAGE STATE WE GO BACK TO THE LANGUAGE MENU
                setState(STATE_MENULINGUAGEM);
            }
            if (evento == EV_B1) { //IF WE PRESS B1(ENTER) IN THE ENGLISH LANGUAGE STATE WE CHANGE THE WHOLE SYSTEM LANGUAGE TO ENGLISH
                if (getLanguage() == 1) { //WE DO THE VERIFICATION TO NOTHING GO WRONG IN THE LANGUAGE CHANGE
                    setLanguage(getLanguage());
                } else {
                    setLanguage(getLanguage() + 1);
                }
                setState(STATE_MENULINGUAGEM); //SET THE PRESENT STATE AS THE LANGUAGE MENU
            }
            break; //BREAK OF THE ENGLISH LANGUAGE STATE

            /*------------------------------------------------------------------------------------------------ */

        case STATE_MENUCONFIGVALORES:
            if (evento == EV_B1) { //B1 enter
                setState(STATE_CONFIGSENSOR1);
            }
            if (evento == EV_B3) { //B3 next
                setState(STATE_MENUDISPLAYDATAHORA);
            }
            break;

        case STATE_CONFIGSENSOR1:
            if (evento == EV_B1) { //B1 enter
                setState(STATE_VALOR1M);
            }
            if (evento == EV_B3) { //B3 next
                setState(STATE_CONFIGSENSOR2);
            }
            if (evento == EV_B2) { //B2 back
                setState(STATE_MENUCONFIGVALORES);
            }
            break;

        case STATE_VALOR1M: //Altera o Alarme 1 Alto

            if (evento == EV_B3) { //B3 next, nesse caso muda a posição do cursor
                setCursor(getCursor() + 1);
                if (getCursor() > 3) {
                    setCursor(1);
                }
            }
            if ((getCursor() == 1) && (evento == EV_B4)) { //B4 +, se o cursor esta na 1ª posição e B4 
                setV1M((getV1M()) + 100); //é selecionado soma-se +100 do 
                if (getV1M() > 999) { //Alarme 1 alto
                    setV1M(getV1M() - 1000);
                }
            }
            if ((getCursor() == 1) && (evento == EV_B5)) { //B5 -, se o cursor esta na 1ª posição e B5
                setV1M((getV1M()) - 100); // é selecionado subtrai-se -100 do
                if (getV1M() < 000) { //Alarme 1 alto
                    setV1M(getV1M() + 1000);
                }
            }
            if ((getCursor() == 2) && (evento == EV_B4)) { //B4 +, se o cursor esta na 2ª posição e B4 
                setV1M((getV1M()) + 10); //é selecionado soma-se +10 do 
                if ((getV1M() % 100) > 99) { //Alarme 1 alto
                    setV1M(getV1M() - 100);
                }
            }
            if ((getCursor() == 2) && (evento == EV_B5)) { //B5 -, se o cursor esta na 2ª posição e B5
                setV1M((getV1M()) - 10); // é selecionado subtrai-se -10 do
                if (getV1M() < 00) { //Alarme 1 alto
                    setV1M(getV1M() + 100);
                }
            }
            if ((getCursor() == 3) && (evento == EV_B4)) { //B4 +, se o cursor esta na 3ª posição e B4 
                setV1M(getV1M() + 1); //é selecionado soma-se +1 do 
                if ((getV1M() % 10) > 9) { //Alarme 1 alto
                    setV1M(getV1M() - 10);
                }
            }
            if ((getCursor() == 3) && (evento == EV_B5)) { //B5 -, se o cursor esta na 3ª posição e B5
                setV1M((getV1M()) - 1); //é selecionado soma-se -1 do 
                if (getV1M() < 0) { //Alarme 1 alto
                    setV1M(getV1M() + 10);
                }
            }
            if (evento == EV_B1) { //B1 enter
                setState(STATE_VALOR1m);
            }
            if (evento == EV_B2) { //B2 back
                setState(STATE_CONFIGSENSOR1);
            }
            break;

        case STATE_VALOR1m: //Altera o Alarme 1 baixo
            if (evento == EV_B3) { //B3 next, nesse caso muda a posição do cursor
                setCursor(getCursor() + 1);
                if (getCursor() > 3) {
                    setCursor(1);
                }
            }
            if ((getCursor() == 1) && (evento == EV_B4)) { //B4 + e cursor 1ª posição
                setV1m((getV1m()) + 100); // +100 em Alarme 1 baixo
                if (getV1m() > 999) {
                    setV1m(getV1m() - 1000);
                }
            }
            if ((getCursor() == 1) && (evento == EV_B5)) { //B5 - e cursor 1ª posição
                setV1m((getV1m()) - 100); // -100 em Alarme 1 baixo
                if (getV1m() < 000) {
                    setV1m(getV1m() + 1000);
                }
            }
            if ((getCursor() == 2) && (evento == EV_B4)) { //B4 + e cursor 2ª posição
                setV1m((getV1m()) + 10); // +10 em Alarme 1 baixo 
                if ((getV1m() % 100) > 99) {
                    setV1m(getV1m() - 100);
                }
            }
            if ((getCursor() == 2) && (evento == EV_B5)) { //B5 - e cursor 2ª posição
                setV1m((getV1m()) - 10); // -10 em Alarme 1 baixo
                if (getV1m() < 00) {
                    setV1m(getV1m() + 100);
                }
            }
            if ((getCursor() == 3) && (evento == EV_B4)) { //B4 + e cursor 3ª posição
                setV1m(getV1m() + 1); // +1 em Alarme 1 baixo 
                if ((getV1m() % 10) > 9) {
                    setV1m(getV1m() - 10);
                }
            }
            if ((getCursor() == 3) && (evento == EV_B5)) { //B5 - e cursor 3ª posição
                setV1m((getV1m()) - 1); // -1 em Alarme 1 baixo 
                if (getV1m() < 0) {
                    setV1m(getV1m() + 10);
                }
            }
            if (evento == EV_B1) { //B1 enter
                if (getV1M() < getV1m()) { //Verifica se Alarme 1 baixo é maior que
                    setV1M(900); //Alarme 1 Alto caso seja seta os dois para 
                    setV1m(000); //valores padrões 
                    setState(STATE_ERROV1); //e mostra uma mensagem na tela
                } else { //caso os valores estejam corretos mostramos uma 
                    setState(STATE_ACERTOV1); //mensagem de valor válido
                }
            }
            if (evento == EV_B2) { //B2 back
                setState(STATE_CONFIGSENSOR1);
            }
            break;

        case STATE_CONFIGSENSOR2: //mesmo codigo usado para configurar o Alarme1 alto e baixo
            if (evento == EV_B1) {
                setState(STATE_VALOR2M);
            }
            if (evento == EV_B3) {
                setState(STATE_CONFIGTEMPO1);
            }
            if (evento == EV_B2) {
                setState(STATE_MENUCONFIGVALORES);
            }
            break;

        case STATE_VALOR2M:
            if (evento == EV_B3) {
                setCursor(getCursor() + 1);
                if (getCursor() > 3) {
                    setCursor(1);
                }
            }
            if ((getCursor() == 1) && (evento == EV_B4)) {
                setV2M((getV2M()) + 100);
                if (getV2M() > 999) {
                    valor_alto_2 = (000);
                    setV2M(valor_alto_2);
                }
                else {
                    valor_alto_2 = (getV2M());
                    setV2M(valor_alto_2);
                }
                
            }
            if ((getCursor() == 1) && (evento == EV_B5)) {
                if (getV2M() > 100) {
                    setV2M((getV2M()) - 100);
                }
                else if (getV2M() <= 100){
                    valor_alto_2 = (000);
                    setV2M(valor_alto_2);
                }
            }
            if ((getCursor() == 2) && (evento == EV_B4)) {
                setV2M((getV2M()) + 10);
                if ((getV2M() % 100) > 99) {
                    valor_alto_2=(getV2M() - 100);
                    setV2M(valor_alto_2);
                }
            }
            if ((getCursor() == 2) && (evento == EV_B5)) {
                setV2M((getV2M()) - 10);
                if (getV2M() < 00) {
                    valor_alto_2=(getV2M() + 100);
                    setV2M(valor_alto_2);
                }
            }
            if ((getCursor() == 3) && (evento == EV_B4)) {
                setV2M(getV2M() + 1);
                if ((getV2M() % 10) > 9) {
                    valor_alto_2=(getV2M() - 10);
                    setV2M(valor_alto_2);
                }
            }
            if ((getCursor() == 3) && (evento == EV_B5)) {
                setV2M((getV2M()) - 1);
                if (getV2M() < 0) {
                    valor_alto_2=(getV2M() + 10);
                    setV2M(valor_alto_2);
                }
            }
            if (evento == EV_B1) {
                setState(STATE_VALOR2m);
            }
            if (evento == EV_B2) {
                setState(STATE_CONFIGSENSOR2);
            }
            break;

        case STATE_VALOR2m:
            if (evento == EV_B3) {
                setCursor(getCursor() + 1);
                if (getCursor() > 3) {
                    setCursor(1);
                }
            }
            if ((getCursor() == 1) && (evento == EV_B4)) { //b4+ b5-
                setV2m((getV2m()) + 100);
                if (getV2m() > 999) {
                    setV2m(getV2m() - 1000);
                }
            }
            if ((getCursor() == 1) && (evento == EV_B5)) {
                setV2m((getV2m()) - 100);
                if (getV2m() < 000) {
                    setV2m(getV2m() + 1000);
                }
            }
            if ((getCursor() == 2) && (evento == EV_B4)) {
                setV2m((getV2m()) + 10);
                if ((getV2m() % 100) > 99) {
                    setV2m(getV2m() - 100);
                }
            }
            if ((getCursor() == 2) && (evento == EV_B5)) {
                setV2m((getV2m()) - 10);
                if (getV2m() < 00) {
                    setV2m(getV2m() + 100);
                }
            }
            if ((getCursor() == 3) && (evento == EV_B4)) {
                setV2m(getV2m() + 1);
                if ((getV2m() % 10) > 9) {
                    setV2m(getV2m() - 10);
                }
            }
            if ((getCursor() == 3) && (evento == EV_B5)) {
                setV2m((getV2m()) - 1);
                if (getV2m() < 0) {
                    setV2m(getV2m() + 10);
                }
            }
            if (evento == EV_B1) {
                if (getV2M() < getV2m()) {
                    setV2M(900);
                    setV2m(000);
                    setState(STATE_ERROV2);
                } else {
                    setState(STATE_ACERTOV2);
                }
            }
            if (evento == EV_B2) {
                setState(STATE_CONFIGSENSOR2);
            }
            break;

        case STATE_CONFIGTEMPO1:

            if (evento == EV_B1) {
                setState(STATE_VALORT1);
            }
            if (evento == EV_B3) {
                setState(STATE_CONFIGTEMPO2);
            }
            if (evento == EV_B2) {
                setState(STATE_MENUCONFIGVALORES);
            }
            break;

        case STATE_VALORT1:

            if (evento == EV_B3) {
                setCursor(getCursor() + 1);
                if (getCursor() > 3) {
                    setCursor(1);
                }
            }

            if ((getCursor() == 1) && (evento == EV_B4)) { //b4+ b5-
                setT1((getT1()) + 100);
                if (getT1() > 999) {
                    setT1(getT1() - 1000);
                }
            }
            if ((getCursor() == 1) && (evento == EV_B5)) {
                setT1((getT1()) - 100);
                if (getT1() < 000) {
                    setT1(getT1() + 1000);
                }
            }
            if ((getCursor() == 2) && (evento == EV_B4)) {
                setT1((getT1()) + 10);
                if ((getT1() % 100) > 99) {
                    setT1(getT1() - 100);
                }
            }
            if ((getCursor() == 2) && (evento == EV_B5)) {
                setT1((getT1()) - 10);
                if (getT1() < 00) {
                    setT1(getT1() + 100);
                }
            }
            if ((getCursor() == 3) && (evento == EV_B4)) {
                setT1(getT1() + 1);
                if ((getT1() % 10) > 9) {
                    setT1(getT1() - 10);
                }
            }
            if ((getCursor() == 3) && (evento == EV_B5)) {
                setT1((getT1()) - 1);
                if (getT1() < 0) {
                    setT1(getT1() + 10);
                }
            }
            if (evento == EV_B1) {
                setState(STATE_CONFIGTEMPO1);
            }
            if (evento == EV_B2) {
                setState(STATE_CONFIGTEMPO1);
            }
            break;

        case STATE_CONFIGTEMPO2:
            if (evento == EV_B1) {
                setState(STATE_VALORT2);
            }
            if (evento == EV_B3) {
                setState(STATE_CONFIGSENSOR1);
            }
            if (evento == EV_B2) {
                setState(STATE_MENUCONFIGVALORES);
            }
            break;

        case STATE_VALORT2:
            if (evento == EV_B3) {
                setCursor(getCursor() + 1);
                if (getCursor() > 3) {
                    setCursor(1);
                }
            }
            if ((getCursor() == 1) && (evento == EV_B4)) { //b4+ b5-
                setT2((getT2()) + 100);
                if (getT2() > 999) {
                    setT2(getT2() - 1000);
                }
            }
            if ((getCursor() == 1) && (evento == EV_B5)) {
                setT2((getT2()) - 100);
                if (getT2() < 000) {
                    setT2(getT2() + 1000);
                }
            }
            if ((getCursor() == 2) && (evento == EV_B4)) {
                setT2((getT2()) + 10);
                if ((getT2() % 100) > 99) {
                    setT2(getT2() - 100);
                }
            }
            if ((getCursor() == 2) && (evento == EV_B5)) {
                setT2((getT2()) - 10);
                if (getT2() < 00) {
                    setT2(getT2() + 100);
                }
            }
            if ((getCursor() == 3) && (evento == EV_B4)) {
                setT2(getT2() + 1);
                if ((getT2() % 10) > 9) {
                    setT2(getT2() - 10);
                }
            }
            if ((getCursor() == 3) && (evento == EV_B5)) {
                setT2((getT2()) - 1);
                if (getT2() < 0) {
                    setT2(getT2() + 10);
                }
            }
            if (evento == EV_B1) {
                setState(STATE_CONFIGTEMPO2);
            }
            if (evento == EV_B2) {
                setState(STATE_CONFIGTEMPO2);
            }
            break;

        case STATE_1ATIVO: //Alarme 1 ativo
            if (evento == EV_B1) { //B1 enter
                setState(STATE_DISPLAY);
            }
            break;

        case STATE_2ATIVO: //Alarme 2 ativo
            if (evento == EV_B1) { //B1 enter
                setState(STATE_DISPLAY);
            }
            break;

        case STATE_ERROV1: //Erro quando o Alarme alto 1 é menor que o Alarme baixo 1
            if (evento == EV_B1) { //B1 enter
                setState(STATE_VALOR1M);
            }
            break;

        case STATE_ERROV2: //Erro quando o Alarme alto 2 é menor que o Alarme baixo 2
            if (evento == EV_B1) { //B1 enter
                setState(STATE_VALOR2M);
            }
            break;

        case STATE_ACERTOV1: //Mensagem quando os valores inseridos pelo usuario são validos
            if (evento == EV_B1) { //B1 enter
                setState(STATE_DISPLAY);
            }
            break;

        case STATE_ACERTOV2: //Mensagem quando os valores inseridos pelo usuario são validos
            if (evento == EV_B1) { //B1 enter
                setState(STATE_DISPLAY);
            }
            break;

        case STATE_MENUDISPLAYDATAHORA:
            if (evento == EV_B1) { //B1 enter
                setState(STATE_DISPLAYDATAHORA);
            }
            if (evento == EV_B3) { //B3 next
                setState(STATE_MENUCONFIGDATAHORA);
            }
            break;

        case STATE_DISPLAYDATAHORA: //Mostra Data e Hora atuais
            if (evento == EV_B2) { //B2 back
                setState(STATE_MENUDISPLAYDATAHORA);
            }
            break;

        case STATE_MENUCONFIGDATAHORA:
            if (evento == EV_B1) { //B1 enter
                setState(STATE_CONFIGDATA);
            }
            if (evento == EV_B3) { //B3 next
                setState(STATE_MENUVALORALRME1);
            }
            break;

        case STATE_CONFIGDATA:
            if (evento == EV_B1) { //B1 enter
                setState(STATE_VALORDATA);
            }
            if (evento == EV_B3) { //B3 next
                setState(STATE_CONFIGHORA);
            }
            if (evento == EV_B2) { //B2 back
                setState(STATE_MENUCONFIGDATAHORA);
            }
            break;

        case STATE_CONFIGHORA:
            if (evento == EV_B1) { //B1 enter
                setState(STATE_VALORHORA);
            }
            if (evento == EV_B3) { //B3 next
                setState(STATE_CONFIGDATA);
            }
            if (evento == EV_B2) { //B2 back
                setState(STATE_MENUCONFIGDATAHORA);
            }
            break;

        case STATE_VALORDATA: //estado para configuração da Data mesma logica usada para as configurações dos alarmes
            if (evento == EV_B3) { //B3 next, nesse caso muda a posição do cursor
                setCursor(getCursor() + 1);
                if (getCursor() > 3) {
                    setCursor(1);
                }
            }

            if ((getCursor() == 1) && (evento == EV_B4)) {
                rtcPutDay(rtcGetDay() + 1);
                if (rtcGetDay() > 31) {
                    rtcPutDay(rtcGetDay() - 32);
                }
            }
            if ((getCursor() == 1) && (evento == EV_B5)) {
                rtcPutDay(rtcGetDay() - 1);
                if (rtcGetDay() < 0) {
                    rtcPutDay(rtcGetDay() + 32);
                }
            }

            if ((getCursor() == 2) && (evento == EV_B4)) {
                rtcPutMonth(rtcGetMonth() + 1);
                if (rtcGetMonth() > 12) {
                    rtcPutDay(rtcGetDay() - 12);
                }
            }
            if ((getCursor() == 2) && (evento == EV_B5)) {
                rtcPutMonth(rtcGetMonth() - 1);
                if (rtcGetMonth() < 0) {
                    rtcPutDay(rtcGetDay() + 12);
                }
            }

            if ((getCursor() == 3) && (evento == EV_B4)) {
                rtcPutYear(rtcGetYear() + 1);
                if (rtcGetYear() > 99) {
                    rtcPutYear(rtcGetYear() - 99);
                }
            }
            if ((getCursor() == 3) && (evento == EV_B5)) {
                rtcPutYear(rtcGetYear() - 1);
                if (rtcGetYear() < 0) {
                    rtcPutYear(rtcGetYear() + 99);
                }
            }

            if (evento == EV_B1) { //B1 enter
                setState(STATE_CONFIGHORA);
            }
            if (evento == EV_B2) { //B2 back
                setState(STATE_CONFIGDATA);
            }
            break;

        case STATE_VALORHORA: //estado para configuração da Data mesma logica usada para as configurações dos alarmes
            if (evento == EV_B3) { //B3 next, nesse caso muda a posição do cursor
                setCursor(getCursor() + 1);
                if (getCursor() > 3) {
                    setCursor(1);
                }
            }

            if ((getCursor() == 1) && (evento == EV_B4)) {
                rtcPutHour(rtcGetHours() + 1);
                //if (rtcGetHours() > 24) {
                //    rtcPutHours(rtcGetHours() - 24);
                //}
            }
            if ((getCursor() == 1) && (evento == EV_B5)) {
                rtcPutHour(rtcGetHours() - 1);
                //if (rtcGetHours() < 0) {
                //  rtcPutHours(rtcGetHours() + 24);
                //}
            }

            if ((getCursor() == 2) && (evento == EV_B4)) {
                rtcPutMinutes(rtcGetMinutes() + 1);
                if (rtcGetMinutes() > 60) {
                    rtcPutMinutes(rtcGetMinutes() - 60);
                }
            }
            if ((getCursor() == 2) && (evento == EV_B5)) {
                rtcPutMinutes(rtcGetMinutes() - 1);
                if (rtcGetMinutes() < 0) {
                    rtcPutMinutes(rtcGetMinutes() + 60);
                }
            }

            if ((getCursor() == 3) && (evento == EV_B4)) {
                rtcPutSeconds(rtcGetSeconds() + 1);
                if (rtcGetSeconds() > 60) {
                    rtcPutSeconds(rtcGetSeconds() - 60);
                }
            }
            if ((getCursor() == 3) && (evento == EV_B5)) {
                rtcPutSeconds(rtcGetSeconds() - 1);
                if (rtcGetSeconds() < 0) {
                    rtcPutSeconds(rtcGetSeconds() - 60);
                }
            }

            if (evento == EV_B1) { //B1 enter       
                setState(STATE_CONFIGDATA);
            }
            if (evento == EV_B2) { //B2 back
                setState(STATE_CONFIGHORA);
            }
            break;

        case STATE_MENUVALORALRME1: //estado que mostra os alarmes que aconteceram
            if ((evento == EV_B1) &&(getA1() == 0)) { //verifica se aconteceu algum alarme caso não tenha 
                setState(STATE_VALORALRMEV1); //acontecido apresenta uma mensagem que nao ocorreu
            } //um alarme recentemente
            if ((evento == EV_B1) &&(getA1() != 0)) { //caso contrario mostra o alarme
                setState(STATE_VALORALRMENV1);
            }
            if (evento == EV_B3) {
                setState(STATE_MENUVALORALRME2);
            }
            break;

        case STATE_VALORALRMEV1: //mensagem quando o alarme 1 ainda não aconteceu
            if (evento == EV_B2) {
                setState(STATE_MENUVALORALRME1);
            }
            break;

        case STATE_VALORALRMENV1: //mostra os dados do ultimo alarme que aconteceu
            if (evento == EV_B2) {
                setState(STATE_MENUVALORALRME1);
            }
            break;

        case STATE_MENUVALORALRME2: //mesma lógica para ver os alarmes do alarme 1
            if ((evento == EV_B1) &&(getA2() == 0)) {
                setState(STATE_VALORALRMEV2);
            }
            if ((evento == EV_B1) &&(getA2() != 0)) {
                setState(STATE_VALORALRMENV2);
            }
            if (evento == EV_B3) {
                setState(STATE_MENUDISPLAY);
            }
            break;

        case STATE_VALORALRMEV2: //mensagem quando o alarme 2 ainda não aconteceu
            if (evento == EV_B2) {
                setState(STATE_MENUVALORALRME2);
            }
            break;

        case STATE_VALORALRMENV2: //mostra os dados do ultimo alarme que aconteceu
            if (evento == EV_B2) {
                setState(STATE_MENUVALORALRME2);
            }
            break;

        case STATE_IDLE:
            // LED_4_SetHigh();
            // while(UART1_Read() != '2'){
            //    
            // };
            // setState(STATE_DISPLAY);
            break;
    }
    outputPrint(getState(), getLanguage());
}

