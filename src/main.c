/**
 * main.c
 * The usual main() This one is a simple loop that will never return.
 */
#include <nucleoboard.h>
#include <stdlib.h>
#include <stdint.h>
#include <globals.h>
#include <clocks.h>
#include <pinmux.h>
#include <interrupts.h>

/*
 * These variables should be initialized during the startup sequence
 */
volatile uint16_t    InitializedVariable16 = 0x1234;
volatile uint32_t    InitializedVariable32 = 0xABCD5678;   


/* 
 * These variables should be zero initialized during startup
 */
volatile uint64_t    ZeroInitializedVariable;
volatile uint16_t    ZeroInitializedVariable16;
volatile uint32_t    ZeroInitializedVariable32;



/*
 * Time that LED should stay on after button press, mS
 */
uint32_t    LEDOnPeriodmS   = 2000;


int main()
{
  
  /* Setup clocks first, unclocked modules will case the system to lockup the bus if accessed */
  SetupSystemClocks();
  
  /* Configure Pin Mux */
  SetupPinmux();
  
  /* Start processing interrupts */
  SetupInterrupts();

  
  /* 
   * Task: 
   * Look at the initialized variables in the debugger to verify that they were 
   * genuinely set to their assigned values
  * NOTE: They are listed below the prevent the linker from optimizing them away
   */
  InitializedVariable16;
  InitializedVariable32;
  ZeroInitializedVariable;
  ZeroInitializedVariable16;
  ZeroInitializedVariable32;
  
 
  
  /* This loop exists to prevent the compiler from removing the variables */
  while (1) {

    /* 
     * LEDOffTickCount is set in the IRQ Handler for the user button (interrupts.c, EXTI10Thru15IrqHandler)
     * to a value some time in the future.
     * Turn the LED off if that period has lapsed.
     */
    if (LEDOffTickCount < GetCurrentTick()) {
      /* If the LED is on, turn it off */
      if (GPIO_BLOCK_LD2->ODR & (1 << GPIO_PIN_LD2) ) {
        /* The high 16 bits of BSRR reset the pin */
        GPIO_BLOCK_LD2->BSRR = (1 << GPIO_PIN_LD2) << 16 ;
      }
    }
           
  }
  
  
  /* main should never actually return in this case */


}