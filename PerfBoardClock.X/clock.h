/* 
 * File:   clock.h
 * Author: Projects
 *
 * Created on December 11, 2023, 8:10 PM
 */

#ifndef CLOCK_H
#define	CLOCK_H

typedef uint8_t Uint8;
typedef uint32_t Uint32;

// Time of day Builder. Determines the time based on timer 0
Uint32 TOD(Uint32 time_of_day, Uint8 T_Tick);

// Takes the time of day and represents the tens and ones place of Hours and Minutes for the Renderer to output to the display
Uint8 Clock_Out(Uint32 time_of_day);

// Rotary Encoder. Takes input from the rotary encoder to reset the clock
Uint32 RotaryEncoder(Uint8 L_Turn, Uint8 R_Turn, Uint8 Click, Uint32 CurrentTime);

#endif	/* CLOCK_H */

