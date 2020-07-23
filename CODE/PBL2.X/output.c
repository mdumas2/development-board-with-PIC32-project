#include "output.h"
#include "LCD_1.h"
#include "stateMachine.h"
#include "var.h"
#include "memoria_i2c.h"
#include "alarme.h"
#include "relogio.h"
#include "calendario.h"
#include "adc.h"
#include "lm35.h"

#define NUM_IDIOMAS 2
#define NUM_ESTADOS STATE_FIM
#define CURSOR_C 4
#define CURSOR_C2 4
#define CURSOR_C3 4

//msgs com 16 caracteres
//1 msg por estado (apenas linha de cima)
static char * msgs[NUM_ESTADOS][NUM_IDIOMAS] = {
    "", "",
    "Display Sensor  ", "Sensor Display  ",
    "Alterar idioma  ", "Change language ",
    "Portugues       ", "Portuguese      ",
    "Ingles          ", "English         ",
    "Configura Valor ", "Values Config   ",
    "Alterar sensorA ", "Change sensorA  ",
    "Alterar sensorB ", "Change sensorB  ",
    "", "",
    "", "",
    "", "",
    "", "",
    "Alterar alarmeA ", "Change alarmA   ",
    "Alterar alarmeB ", "Change alarmB   ",
    "", "",
    "", "",
    "ALARME 1 ATIVO  ", "ALARM 1         ",
    "ALARME 2 ATIVO  ", "ALARM 2         ",
    "m1>M1 INVALIDO  ", "m1>M1 INVALID   ",
    "m2>M2 INVALIDO  ", "m2>M2 INVALID   ",
    "M1>m1 VALIDO    ", "M1>m1 VALID     ",
    "M2>m2 VALIDO    ", "M2>m2 VALID     ",
    "Display DT/HR   ", "DT/HR Display   ",
    "", "",
    "Configura DT/HR ", "DT/HR Config    ",
    "Alterar DATA    ", "Change DATA     ",
    "Alterar HORA    ", "Change HOUR     ",
    "", "",
    "", "",
    "Alarme 1        ", "Alarm 1         ",
    "Alarme 1 vazio  ", "Alarm 1: empty  ",
    "", "",
    "Alarme 2        ", "Alarm 2         ",
    "Alarme 2 vazio  ", "Alarm 2: empty  ",
    "", "",
    "Configurando/PC ", "PC Configuration",
    "", ""
};
static char * Cursor[CURSOR_C] = {
    "^               ",
    " ^              ",
    "  ^             ",
    "   ^            "
};
static char * Cursor2[CURSOR_C2] = {
    "  ^             ",
    "   ^            ",
    "    ^           ",
    "     ^          "
};
static char * Cursor3[CURSOR_C3] = {
    " ^              ",
    "   ^            ",
    "      ^         ",
    "         ^      "
};


void outputInit(void) {
    lcdInit();
    //   ht1380write(7, 0);
}

void outputPrint(int numTela, int idioma) {

    switch (numTela) {
        case STATE_MENUDISPLAY:
            LCD_Set_Cursor(1, 1);
            lcdString(msgs[numTela][idioma]);
            LCD_Set_Cursor(2, 1);
            lcdString("1              >");
            break;

        case STATE_DISPLAY:
            LCD_Set_Cursor(1, 1);
            lcdString("A:");
            lcdInt(temp);
            LCD_Set_Cursor(1, 6);
            lcdString("M");
            lcdInt(getV1M());
            LCD_Set_Cursor(1, 10);
            lcdString("m");
            lcdInt(getV1m());
            LCD_Set_Cursor(1, 14);
            lcdString("   ");

            LCD_Set_Cursor(2, 1);
            lcdString("B:");
            lcdInt(adcRead2());
            LCD_Set_Cursor(2, 6);
            lcdString("M");
            lcdInt(getV2M());
            LCD_Set_Cursor(2, 10);
            lcdString("m");
            lcdInt(getV2m());
            LCD_Set_Cursor(2, 14);
            lcdString("   ");
            break;

        case STATE_MENULINGUAGEM:
            LCD_Set_Cursor(1, 1);
            lcdString(msgs[numTela][idioma]);
            LCD_Set_Cursor(2, 1);
            lcdString("2              >");
            break;

        case STATE_IDIOMAPT:
            LCD_Set_Cursor(1, 1);
            lcdString(msgs[numTela][idioma]);
            LCD_Set_Cursor(2, 1);
            lcdString("2.1            >");
            break;

        case STATE_IDIOMAEN:
            LCD_Set_Cursor(1, 1);
            lcdString(msgs[numTela][idioma]);
            LCD_Set_Cursor(2, 1);
            lcdString("2.2            >");
            break;

        case STATE_MENUCONFIGVALORES:
            LCD_Set_Cursor(1, 1);
            lcdString(msgs[numTela][idioma]);
            LCD_Set_Cursor(2, 1);
            lcdString("3              >");
            break;

        case STATE_CONFIGSENSOR1:
            LCD_Set_Cursor(1, 1);
            lcdString(msgs[numTela][idioma]);
            LCD_Set_Cursor(2, 1);
            lcdString("3.1            >");
            break;

        case STATE_CONFIGSENSOR2:
            LCD_Set_Cursor(1, 1);
            lcdString(msgs[numTela][idioma]);
            LCD_Set_Cursor(2, 1);
            lcdString("3.2            >");
            break;

        case STATE_VALOR1M:
            LCD_Set_Cursor(1, 1);
            lcdString("M");
            lcdInt(getV1M());
            lcdString("            ");
            LCD_Set_Cursor(2, 1);
            lcdString(Cursor[getCursor()]);
            lcdString("         M1");
            break;

        case STATE_VALOR1m:
            LCD_Set_Cursor(1, 1);
            lcdString("m");
            lcdInt(getV1m());
            lcdString("            ");
            LCD_Set_Cursor(2, 1);
            lcdString(Cursor[getCursor()]);
            lcdString("         m1");
            break;

        case STATE_VALOR2M:
            LCD_Set_Cursor(1, 1);
            lcdString("M");
            lcdInt(getV2M());
            lcdString("            ");
            LCD_Set_Cursor(2, 1);
            lcdString(Cursor[getCursor()]);
            lcdString("         M2");
            break;

        case STATE_VALOR2m:
            LCD_Set_Cursor(1, 1);
            lcdString("m");
            lcdInt(getV2m());
            lcdString("            ");
            LCD_Set_Cursor(2, 1);
            lcdString(Cursor[getCursor()]);
            lcdString("         m2");
            break;

        case STATE_CONFIGTEMPO1:
            LCD_Set_Cursor(1, 1);
            lcdString(msgs[numTela][idioma]);
            LCD_Set_Cursor(2, 1);
            lcdString("3.3            >");
            break;

        case STATE_CONFIGTEMPO2:
            LCD_Set_Cursor(1, 1);
            lcdString(msgs[numTela][idioma]);
            LCD_Set_Cursor(2, 1);
            lcdString("3.4            >");
            break;

        case STATE_VALORT1:
            LCD_Set_Cursor(1, 1);
            lcdString("T1:");
            lcdInt(getT1());
            LCD_Set_Cursor(1, 7);
            lcdString("          ");
            LCD_Set_Cursor(2, 1);
            lcdString(Cursor2[getCursor()]);
            lcdString(" mudanca T1");
            break;

        case STATE_VALORT2:
            LCD_Set_Cursor(1, 1);
            lcdString("T2:");
            lcdInt(getT2());
            LCD_Set_Cursor(1, 7);
            lcdString("          ");
            LCD_Set_Cursor(2, 1);
            lcdString(Cursor2[getCursor()]);
            lcdString(" mudanca T2");
            break;

        case STATE_1ATIVO:
            LCD_Set_Cursor(1, 1);
            lcdString(msgs[numTela][idioma]);
            LCD_Set_Cursor(2, 1);
            lcdString("T1:");
            lcdInt(adcRead1());
            lcdString("/");
            lcdInt(rtcGetHours());
            lcdString(":");
            lcdInt(rtcGetMinutes());
            lcdString(":");
            lcdInt(rtcGetSeconds());
            lcdString(" ");
            break;

        case STATE_2ATIVO:
            LCD_Set_Cursor(1, 1);
            lcdString(msgs[numTela][idioma]);
            LCD_Set_Cursor(2, 1);
            lcdString("T2:");
            lcdInt(adcRead2());
            lcdString("/");
            lcdInt(rtcGetHours());
            lcdString(":");
            lcdInt(rtcGetMinutes());
            lcdString(":");
            lcdInt(rtcGetSeconds());
            lcdString(" ");
            break;

        case STATE_ERROV1:
            LCD_Set_Cursor(1, 1);
            lcdString(msgs[numTela][idioma]);
            LCD_Set_Cursor(2, 1);
            lcdString("                ");
            break;

        case STATE_ERROV2:
            LCD_Set_Cursor(1, 1);
            lcdString(msgs[numTela][idioma]);
            LCD_Set_Cursor(2, 1);
            lcdString("                ");
            break;

        case STATE_ACERTOV1:
            LCD_Set_Cursor(1, 1);
            lcdString(msgs[numTela][idioma]);
            LCD_Set_Cursor(2, 1);
            lcdString("                ");
            break;

        case STATE_ACERTOV2:
            LCD_Set_Cursor(1, 1);
            lcdString(msgs[numTela][idioma]);
            LCD_Set_Cursor(2, 1);
            lcdString("                ");
            break;

        case STATE_MENUDISPLAYDATAHORA:
            LCD_Set_Cursor(1, 1);
            lcdString(msgs[numTela][idioma]);
            LCD_Set_Cursor(2, 1);
            lcdString("4              >");
            break;
        case STATE_DISPLAYDATAHORA:
            LCD_Set_Cursor(1, 1);
            lcdInt(10 * rtcGetDay());
            LCD_Set_Cursor(1, 3);
            lcdString("/");
            LCD_Set_Cursor(1, 4);
            lcdInt(10 * rtcGetMonth());
            LCD_Set_Cursor(1, 6);
            lcdString("/");
            LCD_Set_Cursor(1, 7);
            lcdString("20");
            LCD_Set_Cursor(1, 9);
            lcdInt(10 * rtcGetYear());
            LCD_Set_Cursor(1, 11);
            lcdString("      ");
            //lcdString("       ");
            LCD_Set_Cursor(2, 1);
            lcdInt(10 * rtcGetHours());
            LCD_Set_Cursor(2, 3);
            lcdString(":");
            LCD_Set_Cursor(2, 4);
            lcdInt(10 * rtcGetMinutes());
            LCD_Set_Cursor(2, 6);
            lcdString(":");
            LCD_Set_Cursor(2, 7);
            lcdInt(10 * rtcGetSeconds());
            LCD_Set_Cursor(2, 9);
            lcdString("        ");
            //lcdString("       ");
            break;
        case STATE_MENUCONFIGDATAHORA:
            LCD_Set_Cursor(1, 1);
            lcdString(msgs[numTela][idioma]);
            LCD_Set_Cursor(2, 1);
            lcdString("5              >");
            break;
        case STATE_CONFIGDATA:
            LCD_Set_Cursor(1, 1);
            lcdString(msgs[numTela][idioma]);
            LCD_Set_Cursor(2, 1);
            lcdString("5.1            >");
            break;
        case STATE_CONFIGHORA:
            LCD_Set_Cursor(1, 1);
            lcdString(msgs[numTela][idioma]);
            LCD_Set_Cursor(2, 1);
            lcdString("5.2            >");
            break;

        case STATE_VALORDATA:
            LCD_Set_Cursor(1, 1);
            lcdString("D:");
            LCD_Set_Cursor(1, 3);
            lcdInt(10 * rtcGetDay());
            LCD_Set_Cursor(1, 5);
            lcdString("/");
            LCD_Set_Cursor(1, 6);
            lcdInt(10 * rtcGetMonth());
            LCD_Set_Cursor(1, 8);
            lcdString("/");
            LCD_Set_Cursor(1, 9);
            lcdInt(10 * rtcGetYear());
            LCD_Set_Cursor(1, 11);
            lcdString("      ");
            LCD_Set_Cursor(2, 1);
            lcdString(Cursor3[getCursor()]);
            break;

        case STATE_VALORHORA:
            LCD_Set_Cursor(1, 1);
            lcdString("H:");
            LCD_Set_Cursor(1, 3);
            lcdInt(10 * rtcGetHours());
            LCD_Set_Cursor(1, 5);
            lcdString(":");
            LCD_Set_Cursor(1, 6);
            lcdInt(10 * rtcGetMinutes());
            LCD_Set_Cursor(1, 8);
            lcdString(":");
            LCD_Set_Cursor(1, 9);
            lcdInt(10 * rtcGetSeconds());
            LCD_Set_Cursor(1, 11);
            lcdString("      ");
            LCD_Set_Cursor(2, 1);
            lcdString(Cursor3[getCursor()]);
            break;

        case STATE_MENUVALORALRME1:
            LCD_Set_Cursor(1, 1);
            lcdString(msgs[numTela][idioma]);
            LCD_Set_Cursor(2, 1);
            lcdString("6               ");
            break;

        case STATE_VALORALRMEV1:
            LCD_Set_Cursor(1, 1);
            lcdString(msgs[numTela][idioma]);
            LCD_Set_Cursor(2, 1);
            lcdString("                ");
            break;

        case STATE_VALORALRMENV1:
            LCD_Set_Cursor(1, 1);
            lcdString("T=");
            lcdInt(getA1());
            lcdString("D:");
            lcdInt(getDd1());
            lcdString("/");
            lcdInt(getDm1());
            lcdString("/");
            lcdInt(getDa1());
            LCD_Set_Cursor(2, 1);
            lcdString("H:");
            lcdInt(getHh1());
            lcdString(":");
            lcdInt(getHm1());
            lcdString(":");
            lcdInt(getHs1());
            lcdString("      ");
            break;

        case STATE_MENUVALORALRME2:
            LCD_Set_Cursor(1, 1);
            lcdString(msgs[numTela][idioma]);
            LCD_Set_Cursor(2, 1);
            lcdString("7               ");
            break;

        case STATE_VALORALRMEV2:
            LCD_Set_Cursor(1, 1);
            lcdString(msgs[numTela][idioma]);
            LCD_Set_Cursor(2, 1);
            lcdString("                ");
            break;

        case STATE_VALORALRMENV2:
            LCD_Set_Cursor(1, 1);
            lcdString("T=");
            lcdInt(getA2());
            lcdString("D:");
            lcdInt(getDd2());
            lcdString("/");
            lcdInt(getDm2());
            lcdString("/");
            lcdInt(getDa2());
            LCD_Set_Cursor(2, 1);
            lcdString("H:");
            lcdInt(getHh2());
            lcdString(":");
            lcdInt(getHm2());
            lcdString(":");
            lcdInt(getHs2());
            lcdString("      ");
            break;

        case STATE_IDLE:
            LCD_Set_Cursor(1, 1);
            lcdString(msgs[numTela][idioma]);
            LCD_Set_Cursor(2, 1);
            lcdString("A               ");
            break;
    }
}