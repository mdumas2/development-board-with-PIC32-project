#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/system.h"
#include "memoria_i2c.h"
#include "mcc_generated_files/uart1.h"
#include "LCD_1.h"
void memInit(void)
{
    TRISBCLR = (1 << SDA_PIN);
    TRISBCLR = (1 << SCL_PIN);
}


void sendStartBit(void)
{
#ifdef MEM_DEBUG
    UART1_WriteString(" START ", 7);
#endif
    SDA_ON();
    DELAY();
    SCL_ON();
    DELAY();
    SDA_OFF();
    DELAY();
    SCL_OFF();
}

void sendStopBit(void)
{
    SDA_OFF();
    DELAY();
    SCL_ON();
    DELAY();
    SDA_ON();
    DELAY();
    SCL_OFF();
#ifdef MEM_DEBUG
    UART1_WriteString(" STOP ", 6);
#endif
}

void writeByte(char c)
{
    SDA_OUT();
    SCL_OFF();
    char i;
    for(i = 0; i < 8; i++)
    {
        if((c<<i) & 0x80)
        {
            SDA_ON();
#ifdef MEM_DEBUG
            UART1_Write('1');
#endif
        }else {
            SDA_OFF();
#ifdef MEM_DEBUG
            UART1_Write('0');
#endif
        }
        DELAY2();
        SCL_ON();
        DELAY();
        SCL_OFF();
        DELAY();
    }
#ifdef MEM_DEBUG
    UART1_WriteString(" ACK ", 5);
#endif
    ACK();
}

unsigned char readByte(void)
{
    char i;
    SDA_IN();
    unsigned char response = 0x00;
    SCL_OFF();
    for(i = 0; i < 8; i++)
    {
        SCL_ON();
        DELAY();
        response <<= 1;
        if(SDA())
        {
#ifdef MEM_DEBUG
            UART1_Write('1');
#endif
            response |= 0x01;
        }
#ifdef MEM_DEBUG
        else {
            UART1_Write('0');
        }
#endif
        SCL_OFF();
        DELAY();
    }
    SDA_OUT();
    return response;
}

void sendControlByte(MEM_OP cmd)
{
    unsigned char byte = CONTROL_BYTE + ADDR + ((cmd == MEM_READ)?0x01:0x00);
    writeByte(byte);
}

void txStart(MEM_OP op, uint16_t addr)
{
    sendStartBit();
    sendControlByte(op);
    writeByte(addr>>8);
    writeByte(addr&0x00FF);
}

void txStop(void)
{
    sendStopBit();
}

void memWrite(uint16_t addr, unsigned int c)
{
#ifdef MEM_DEBUG
    UART1_WriteString("\nESCREVENDO\n",12);
#endif
    txStart(MEM_WRITE, addr);
    writeByte(c);
    txStop();
    DelayMiliS(5);
}
unsigned char memRead(uint16_t addr)
{
#ifdef MEM_DEBUG
    UART1_WriteString("\nLENDO\n",7);
#endif
    char i;
    char leitura;
    txStart(MEM_WRITE, addr);
    sendStartBit();
    sendControlByte(MEM_READ);
    leitura = readByte();
    txStop();
    /*UART1_Write('\n');
    for(i = 0; i < 8; i++)
    {
        if((leitura<<i) & 0x80)
        {
            UART1_Write('1');
        }else {
            UART1_Write('0');
        }
    }
    UART1_Write('\n');
     */
    return leitura;
}
 
