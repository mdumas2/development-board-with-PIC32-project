#include "var.h"
#include "relogio.h"
#include "memoria_i2c.h"
#include "calendario.h"
#include "mcc_generated_files/clock.h"
#include "mcc_generated_files/uart1.h"
#include "mcc_generated_files/pin_manager.h"

//variáveis a serem armazenadas
static char state, language;
unsigned int V1M, V1m, V2M, V2m, T1, T2, A1, A2,Hh1,Hm1,Hs1,Dd1,Dm1,Da1,Hh2,Hm2,Hs2,Dd2,Dm2,Da2;
int flag_1 = 0;
static unsigned int aux;

void varInit(void) {
    Dd1= memRead(0x0030);
    Dd2= memRead(0x0031);
    Dm1= memRead(0x0032);
    Dm2= memRead(0x0033);
    Da1= memRead(0x0034);
    Da2= memRead(0x0035);
    Hh1= memRead(0x0036); 
    Hh2= memRead(0x0037);
    Hm1= memRead(0x0038); 
    Hm2= memRead(0x0039);
    Hs1= memRead(0x0040);
    Hs2= memRead(0x0041);
    A1 = memRead(0x0007);
    A2 = memRead(0x000E);
    state = 0;
    T1 = ((memRead(0x0001)<<8)&0xff00) | (memRead(0x0002)&0x00ff);
    T2 = ((memRead(0x0003)<<8)&0xff00) | (memRead(0x0004)&0x00ff);
    V1M = ((memRead(0x0005)<<8)&0xff00) | (memRead(0x0006)&0x00ff);
  //  V1m = memRead(0x0005);
    V1m = 0;
    V2M = ((memRead(0x0007)<<8)&0xff00) | (memRead(0x0008)&0x00ff);
    V2m = 0;
  //  V2m = memRead(0x0006);
}

char getState(void) {
    return state;
}

void setState(char newState) {
    state = newState;
}

char getLanguage(void) {
    if (memRead(0x0040) == 1){
       return 1; 
    }
    else {
       return 0; 
    }
   // return language;
}

void setLanguage(char newLanguage) {
    language = newLanguage % 2;
    if (getLanguage() == 0) { //WE DO THE VERIFICATION TO NOTHING GO WRONG IN THE LANGUAGE CHANGE
        memWrite(0x0040,1);
       } else {
        memWrite(0x0040,0);
       }
}

int getT1(void) {
    return ((memRead(0x0001)<<8)&0xff00) | (memRead(0x0002)&0x00ff);
}

void setT1(int newTime) {
    int tempo1;
    tempo1 = ((newTime*2)-1);
     memWrite(0x0001,(tempo1>>8)&0xff);
     memWrite(0x0002,tempo1&0xff);     
     TMR1_Counter16BitSet(((memRead(0x0001)<<8)&0xff00) | (memRead(0x0002)&0x00ff));
}

int getT2(void) {
    return ((memRead(0x0003)<<8)&0xff00) | (memRead(0x0004)&0x00ff);
}

void setT2(int newTime) {
    int tempo2;
    tempo2 = ((newTime*2)-1);
     memWrite(0x0003,(tempo2>>8)&0xff);
     memWrite(0x0004,tempo2&0xff);
     TMR1_Counter16BitSet(((memRead(0x0003)<<8)&0xff00) | (memRead(0x0004)&0x00ff));
}

int getV1M(void) {
    return ((memRead(0x0005)<<8)&0xff00) | (memRead(0x0006)&0x00ff);
}

int getV1m(void) {
    return V1m;
}

unsigned int getV2M(void) {
    return ((memRead(0x0007)<<8)&0xff00) | (memRead(0x0008)&0x00ff);
}

int getV2m(void) {
    return V2m;
}

int getA1(void) {
    return memRead(0x0007);
}

int getDd1(void) {
    return memRead(0x0008);
}

int getDm1(void) {
    return memRead(0x0009);
}

int getDa1(void) {
    return memRead(0x000A);
}

int getHh1(void) {
    return memRead(0x000B);
}

int getHm1(void) {
    return memRead(0x000C);
}

int getHs1(void) {
    return memRead(0x000D);
}

int getA2(void) {
    return memRead(0x000E);
}

int getDd2(void) {
    return memRead(0x000F);
}

int getDm2(void) {
    return memRead(0x0010);
}

int getDa2(void) {
    return memRead(0x0011);
}

int getHh2(void) {
    return memRead(0x0012);
}

int getHm2(void) {
    return memRead(0x0013);
}

int getHs2(void) {
    return memRead(0x0014);
}

void setV1M(int VA1M) {
    memWrite(0x0005,(VA1M>>8)&0xff);
    memWrite(0x0006,VA1M&0xff);
}

void setV2M(unsigned int VA2M) {
    memWrite(0x0007,(VA2M>>8)&0xff);
    memWrite(0x0008,VA2M&0xff);
}

void setV1m(int VA1m) {
    V1m = VA1m;
    memWrite(0x0005,V1m);
}

void setV2m(unsigned int VA2m) {
    V2m = VA2m;
    memWrite(0x0006,V2m);
}

void setA1(int A1) {
    A1 = A1;
    memWrite(0x0007,A1);
}

void setDd1(int Dd1) {
    Dd1= Dd1;
    memWrite(0x0008,Dd1);
}

void setDm1(int Dm1) {
    Dm1= Dm1;
    memWrite(0x0009,Dm1); 
}

void setDa1(int Da1) {
    Da1= Da1;
    memWrite(0x000A,Da1);
}

void setHh1(int Hh1) {
    Hh1 = Hh1;
    memWrite(0x000B,Hh1);
}

void setHm1(int Hm1) {
    Hm1 = Hm1;
    memWrite(0x000C,Hm1);
}

void setHs1(int Hs1) {
    Hs1 = Hs1;
    memWrite(0x000D,Hs1);
}

void setA2(int A2) {
    A2 = A2;
    memWrite(0x000E,A2);
}

void setDd2(int Dd2) {
    Dd2 = Dd2;
    memWrite(0x000F,Dd2);
}

void setDm2(int Dm2) {
    Dm2 = Dm2;
    memWrite(0x0010,Dm2);
}

void setDa2(int Da2) {
    Da2 = Da2;
    memWrite(0x0011,Da2);
}

void setHh2(int Hh2) {
    Hh2 = Hh2;
    memWrite(0x0012,Hh2);
}

void setHm2(int Hm2) {
    Hm2 = Hm2;
    memWrite(0x0013,Hm2);
}

void setHs2(int Hs2) {
    Hs2 = Hs2;
    memWrite(0x0014,Hs2);
}

unsigned int getCursor(void) {
    return aux;
}

void setCursor(unsigned int newAux) {
    aux = newAux;
}
