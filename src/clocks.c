/**
 * clocks.c
 * Setup the system clocks to the used peripherals
 *
 */
#include <stm32f401.h>
#include <clocks.h>

const uint32_t CLOCK_HSI =  16000000;

/**
 * Clock fan out is not well documented, see stm32f401 reference manual, section 6.2 
 * Examine how HSI gets to the GPIO block (GPIO is on AHB1)
 * see section 6.2.6
 * The system can switch to the PLL to go faster, see PLLCFGR, 6.3.2
 * There is no need for that here, so leave SYSCLK == HSI
 * Leave AHB1 == SYSCLK (PPRE2 = 0)
 */
void SetupSystemClocks(void)
{
    uint32_t reg;
     
    /* Enable used clocks, see 6.3.9 */
    reg = RCC->APB1ENR;
    reg |= RCC_APB1ENR_PWREN;
    RCC->APB1ENR = reg;    
    
    reg= RCC->AHB1ENR;
    reg |= RCC_AHB1ENR_GPIOAEN|RCC_AHB1ENR_GPIOBEN|RCC_AHB1ENR_GPIOCEN|RCC_AHB1ENR_GPIODEN|RCC_AHB1ENR_GPIOEEN;
    RCC->AHB1ENR = reg;
    
    reg= RCC->APB2ENR;
    reg |= RCC_APB2ENR_SYSCFGEN;
    RCC->APB2ENR = reg;
    

}
