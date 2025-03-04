#include "msp.h"

void init_uart(void) {
    // Set up UART for communication with the PC
    P1SEL0 |= BIT0 | BIT1;  // Set pins 1.0 and 1.1 for UART TX/RX
    EUSCI_A0->CTLW0 = EUSCI_B_CTLW0_SWRST;  // Put eUSCI in reset
    EUSCI_A0->CTLW0 = EUSCI_B_CTLW0_UCPEN | EUSCI_B_CTLW0_UCMODE_0;  // Set UART mode
    EUSCI_A0->BRW = 6;  // Set baud rate
    EUSCI_A0->MCTLW = 0;  // Set modulation
    EUSCI_A0->CTLW0 &= ~EUSCI_B_CTLW0_SWRST;  // Release from reset
}

// Function to send a character over UART
void uart_send_char(char c) {
    while (!(EUSCI_A0->IFG & EUSCI_A_IFG_TXBUF)) {
        // Wait for TX buffer to be ready
    }
    EUSCI_A0->TXBUF = c;  // Send character
}

// Function to receive a character from UART
char uart_receive_char(void) {
    while (!(EUSCI_A0->IFG & EUSCI_A_IFG_RXBUF)) {
        // Wait for RX buffer to be ready
    }
    return EUSCI_A0->RXBUF;  // Return received character
}
