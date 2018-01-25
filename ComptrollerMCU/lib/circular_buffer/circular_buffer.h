#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
//#include "lib/current_sense/current_measurement.h"
// #include <current_sense/current_measurement.h>
// #include <avr/pgmspace.h>


typedef struct {
    uint8_t *buffer;
    uint8_t *head;
    uint8_t *tail;
    uint8_t *last;
    uint16_t currentLen;
    uint16_t maxLen;
} circularBuffer;

void circBufInit(circularBuffer *c, uint16_t size);

uint16_t circBufSpace(circularBuffer *c);
uint16_t circBufCount(circularBuffer *c);
uint16_t circBufCountObjects(circularBuffer *c, uint16_t size);
// uint8_t circBufCountFloat(circBuf_t *c);
// uint8_t circBufCount16(circBuf_t *c);

uint8_t circBufPush(circularBuffer *c, uint8_t data);
uint8_t circBufPop(circularBuffer *c, uint8_t *data);
// int circBufPushFloat(circBuf_t *c, float data);
// int circBufPopFloat(circBuf_t *c, float *data);
// int circBufPush16(circBuf_t *c, uint16_t data);
// int circBufPop16(circBuf_t *c, uint16_t *data);
// int circBufPushCurrentMeasurement(circBuf_t *c, currentMeasurement data);
// int circBufPopCurrentMeasurement(circBuf_t *c, currentMeasurement *data);
// uint8_t circBufCountCurrentMeasurement(circBuf_t *c);
#endif
