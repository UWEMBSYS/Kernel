/**
 * interrupts.c
 * Setup the interrupt controller and the external interrupt lines
 */
#include <nucleoboard.h>
#include <interrupts.h>
#include <globals.h>
#include <clocks.h>



/**
 * Setup the NVIC and EXTI
 * Use CMSIS macros to do the bit swizzling and register accesses
 * Enable some interrupts
 * - The Systick Irq 
 * - The GPIO  for the User Button, which is on GPIO line GPIO_PIN_USER_BUTTON (AKA 13)
 */
void SetupInterrupts(void)
{
  NVIC_SetPriorityGrouping(__NVIC_PRIORITYGROUP);
  
  uint32_t preemptLevel = 0;
  uint32_t subPri  = 0;
  
  uint32_t pri = NVIC_EncodePriority(NVIC_GetPriorityGrouping(), preemptLevel, subPri);  
  NVIC_SetPriority(SysTick_IRQn, pri);  
  
  
  /**
   * Enable Systick IRQ, in this example code HSI is used for system clock
   * To verify that see RCC_CFGR register, SWS bits 
   * This funciton will enable the system tick interrupt
   */  
  SysTick_Config(CLOCK_HSI / 1000);
  
  /**
   * Enable the interrupt in the external interrupt controller
   * See ref manual, 10.2.1
   * - Select the  EXTICR register for this GPIO Pin number (4 bits per pin so / by 4)
   * - Select the GPIO Block as that interrupt source 
   * In the EXTI 
   * - Select Rising Edge as the trigger
   * - Enable the source in the External mask interrupt register
   */
  uint32_t reg = SYSCFG->EXTICR[GPIO_PIN_USER_BUTTON / 4 ];
  reg &= ~(0xf << ((GPIO_PIN_USER_BUTTON % 4) * 4));

  /* Select the correct GPIO block as the source */
  uint32_t gpioBlock=0;
  if (GPIOC == GPIO_BLOCK_USER_BUTTON) 
  {
    gpioBlock = SYSCFG_EXTICR_PC;
  } /* add other clauses for other GPIO blocks */
  
  
  reg |= gpioBlock << ((GPIO_PIN_USER_BUTTON % 4) * 4);
  SYSCFG->EXTICR[GPIO_PIN_USER_BUTTON / 4 ] = reg;
  
  
  EXTI->RTSR |= 1 << GPIO_PIN_USER_BUTTON;      /* Select Rising edge trigger */
  EXTI->IMR |= 1 << GPIO_PIN_USER_BUTTON;       /* Enable the interrupt at EXTI */
  
  /**
   * Enable the external interrupt at the NVIC
   */
  NVIC_SetPriority(EXTI15_10_IRQn, pri); 
  NVIC_EnableIRQ(EXTI15_10_IRQn);
  
}


/**
 * Add interrupt handlers for Systick and GPIO
 * GPIO is part of the EXTI block
 * These will override the weak linkages specified in the startup.s file
 */
void SysTickIrqHandler(void)
{
    ++CurrentTick;
}

/**
 * The handler for the User button (and potentially other sources)
 */
void EXTI10Thru15IrqHandler(void)
{
  /* Look for pending interrupt in the external interrupt pending register */
  if (EXTI->PR & (1 << GPIO_PIN_USER_BUTTON) ) {
    
    /* External interrupt detected for the correct pin, ack the IRQ */
    EXTI->PR = (1 << GPIO_PIN_USER_BUTTON);     
    /* There is no need to acknolwedge the interrupt at the NVIC ICPR register as the interrupt source 
     * was removed  by the EXTI
     * CMSIS: NVIC_ClearPendingIRQ would be called if this were not the case
     */   
    
    LEDOffTickCount = 2000 + GetCurrentTick();
    /* The low 16 bits of BSRR set the GPIO pin */
    GPIO_BLOCK_LD2->BSRR = (1 << GPIO_PIN_LD2);
  } else {
    /* Spurious irq, how did this happen, no other sources are enabled???? */
    NVIC_ClearPendingIRQ(EXTI15_10_IRQn);
  }
}

