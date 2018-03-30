#include <avr/io.h>
#include "uart.h"
#include <stdio.h>
#include <avr/interrupt.h>
#include <circular_buffer/circular_buffer.h>
//#include "lib/circular_buffer/circular_buffer.h"
//#include "../softuart/softuart.h"
// #include <softuart/softuart.h>
// #include <../main.h>

void uartWriteBin(uint32_t num, uint8_t length);
void (*uartReceiveHandler)(uint8_t);
// circBuf_t sendingBuf;
circularBuffer sendingBuf;
// CIRCBUF_DEF(sendingBuf, UART_SENDING_BUFFER);

uint8_t sendingData;
uint8_t sendingFlag;

volatile uint8_t receivedData;

void printUartHandler(void)
{
// 	debugWriteString("Uart Handler: ");
// // 	debugWriteHex16((uint16_t) (sendingBuf.head));
// // 	debugWriteChar(' ');
// // 	debugWriteHex16((uint16_t) (sendingBuf.last));
// // 	debugWriteChar(' ');

// 	debugWriteHex32((uint16_t) (uartReceiveHandler));
// 	debugWriteChar(' ');
// 	debugWriteHex8(UCSR0B);
// 	debugWriteChar(' ');
// 	debugWriteDec8((SREG & _BV(7)) != 0);
// 	debugNewLine();
	

// 	debugWriteHex32((uint32_t) (&uartReceiveHandler));
// 	debugWriteChar(' ');

// 	return 0;
// 	// return (uint16_t) uartReceiveHandler;
}

// void setHandler(void (*receiveHandler)(uint8_t))
// {
// 	// debugWriteLine("CHANGING HANDLER");
// 	// uartReceiveHandler = receiveHandler;
// }

void uartInit(void (*receiveHandler)(uint8_t))
{
	UBRR0H = (uint8_t) (my_bdr >> 8);
	UBRR0L = (uint8_t) (my_bdr);
#if UART_2X
	UCSR0A |= _BV(U2X0);
#endif
	UCSR0B = _BV(RXEN0) | _BV(TXEN0) | _BV(TXCIE0); // disabled interrupts for uart: | _BV(RXCIE0) | _BV(TXCIE0);
	UCSR0C = _BV(USBS0) | (3 << UCSZ00);

	uartReceiveHandler = receiveHandler;

	sendingFlag = 0x0;

	circBufInit(&sendingBuf, UART_SENDING_BUFFER);

	sei();
}

// is uart sending interface busy?
uint8_t uartSending(void)
{
	return sendingFlag;
}

void uartNewLine(void)
{
	// uartWriteChar('\r');
	uartWriteChar('\n');
}

void uartWriteLine(char *s)
{
	uartWriteString(s);

	uartNewLine();
}

void uartWriteString(char *s)
{
	while (*s != 0)
		uartQueue(*(s++));
	uartWriteNext();
}

void uartWriteStringLength(char *s, uint8_t length)
{
	uint8_t i;
	for (i = 0; i < length; i++)
		uartQueue(s[i]);
	uartWriteNext();
}

uint8_t uartAvailable(void)
{
	return ( UCSR0A & _BV(RXC0)) != 0;
}

// remember to clear interrupts
uint8_t uartReceiveCharBlocking()
{
	cli();
	/* Wait for finished receive */
	while (!( UCSR0A & _BV(RXC0)))
		;

	sei();

	return UDR0;
}

uint32_t output = 0;
// remember to clear interrupts
void uartReceiveUint32Blocking(uint32_t *output)
{
	cli();
	uint8_t *outputPtr = (uint8_t *) output;

	*outputPtr++ = uartReceiveCharBlocking();
	*outputPtr++ = uartReceiveCharBlocking();
	*outputPtr++ = uartReceiveCharBlocking();
	*outputPtr++ = uartReceiveCharBlocking();

	sei();
	// return output;
}

void uartWriteCharBlock(uint8_t c)
{
	cli();
	while (!( UCSR0A & _BV(UDRE0)))
		;

	/* Put data into buffer, sends the data */
	UDR0 = c;
	// while ( !( UCSR0A & _BV(UDRE0)) );
	sei();
}

void uartWriteNext(void)
{
	if (!sendingFlag)
	{
		/* Wait for empty transmit buffer */
		while (!( UCSR0A & _BV(UDRE0)))
			;
		circBufPop(&sendingBuf, &sendingData);
		UDR0 = sendingData;
		sendingFlag = 0x1;
		// setLed(0, 1);
	}
}

uint8_t uartQueue(uint8_t c)
{
	return circBufPush(&sendingBuf, c);
}

// ignore extra parameter used for flash readback
void uartWriteCharHelper(uint8_t c, uint8_t last)
{
	uartWriteChar(c);
}

void uartWriteChar(uint8_t c)
{
	// debugWriteString("writing: ");
	// debugWriteChar(c);
	// debugNewLine();

	// if not sending yet, start process
	// if (!sendingFlag)
	// {

	// }
	// otherwise leave it in buffer for later
	// else
	// {
	// if there's space in the buffer, sending
	if (circBufPush(&sendingBuf, c))
	{
		// check if sending already
		if (!sendingFlag)
			// start process
			uartWriteNext();

		sendingFlag = 0x1;
	}
	// }

}

void uartAck(uint8_t c)
{
	uartWriteChar(c);
	// uartWriteCharBlock(c);
}

void uartWriteHex8(uint8_t num)
{
	char buf[3];
	sprintf(buf, "%02X", num);
	uartWriteString(buf);
}

void uartWriteDec8(uint8_t num)
{
	char buf[4];
	sprintf(buf, "%d", num);
	uartWriteString(buf);
}

void uartWriteDec16(uint16_t num)
{
	char buf[20];
	sprintf(buf, "%u", num);
	uartWriteString(buf);
}

void uartWriteDec32(uint32_t num)
{
	char buf[20];
	sprintf(buf, "%lu", num);
	uartWriteString(buf);
}

void uartWriteBin8(uint8_t num)
{
	uartWriteBin(num, 8);
}

void uartWriteHex16(uint16_t num)
{
	char buf[10];
	sprintf(buf, "%04X", num);
	uartWriteString(buf);
}

void uartWriteHex32(uint32_t num)
{
	char buf[10];
	sprintf(buf, "%08lX", num);
	uartWriteString(buf);
}

void uartWriteBin32(uint32_t num)
{
	uartWriteBin(num, 32);
}

void uartWriteBin4(uint8_t num)
{
	uartWriteBin(num, 4);
}

void uartWriteBin(uint32_t num, uint8_t length)
{
	uartWriteString("0b");
	int i;
	uint32_t number = num;
	for (i = length - 1; i >= 0; i--)
	{
		if (number & _BV(i))
			uartWriteChar('1');
		else
			uartWriteChar('0');
		// number >>= 1;
	}
}

void uartWriteFloat(float num)
{
	char buf[10];
	sprintf(buf, "%.2f", num);
	uartWriteString(buf);
}

ISR(USART_RX_vect)
{
	cli();
	// debugNewLine();
	
	// debugWriteLine("USART0_RX_vect");

	receivedData = UDR0;
	uartReceiveHandler(receivedData);
	// debugWriteChar(UDR0);

	// debugWriteLine("/USART0_RX_vect");

	sei();
}

ISR(USART_TX_vect)
{
	cli();
	// debugWriteLine("USART0_TX_vect");

	// check if more data to send
	if (circBufPop(&sendingBuf, &sendingData))
		// if avail, send it
		UDR0 = sendingData;
	else
	{
		sendingFlag = 0x0;
		// setLed(0, 0);

		// debugWriteLine("buffer empty");

	}

	sei();
	// debugWriteLine("/USART0_TX_vect");
}
