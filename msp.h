#ifndef MSP_H
#define MSP_H

// Define the base addresses for the MSP432 peripheral registers

// Port 1 Registers
#define P1DIR   (*(volatile unsigned char *) 0x40004C00)   // Port 1 direction register
#define P1OUT   (*(volatile unsigned char *) 0x40004C02)   // Port 1 output register
#define P1IN    (*(volatile unsigned char *) 0x40004C01)   // Port 1 input register
#define P1SEL0  (*(volatile unsigned char *) 0x40004C04)   // Port 1 function select register 0

// Port 2 Registers
#define P2DIR   (*(volatile unsigned char *) 0x40004C40)   // Port 2 direction register
#define P2OUT   (*(volatile unsigned char *) 0x40004C42)   // Port 2 output register
#define P2IN    (*(volatile unsigned char *) 0x40004C41)   // Port 2 input register
#define P2SEL0  (*(volatile unsigned char *) 0x40004C44)   // Port 2 function select register 0

// EUSCI_A0 Registers (UART)
#define EUSCI_A0_BASE 0x40001000  // Base address for UART (EUSCI_A0)
#define EUSCI_A0_CTLW0 (*(volatile unsigned int *) (EUSCI_A0_BASE + 0x00))  // Control register
#define EUSCI_A0_BRW   (*(volatile unsigned int *) (EUSCI_A0_BASE + 0x06))  // Baud rate register
#define EUSCI_A0_MCTLW (*(volatile unsigned int *) (EUSCI_A0_BASE + 0x08))  // Modulation control register
#define EUSCI_A0_TXBUF (*(volatile unsigned char *) (EUSCI_A0_BASE + 0x02))  // Transmit buffer
#define EUSCI_A0_RXBUF (*(volatile unsigned char *) (EUSCI_A0_BASE + 0x04))  // Receive buffer
#define EUSCI_A0_IFG   (*(volatile unsigned int *) (EUSCI_A0_BASE + 0x0A))  // Interrupt flag register

// Timer A0 Registers
#define TIMER_A0_BASE 0x4000C000  // Base address for Timer_A0
#define TA0CTL  (*(volatile unsigned int *) (TIMER_A0_BASE + 0x00))  // Timer A control register
#define TA0CCTL0 (*(volatile unsigned int *) (TIMER_A0_BASE + 0x02))  // Timer A capture/compare control register 0
#define TA0CCR0 (*(volatile unsigned int *) (TIMER_A0_BASE + 0x04))  // Timer A capture/compare register 0

// Define BIT0 for use with Port 1 and Port 2
#define BIT0 (0x01)

// Function prototypes for UART and motor initialization
void init_uart(void);
void uart_send_char(char c);
char uart_receive_char(void);
void init_motors(void);
void init_additional_pins(void);
void init_timer(void);  // Timer_A initialization for PWM

#endif  // MSP_H
