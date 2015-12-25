#pragma once
/**
 * clocks.h
 * The Nucleo board has no external clock (HSE) therefore the internal clock is used (HSI)
 * HSI runs at 8MHZ  and derives all other high speed clocks
 */
#include <stdint.h>
   
extern const uint32_t  CLOCK_HSI;

/**
 * Setup the core clock frequencies
 * Enable clocks to all peripherals that are used
 */
void SetupSystemClocks(void);





