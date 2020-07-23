/* 
 * File:   event.h
 * Author: mateu
 *
 * Created on 12 de Outubro de 2019, 17:46
 */

#ifndef EVENT_H
#define	EVENT_H

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

#endif	/* EVENT_H */

