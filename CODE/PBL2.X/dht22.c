#include "mcc_generated_files/system.h"
#include "mcc_generated_files/pin_manager.h"
#include "LCD_1.h"
#include "mcc_generated_files/clock.h"
#include "mcc_generated_files/uart1.h"
#include <stdio.h>
/*

char message1[] = "Temp = 00.0 C";
char message2[] = "RH   = 00.0 %";
short Time_out ;
unsigned int T_byte1, T_byte2, RH_byte1, RH_byte2, CheckSum ;
unsigned int Temp, RH;

void start_signal(){
  IO_RB5_SetDigitalOutput();           // Configure connection pin as output
  IO_RB5_SetLow();                      // Connection pin output low
  DelayMiliS(25);
  IO_RB5_SetHigh();                  // Connection pin output high
  Delay10us(3);
  IO_RB5_SetDigitalInput();          // Configure connection pin as input
}
short check_response(){
  Delay10us(4);
  if(!IO_RB5_GetValue()){                     // Read and test if connection pin is low
    Delay10us(8);
    if(IO_RB5_GetValue()){                    // Read and test if connection pin is high
      Delay10us(5);
      return 1;}
    }
}
unsigned int Read_Data(){
  unsigned int i, k, _data = 0;     // k is used to count 1 bit reading duration
  if(Time_out)
    return;
  for(i = 0; i < 8; i++){
    k = 0;
    while(!IO_RB5_GetValue()){                          // Wait until pin goes high
      k++;
      if (k > 100) {Time_out = 1; break;}
      Delay10us(1);}
      Delay10us(3);
    if(!IO_RB5_GetValue())
      BitClr(_data, (7 - i));               // Clear bit (7 - i)
    else{
      BitSet(_data, (7 - i));                 // Set bit (7 - i)
      while(IO_RB5_GetValue()){                         // Wait until pin goes low
      k++;
      if (k > 100) {Time_out = 1; break;}
      Delay10us(1);}
    }
  }
  return _data;
}
void principal(){
  lcdInit();                                // Initialize LCD module
  lcdClear();                             // LCD clear 
  while(1){
    DelayMiliS(2000);
    Time_out = 0;
    start_signal();
    if(check_response()){                    // If there is response from sensor
      RH_byte1 = Read_Data();                 // read RH byte1
      RH_byte2 = Read_Data();                 // read RH byte2
      T_byte1 = Read_Data();                  // read T byte1
      T_byte2 = Read_Data();                  // read T byte2
      CheckSum = Read_Data();                 // read checksum
      if(Time_out){                           // If reading takes long time
        lcdClear();                  // LCD clear
        LCD_Set_Cursor(2,1);                     // Go to column 5 row 1
        lcdString("Time out!");
      }
      else{
       if(CheckSum == ((RH_byte1 + RH_byte2 + T_byte1 + T_byte2) & 0xFF)){
        RH = RH_byte1;
        RH = (RH << 8) | RH_byte2;
        Temp = T_byte1;
        Temp = (Temp << 8) | T_byte2;
        unsigned char *umid;
        unsigned char *tmp;
        itoa(umid,RH,10);
        itoa(tmp,Temp,10);
        send_string(umid);
        send_string(tmp);
        if (Temp > 0X8000){
         message1[6] = '-';
         Temp = Temp & 0X7FFF; }
        else
        message1[6] = ' ';
        message1[7]  = (Temp / 100) % 10  + 48;
        message1[8]  = (Temp / 10) % 10  + 48;
        message1[10] = Temp % 10  + 48;
        message2[7]  = (RH / 100) % 10 + 48;
        message2[8]  = (RH / 10) % 10 + 48;
        message2[10] = RH % 10 + 48;
        message1[11] = 223;                   // Degree symbol
        lcdClear();                      // LCD clear    
        LCD_Set_Cursor(2,1);  
        lcdString(message1);         // Display message1
        LCD_Set_Cursor(2,1);                     // Go to column 1 row 2
        lcdString(message2);          // Display message2
       }
        else {
          lcdClear();                      // LCD clear    
          LCD_Set_Cursor(1,1);                  // Go to column 1 row 1
          lcdString("Checksum Error!");
        }
      }
    }
    else {
      lcdClear();                      // LCD clear    
      LCD_Set_Cursor(1,1);          // Go to column 3 row 1
      lcdString("No response");
      LCD_Set_Cursor(2,1);            // Go to column 1 row 2
      lcdString("from the sensor");
    }
  }
}
*/

