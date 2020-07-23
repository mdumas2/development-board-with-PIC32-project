/* 
 * File:   var.h
 * Author: mateu
 *
 * Created on 12 de Outubro de 2019, 18:09
 */

#ifndef VAR_H
#define	VAR_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

void varInit(void);

char getState(void);
void setState(char newState);

char getLanguage(void);
void setLanguage(char newLanguage);

unsigned int getCursor(void);
void setCursor(unsigned int newAux);

int getV1M(void);
void setV1M(int newAux);

int getV1m(void);
void setV1m(int newAux);

unsigned int getV2M(void);
void setV2M(unsigned int newAux);

int getV2m(void);
void setV2m(unsigned int newAux);

int getT1(void);
void setT1(int newAux);

int getT2(void);
void setT2(int newAux);

char getCondition(char alarm);
void setCondition(char alarm, char condition);

int getA1(void);
void setA1(int newAux);

int getDd1(void);
void setDd1(int newAux);

int getDm1(void);
void setDm1(int newAux);

int getDa1(void);
void setDa1(int newAux);

int getHh1(void);
void setHh1(int newAux);

int getHm1(void);
void setHm1(int newAux);

int getHs1(void);
void setHs1(int newAux);

int getA2(void);
void setA2(int newAux);

int getDd2(void);
void setDd2(int newAux);

int getDm2(void);
void setDm2(int newAux);

int getDa2(void);
void setDa2(int newAux);

int getHh2(void);
void setHh2(int newAux);

int getHm2(void);
void setHm2(int newAux);

int getHs2(void);
void setHs2(int newAux);

int temp;

#endif	/* VAR_H */

