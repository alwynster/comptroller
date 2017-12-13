#ifndef UART_H
#define UART_H

// #include <io/leds.h>
//#include "lib/io/leds.h"

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

#define baud 9600 // 250000
#define UART_2X 0
#if UART_2X
#define my_bdr ((F_CPU / 8 / (baud)) - 1)
#else
#define my_bdr ((F_CPU / 16 / (baud)) - 1)
#endif
#define UART_SENDING_BUFFER 1024
// #define my_bdr 0

void printUartHandler(void);

// void setHandler(void (*receiveHandler)(uint8_t));

void uartInit(void (*receiveHandler)(uint8_t));
uint8_t uartSending(void);
void uartNewLine(void);
void uartWriteLine(char *s);
void uartWriteString(char *s);

void uartWriteNext(void);
uint8_t uartQueue(uint8_t c);

void uartWriteStringLength(char *s, uint8_t length);
uint8_t uartReceiveCharBlocking(void);
void uartReceiveUint32Blocking(uint32_t *output);
void uartWriteCharHelper(uint8_t c, uint8_t last);
void uartWriteChar(uint8_t c);
void uartWriteCharBlock(uint8_t c);
void uartWriteHex8(uint8_t num);
void uartWriteDec8(uint8_t num);
void uartWriteBin8(uint8_t num);
void uartWriteDec16(uint16_t num);
void uartWriteHex16(uint16_t num);
void uartWriteHex32(uint32_t num);
void uartWriteBin32(uint32_t num);
void uartWriteDec32(uint32_t num);
void uartWriteBin4(uint8_t num);
void uartWriteFloat(float num);
void uartAck(uint8_t c);
#endif
