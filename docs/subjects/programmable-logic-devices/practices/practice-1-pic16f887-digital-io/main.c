/**
 * @file main.c
 * @author fermeridamagni
 * @date 2025-09-20
 * @description Main function for PIC16F887 microcontroller. Reads digital inputs from pins RC1, RD2, and RD7, and controls corresponding outputs on RD0, RA2, and RB3 respectively.
 */

#include <pic16f887.h>
#include <xc.h>

// Configuration bits
#pragma config FOSC = INTRC_NOCLKOUT // Internal RC oscillator, no CLKOUT
#pragma config WDTE = OFF            // Watchdog Timer disabled
#pragma config PWRTE = ON            // Power-up Timer enabled
#pragma config MCLRE = ON            // MCLR pin function enabled
#pragma config CP = OFF              // Code protection disabled
#pragma config CPD = OFF             // Data code protection disabled
#pragma config BOREN = ON            // Brown-out Reset enabled
#pragma config IESO = ON             // Internal/External Switchover enabled
#pragma config FCMEN = ON            // Fail-Safe Clock Monitor enabled
#pragma config LVP = OFF             // Low Voltage Programming disabled
#pragma config DEBUG = OFF           // In-Circuit Debugger disabled
#pragma config BOR4V = BOR40V        // Brown-out Reset 4.0V
#pragma config WRT = OFF // Flash Program Memory Write Enable bits off

void main() {
  ANSELH = 0; // Configure all pins as digital I/O

  while (1) {
    // C1 to D0 ---------------------------------------
    TRISCbits.TRISC1 = 1; // Set RC1 as input
    TRISDbits.TRISD0 = 0; // Set RD0 as output

    if (PORTCbits.RC1 == 0) {
      PORTDbits.RD0 = 1;
    } else {
      PORTDbits.RD0 = 0;
    }

    // D2 to A2 ---------------------------------------
    TRISDbits.TRISD2 = 1; // Set RD2 as input
    TRISAbits.TRISA2 = 0; // Set RA2 as output

    if (PORTDbits.RD2 == 0) {
      PORTAbits.RA2 = 1;
    } else {
      PORTAbits.RA2 = 0;
    }

    // D7 to B3 ---------------------------------------
    TRISDbits.TRISD7 = 1; // Set RD7 as input
    TRISBbits.TRISB3 = 0; // Set RB3 as output

    if (PORTDbits.RD7 == 0) {
      PORTBbits.RB3 = 1;
    } else {
      PORTBbits.RB3 = 0;
    }
  }
}
