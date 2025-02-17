//# EXTERNEL_INTERRUPT_PIC16F16877A
//ISR FUNCTION

// 'C' source line config statements

// CONFIG
#pragma config FOSC = HS    // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

// PIC16F877A Configuration Bit Settings

#include <xc.h>
#define _XTAL_FREQ 20000000
#define LED RC0
#define LED1 RC7
void delay(unsigned int d);
void delay(unsigned int d)
{
    int i,j;
    for(i=0;i<d;i++)
    {
        for(j=0;j<500;j++)
        {
            
        }
    }
}
void main(void) 
{
    TRISB = 0b00000001;
    INTCON = 0b1101000;
    OPTION_REG = 0x00;
    TRISC = 0x00;
    
    while(1)
    {
        LED= 1;
        delay(500);
        LED = 0;
        delay(500);
    }
} 

void __interrupt()ISR()
{
    if(INTCONbits.INTF == 1)
    {
        
        LED1 = 1;
        delay(500);
        LED1 = 0;
        delay(500);
        INTF = 0;
    }
    
}
