/* 
 * File:   LCD_1.h
 * Author: GUILH
 *
 * Created on September 16, 2019, 9:15 PM
 */

#ifndef LCD_1_H
#define	LCD_1_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#define RS  IO_RC3_SetLow();     //rc3
#define EN  IO_RC5_SetLow();     //rc5
#define D4  IO_RC6_SetHigh();     //rc6
#define D5  IO_RC7_SetLow();     //rc7
#define D6  IO_RC8_SetLow();     //rc8
#define D7  IO_RC9_SetLow();     //rc9

//==========================================
//-----[ Prototypes For All Functions ]-----
#define BitSet(arg,bit) ((arg) |= (1<<bit))
#define BitClr(arg,bit) ((arg) &= ~(1<<bit)) 
#define BitFlp(arg,bit) ((arg) ^= (1<<bit)) 
#define BitTst(arg,bit) ((arg) & (1<<bit)) 

void delayMS(unsigned char ms);
void pulseEnablePin(void);
void pushNibble(int value, int rs);
void pushByte(int value, int rs);
void lcdCommand4bits(int nibble);
void lcdCommand8bits(int value);
void lcdChar(int value);
void lcdString(char msg[]);
void lcdDefconLogo(void);
void lcdInit(void);
void lcdData(unsigned char value);
void LCD_Set_Cursor(unsigned char r, unsigned char c);
void lcdClear(void);
void LCD_SR(void);
//void Delay10us(uint32_t delay);
//void DelayMiliS(uint16_t ms);
void LCD_SL(void);
void lcdInt(int val);

#endif	/* LCD_1_H */

