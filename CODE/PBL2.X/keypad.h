/* 
 * File:   keypad.h
 * Author: mateu
 *
 * Created on 12 de Outubro de 2019, 17:46
 */

#ifndef KEYPAD_H
#define	KEYPAD_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

unsigned int kpRead(void);
void kpDebounce(void);
void kpInit(void);

#endif	/* KEYPAD_H */

