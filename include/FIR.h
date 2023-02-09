#ifndef FIR_FILTER_H
#define FIR_FILTER_H

// This is a bit overkill but saves writing out all the headers either in this file or another header to import here
#include <bits/stdc++.h>

// #define FIR_FILTER_LENGTH 5
#define FIR_FILTER_LENGTH 10

// Defining the struct to represent the circular buffer
typedef struct
{
    float buff[FIR_FILTER_LENGTH]; // For circular buffer array
    uint8_t buffIndex;             // Tracking the index of the circular buffer
    float out;                     // The output value of the circular buffer
} FIRFilter;

// Functions Prototypes
void FIRFilter_init(FIRFilter *fir);
float FIRFilter_calc(FIRFilter *fir, float inputVal);

#endif