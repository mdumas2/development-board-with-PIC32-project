/* 
 * File:   Teclado.h
 * Author: mateu
 *
 * Created on October 1, 2019, 4:32 PM
 */

#ifndef TECLADO_H
#define	TECLADO_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

enum {
    EV_B5,
    EV_B4,
    EV_B3,
    EV_B2,
    EV_B1,
    EV_NOEVENT
};

void eventInit(void);
unsigned int eventRead(void);
unsigned int kpRead(void);
void kpDebounce(void);
void kpInit(void);

#endif	/* TECLADO_H */

