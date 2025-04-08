#ifndef UART_H
#define UART_H

void init_uart(void);
void uart_send_char(char c);
char uart_receive_char(void);

#endif // UART_H
