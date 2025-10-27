/**
 * @file main.c
 * @author fermeridamagni
 * @date 2025-09-24
 * @description Get the analogic value from the bit AN0 in the PIC16F887 and control PORTB LEDs based on the value.
 */

#include <pic16f887.h> // Include the specific header for PIC16F887
#include <xc.h>

// Define the system frequency for delay functions
#define _XTAL_FREQ 8000000 // 8MHz internal oscillator

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

// Function to read ADC value
unsigned int ADC_Read(void) {
  __delay_us(20);          // Acquisition time delay
  ADCON0bits.GO_nDONE = 1; // Start conversion
  while (ADCON0bits.GO_nDONE)
    ;                              // Wait for conversion to complete
  return ((ADRESH << 8) + ADRESL); // Return 10-bit result
}

void main() {
  // Configure analog input pin
  ANSELbits.ANS0 = 1;   // Set RA0 (AN0) as analog
  TRISAbits.TRISA0 = 1; // Set RA0 (AN0) as input

  // Configure ADC module
  ADCON0bits.ADCS = 0b10;  // ADC clock = FOSC/32 (for 8MHz)
  ADCON0bits.CHS = 0b0000; // Select channel AN0
  ADCON0bits.ADON = 1;     // Turn on ADC module

  ADCON1bits.ADFM = 1;  // Right justify result (10-bit)
  ADCON1bits.VCFG0 = 0; // Use VDD as positive reference
  ADCON1bits.VCFG1 = 0; // Use VSS as negative reference

  // Output digital pins
  TRISBbits.TRISB0 = 0; // Set RB0 as output
  TRISBbits.TRISB1 = 0; // Set RB1 as output
  TRISBbits.TRISB2 = 0; // Set RB2 as output
  TRISBbits.TRISB3 = 0; // Set RB3 as output
  TRISBbits.TRISB4 = 0; // Set RB4 as output
  TRISBbits.TRISB5 = 0; // Set RB5 as output
  TRISBbits.TRISB6 = 0; // Set RB6 as output
  TRISBbits.TRISB7 = 0; // Set RB7 as output

  // Main loop
  while (1) {
    unsigned int adc_value = ADC_Read(); // Read ADC value once per loop

    if (adc_value >= 128) {
      PORTBbits.RB0 = 1; // Set RB0 high
    } else {
      PORTBbits.RB0 = 0; // Set RB0 low
    }

    if (adc_value >= 256) {
      PORTBbits.RB1 = 1; // Set RB1 high
    } else {
      PORTBbits.RB1 = 0; // Set RB1 low
    }

    if (adc_value >= 384) {
      PORTBbits.RB2 = 1; // Set RB2 high
    } else {
      PORTBbits.RB2 = 0; // Set RB2 low
    }

    if (adc_value >= 512) {
      PORTBbits.RB3 = 1; // Set RB3 high
    } else {
      PORTBbits.RB3 = 0; // Set RB3 low
    }

    if (adc_value <= 640) {
      PORTBbits.RB4 = 1; // Set RB4 high
    } else {
      PORTBbits.RB4 = 0; // Set RB4 low
    }

    if (adc_value <= 768) {
      PORTBbits.RB5 = 1; // Set RB5 high
    } else {
      PORTBbits.RB5 = 0; // Set RB5 low
    }

    if (adc_value <= 896) {
      PORTBbits.RB6 = 1; // Set RB6 high
    } else {
      PORTBbits.RB6 = 0; // Set RB6 low
    }

    if (adc_value <= 1023) {
      PORTBbits.RB7 = 1; // Set RB7 high
    } else {
      PORTBbits.RB7 = 0; // Set RB7 low
    }

    // Small delay to prevent excessive ADC reading rate
    __delay_ms(10);
  }
}
