/*
 -----------------------------------
 * Biblioteca EEPROM I2C - PBLE02
 * Autor: Pedro Linhares
 * pedrolinhares at unifei.edu.br
 
 */

#ifndef MEMORIA_H
#define MEMORIA_H
#include <xc.h>

#define SDA_PIN 2
#define SCL_PIN 3

#define SDA_OUT() TRISBCLR = (1 << SDA_PIN)
#define SDA_IN() TRISBSET = (1 << SDA_PIN)

#define US_DELAY 1

#define SCL_OFF() LATBCLR = (1 << SCL_PIN)
#define SCL_ON() LATBSET = (1 << SCL_PIN)
#define SDA_OFF() LATBCLR = (1 << SDA_PIN)
#define SDA_ON() LATBSET = (1 << SDA_PIN)
#define SDA() PORTBbits.RB2 /*ALTERAR COM SDA_PIN!*/
#define DELAY() Delay10us(US_DELAY);
#define DELAY2() Delay10us(US_DELAY);
#define ACK() do { SDA_IN(); SCL_ON(); DELAY(); SCL_OFF(); SDA_OUT(); DELAY(); } while(0)
#define CONTROL_BYTE 0xA0
#define ADDR 0x0
//#define MEM_DEBUG //SE MEM_DEBUG FOR DEFINIDO AS FUNÇÕES PRINTAM NO SERIAL TODA A COMUNICAÇÃO I2C -> AUMENTA MUITO O DELAY
typedef enum{
    MEM_READ,
    MEM_WRITE,
} MEM_OP;

void memInit(void);

//Após escrever com memWrite(), esperar 5ms antes de fazer leitura
void memWrite(uint16_t addr, unsigned int c);
unsigned char memRead(uint16_t addr);


#endif
 