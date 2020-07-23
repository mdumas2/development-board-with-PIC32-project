#include "mcc_generated_files/system.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/clock.h"
#include "LCD_1.h"

void delayMS(unsigned char ms) {
    volatile unsigned int i;
    for (; ms > 0; ms--);
    {
        for (i = 0; i < 700; i++);
    }
}

void pulseEnablePin() {
    IO_RC5_SetHigh();  
    IO_RC5_SetLow();     
}

void pushNibble(int value, int rs) {
    if (BitTst(value, 4)) IO_RC6_SetHigh(); else IO_RC6_SetLow();
    if (BitTst(value, 5)) IO_RC7_SetHigh(); else IO_RC7_SetLow();
    if (BitTst(value, 6)) IO_RC8_SetHigh(); else IO_RC8_SetLow();
    if (BitTst(value, 7)) IO_RC9_SetHigh(); else IO_RC9_SetLow();
    //pulseEnablePin();
  /*  if (BitTst(value, 0)) LCD0_SetHigh(); else LCD0_SetLow();
    if (BitTst(value, 1)) LCD1_SetHigh(); else LCD1_SetLow();
    if (BitTst(value, 2)) LCD2_SetHigh(); else LCD2_SetLow();
    if (BitTst(value, 3)) LCD3_SetHigh(); else LCD3_SetLow();
    *///seta o RS para dados (1) ou comando (0)
    if (rs)  IO_RC3_SetHigh(); else IO_RC3_SetLow();
    pulseEnablePin();
}

void pushByte(int value, int rs) {
    int val_lower = (value << 4) &0xf0;
    int val_upper = value & 0xF0;
    pushNibble(val_upper, rs);
    pushNibble(val_lower, rs);
}

void lcdCommand4bits(int nibble) {
    pushNibble(nibble << 4, 0);
}

void lcdCommand8bits(int value) {
    pushByte(value, 0);
    delayMS(1);
}

void lcdChar(int value) {
    //let pushByte worry about the intricacies of Enable, nibble order.
    pushByte(value, 1);
    delayMS(1);
}

void lcdString(char msg[]) {
    unsigned char i = 0; //fancy int.  avoids compiler warning when comparing i with strlen()'s uint8_t
    while (msg[i]) {
        lcdChar(msg[i]);
        i++;
    }
}

void lcdInt(int val) {
    if (val < 0) {
        val = val * (-1);
        lcdData('-');
    }

    lcdData((val / 100) % 10 + 48);
    lcdData((val / 10) % 10 + 48);
    lcdData((val / 1) % 10 + 48);

}

void lcdInit() {
    IO_RC4_SetLow();            
    delayMS(15); //15ms

    //The first 4 nibbles and timings are not in my DEM16217 SYH datasheet, but apparently are HD44780 standard...
    lcdCommand4bits(0x03);
    delayMS(1);
    lcdCommand4bits(0x03);
    delayMS(1); //100us
    lcdCommand4bits(0x03);
    delayMS(5);

    // needed by the LCDs controller
    //this being 2 sets up 4-bit mode.
    lcdCommand4bits(0x02);
    delayMS(1);

    //configura o display
    lcdCommand8bits(0x28); //8bits, 2 linhas, 5x8
    lcdCommand8bits(0x06); //modo incremental
    lcdCommand8bits(0x0c); //display e cursor on, com blink
    lcdCommand8bits(0x03); //zera tudo
    lcdCommand8bits(0x80); //posição inicial
    lcdCommand8bits(0x01); //limpar display
}

void lcdData(unsigned char value)
{/*
    LCD_RS_SetHigh();
    
    if (BitTst(value, 4)) LCD0_SetHigh(); else LCD0_SetLow();
    if (BitTst(value, 5)) LCD1_SetHigh(); else LCD1_SetLow();
    if (BitTst(value, 6)) LCD2_SetHigh(); else LCD2_SetLow();
    if (BitTst(value, 7)) LCD3_SetHigh(); else LCD3_SetLow();
    pulseEnablePin();*/
    pushByte(value, 1);
    delayMS(2);
}

void lcdClear(){
   lcdCommand8bits(0x01);
}

void LCD_Set_Cursor(unsigned char r, unsigned char c)
{
  unsigned char Temp;
  if(r == 1) 
  {
    Temp = 0x80 + c - 1; //0x80 is used to move the cursor
    lcdCommand8bits(Temp);
  }
  if(r == 2) 
  {
    Temp = 0xC0 + c - 1;
    lcdCommand8bits(Temp);
  }
}

void LCD_SR()
{
  lcdCommand8bits(0x1C);
}

void LCD_SL()
{
  lcdCommand8bits(0x18);
}
/*
void Delay10us(uint32_t delay)
{
    volatile uint32_t _d;
    _d = delay * ((uint32_t) (0.00001 / (1.0 / CLOCK_InstructionFrequencyGet()) / 10));
    while(_d--)
    {
        asm("nop");
        asm("nop");
        asm("nop");
    }
}
void DelayMiliS(uint16_t ms)
{
    unsigned char i;
    while(ms--)
    {
        i = 4;
        while(i--)
        {
            Delay10us(25);
        }
            
    }
}
*/
