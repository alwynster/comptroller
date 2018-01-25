#include "circular_buffer.h"
// #include "../softuart/softuart.h"
#include <avr/interrupt.h>
// #include <io/interrupts.h>

void circBufInit(circularBuffer *c, uint16_t size)
{
    // allocate buffer
    c->buffer = (uint8_t *) malloc(size);
    if (!c->buffer)
    {
        // debugWriteString("Could not allocate buffer of size ");
        // debugWriteDec16(size);
        // debugNewLine();
    }
    else
    {
        // debugWriteString("allocated buffer at ");
        // debugWriteHex16((uint16_t) c->buffer);
        // init head and tail pointers
        c->head = c->buffer;
        // c->tail = NULL; // cannot immediate pop
        c->tail = c->buffer;
        // c->maxLen = size;
        c->last = c->buffer + size - 1;
        c->currentLen = 0;
        c->maxLen = size;

        // debugWriteString(" to ");
        // debugWriteHex32((uint16_t) c->last);
        // debugNewLine();
    }
}

uint8_t circBufPush(circularBuffer *c, uint8_t data)
{
    uint8_t gi =  SREG & _BV(7);
    
    if (gi)
        cli();

    // check if buffer is full
    if (c->currentLen == c->maxLen) // c->head == c->tail)
    {
        if (gi) sei();
        return 0;
    }

    // store new data
    *c->head = data;
    // // tail is oldest data
    // if (!c->tail)
    //     c->tail = c->head;

    // find pointer for next data
    c->head++;
    // circle around when head passes too far
    if (c->head > c->last)
        c->head = c->buffer;

    // counter for convenience
    c->currentLen++;

    // // next is where head will point to after this write.
    // int next = c->head + 1;
    // if (next >= c->maxLen)
    //     next = 0;

    // if (next == c->tail) // check if circular buffer is full
    // {
    //     sei();
    //     return 0;       // and return with an error.
    // }

    // c->buffer[c->head] = data; // Load data and then move
    // c->head = next;            // head to next data offset.
    // c->currentLen++;

    if (gi) sei();
    return 1;  // return success to indicate successful push.
}

uint8_t circBufPop(circularBuffer *c, uint8_t *data)
{
    // check if available
    if (!c->currentLen)
        return 0;

    uint8_t gi =  SREG & _BV(7);
    
    if (gi)
        cli();
    // data exists
    c->currentLen--;

    // fetch data
    *data = *c->tail;

    // next data
    c->tail++;
    if (c->tail > c->last)
        c->tail = c->buffer;

    if (gi) sei();

    return 1;  // return success to indicate successful pop.
}

uint16_t circBufSpace(circularBuffer *c)
{
    return c->maxLen - c->currentLen;
}

uint16_t circBufCount(circularBuffer *c) { return c->currentLen; }
uint16_t circBufCountObjects(circularBuffer *c, uint16_t size) { return circBufCount(c) / size; }
