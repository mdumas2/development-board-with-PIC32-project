/* 
 * File:   relogio.h
 * Author: GUILH
 *
 * Created on 12 de Outubro de 2019, 16:33
 */

#ifndef RELOGIO_H
#define	RELOGIO_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif
void rtcPutSeconds(int segundos);
void rtcPutMinutes(int minutos);
void rtcPutHour(int hora);
int rtcGetSeconds(void);
int rtcGetMinutes(void);
int rtcGetHours(void);
#endif	/* RELOGIO_H */

