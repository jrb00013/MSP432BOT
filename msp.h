#ifndef MSP_H
#define MSP_H

#include <stdint.h>  // Use standard integer types

// Define the base addresses for the MSP432 peripheral registers

// Port 1 Registers (32-bit registers)
#define P1DIR   (*(volatile uint32_t *) 0x40004C00)   // Port 1 Direction Register
#define P1OUT   (*(volatile uint32_t *) 0x40004C02)   // Port 1 Output Register
#define P1IN    (*(volatile uint32_t *) 0x40004C01)   // Port 1 Input Register
#define P1SEL0  (*(volatile uint32_t *) 0x40004C04)   // Port 1 Function Select Register 0
#define P1SEL1  (*(volatile uint32_t *) 0x40004C05)   // Port 1 Function Select Register 1

// Port 2 Registers
#define P2DIR   (*(volatile uint32_t *) 0x40004C40)   // Port 2 Direction Register
#define P2OUT   (*(volatile uint32_t *) 0x40004C42)   // Port 2 Output Register
#define P2IN    (*(volatile uint32_t *) 0x40004C41)   // Port 2 Input Register
#define P2SEL0  (*(volatile uint32_t *) 0x40004C44)   // Port 2 Function Select Register 0
#define P2SEL1  (*(volatile uint32_t *) 0x40004C45)   // Port 2 Function Select Register 1

// EUSCI_A0 Registers (UART)
#define EUSCI_A0_BASE  0x40001000  // Base address for UART (EUSCI_A0)
#define EUSCI_A0_CTLW0 (*(volatile uint32_t *) (EUSCI_A0_BASE + 0x00))  // Control register
#define EUSCI_A0_BRW   (*(volatile uint32_t *) (EUSCI_A0_BASE + 0x06))  // Baud rate register
#define EUSCI_A0_MCTLW (*(volatile uint32_t *) (EUSCI_A0_BASE + 0x08))  // Modulation control register
#define EUSCI_A0_TXBUF (*(volatile uint8_t  *) (EUSCI_A0_BASE + 0x02))  // Transmit buffer
#define EUSCI_A0_RXBUF (*(volatile uint8_t  *) (EUSCI_A0_BASE + 0x04))  // Receive buffer
#define EUSCI_A0_IFG   (*(volatile uint32_t *) (EUSCI_A0_BASE + 0x0A))  // Interrupt flag register

// Timer A0 Registers (Used for PWM)
#define TIMER_A0_BASE  0x4000C000  // Base address for Timer_A0
#define TA0CTL   (*(volatile uint32_t *) (TIMER_A0_BASE + 0x00))  // Timer A Control Register
#define TA0CCTL0 (*(volatile uint32_t *) (TIMER_A0_BASE + 0x02))  // Capture/Compare Control Register 0
#define TA0CCR0  (*(volatile uint32_t *) (TIMER_A0_BASE + 0x04))  // Capture/Compare Register 0
#define TA0CCTL1 (*(volatile uint32_t *) (TIMER_A0_BASE + 0x06))  // Capture/Compare Control Register 1 (for PWM)
#define TA0CCR1  (*(volatile uint32_t *) (TIMER_A0_BASE + 0x08))  // Capture/Compare Register 1 (PWM duty cycle)
#define TA0CCTL2 (*(volatile uint32_t *) (TIMER_A0_BASE + 0x0A))  // Capture/Compare Control Register 2 (for PWM)
#define TA0CCR2  (*(volatile uint32_t *) (TIMER_A0_BASE + 0x0C))  // Capture/Compare Register 2 (PWM duty cycle)

// Define bit values for ports
#define BIT0 (0x01)
#define BIT1 (0x02)
#define BIT2 (0x04)
#define BIT3 (0x08)
#define BIT4 (0x10)
#define BIT5 (0x20)
#define BIT6 (0x40)
#define BIT7 (0x80)

// Function prototypes
void init_uart(void);
void uart_send_char(char c);
char uart_receive_char(void);
void init_motors(void);
void init_additional_pins(void);
void init_timer(void);  // Timer_A initialization for PWM

#endif  // MSP_H
