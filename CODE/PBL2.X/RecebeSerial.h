/* 
 * File:   RecebeSerial.h
 * Author: GUILH
 *
 * Created on 13 de Outubro de 2019, 13:58
 */

#ifndef RECEBESERIAL_H
#define	RECEBESERIAL_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

uint8_t UARTReadString(char *buf, uint8_t max_length);
void send_string(const char *x);
void Recebe_Valores_Serial(void);

#endif	/* RECEBESERIAL_H */

