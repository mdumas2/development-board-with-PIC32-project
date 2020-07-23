#include "event.h"
#include "adc.h"
#include "var.h"
#include "memoria_i2c.h"
#include "stateMachine.h"
#include "relogio.h"
#include "calendario.h"

// essa biblioteca é responsavel por testar os valores do alarme e ativarem caso algo aconteça
//e tambem salvar os dados de quando o alarme aconteceu

void Alarme1Tst(void) {
    if (adcRead1() > getV1M()) {
        setA1(adcRead1());
        setDd1(rtcGetDay());
        setDm1(rtcGetMonth());
        setDa1(rtcGetYear());
        setHh1(rtcGetHours());
        setHm1(rtcGetMinutes());
        setHs1(rtcGetSeconds());
        setState(STATE_1ATIVO);
    }
    if (adcRead1() < getV1m()) {
        setA1(adcRead1());
        setDd1(rtcGetDay());
        setDm1(rtcGetMonth());
        setDa1(rtcGetYear());
        setHh1(rtcGetHours());
        setHm1(rtcGetMinutes());
        setHs1(rtcGetSeconds());
        setState(STATE_1ATIVO);
    }
}

void Alarme2Tst(void) {
    if (adcRead2() > getV2M()) {
        setA2(adcRead2());
        setDd2(rtcGetDay());
        setDm2(rtcGetMonth());
        setDa2(rtcGetYear());
        setHh2(rtcGetHours());
        setHm2(rtcGetMinutes());
        setHs2(rtcGetSeconds());
        setState(STATE_2ATIVO);
    }
    if (adcRead2() < getV2m()) {
        setA2(adcRead2());
        setDd2(rtcGetDay());
        setDm2(rtcGetMonth());
        setDa2(rtcGetYear());
        setHh2(rtcGetHours());
        setHm2(rtcGetMinutes());
        setHs2(rtcGetSeconds());
        setState(STATE_2ATIVO);
    }
}

