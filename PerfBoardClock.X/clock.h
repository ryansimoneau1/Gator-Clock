/* 
 * File:   clock.h
 * Author: Projects
 *
 * Created on December 11, 2023, 8:10 PM
 */

#ifndef CLOCK_H
#define	CLOCK_H

#include <stdint.h>

typedef uint8_t Uint8;
typedef uint32_t Uint32;

typedef struct Clock{
    Uint8 Hours;
    Uint8 Minutes;
} Clock;

extern Clock time_of_day;

// Determines the time based on timer 0
void TOD(Clock *Time_Of_Day);


// Rotary Encoder. Takes input from the rotary encoder to modify the clock
Uint32 RotaryEncoder(Uint8 L_Turn, Uint8 R_Turn, Uint8 Click, Uint32 CurrentTime);

#endif	/* CLOCK_H */

