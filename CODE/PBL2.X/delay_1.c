#include "mcc_generated_files/system.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/clock.h"
#include "LCD_1.h"

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
