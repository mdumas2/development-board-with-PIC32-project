/* 
 * File:   calendario.h
 * Author: GUILH
 *
 * Created on 12 de Outubro de 2019, 16:53
 */

#ifndef CALENDARIO_H
#define	CALENDARIO_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif
int rtcGetYear(void);
int rtcGetMonth(void);
int rtcGetDay(void);
void rtcPutYear(int ano);
void rtcPutMonth(int mes);
void rtcPutDay(int dia);

#endif	/* CALENDARIO_H */

