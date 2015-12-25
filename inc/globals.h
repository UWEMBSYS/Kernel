#pragma once
/**
 * globals.h
 * Global variables and their accessors are prototyped here
 */
#include <stdint.h>

/*!<  The current mS tick count */
uint32_t GetCurrentTick();
extern volatile uint32_t    CurrentTick;

/*!< IRQ Sets this to the tick count for when the LED should be turned off */
extern volatile uint32_t    LEDOffTickCount;