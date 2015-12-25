#include <globals.h>

volatile uint32_t CurrentTick = 0;
uint32_t GetCurrentTick() 
{
  return CurrentTick;
}

volatile uint32_t LEDOffTickCount = 0;