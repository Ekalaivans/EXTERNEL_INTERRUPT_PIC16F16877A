
#pragma config FOSC = HS     // High-speed Oscillator
#pragma config WDTE = OFF    // Watchdog Timer disabled
#pragma config PWRTE = OFF   // Power-up Timer disabled
#pragma config BOREN = OFF   // Brown-out Reset disabled
#pragma config LVP = OFF     // Low-Voltage Programming disabled
#pragma config CPD = OFF     // Data EEPROM Code Protection off
#pragma config WRT = OFF     // Flash Program Memory Write disabled
#pragma config CP = OFF      // Code Protection off

#include <xc.h>
#define _XTAL_FREQ 20000000   // 20MHz crystal

#define LED   RC0   // Main LED (blinks continuously)
#define LED1  RC7   // Interrupt LED (blinks on interrupt)

// Simple delay function
void delay(unsigned int d) {
    unsigned int i, j;
    for (i = 0; i < d; i++) {
        for (j = 0; j < 500; j++) {
            // Waste cycles
        }
    }
}

// Interrupt Service Routine
void __interrupt() ISR(void) {
    if (INTF) {   // Check INT0 interrupt flag
        LED1 = 1;       // Turn LED1 ON
        delay(500);
        LED1 = 0;       // Turn LED1 OFF
        delay(500);

        INTF = 0;       // Clear interrupt flag
    }
}

void main(void) {
    // Port setup
    TRISB0 = 1;   // RB0 as input (INT0 pin)
    TRISC0 = 0;   // RC0 as output (blinking LED)
    TRISC7 = 0;   // RC7 as output (interrupt LED)

    // Interrupt setup
    INTCON = 0b11010000;  // GIE=1, PEIE=0, INTE=1, INTF=0
    OPTION_REG = 0x00;    // INT0 triggered on rising edge

    while (1) {
        // Main LED blinking continuously
        LED = 1;
        delay(500);
        LED = 0;
        delay(500);
    }
}

