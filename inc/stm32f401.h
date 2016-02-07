#pragma once
/**
 * stm32f401.h
 * \brief Contains addresses and layouts of the peripherals used on the STM32F401 by this project
 */
#include <stdint.h>


/**
 * The Core IRQ, the STM32F401 IRQ would be added starting at 0
 * The core IRQs are all negative values - this is a CMSIS method to separate them.
 */
typedef enum 
{
  NonMaskableInt_IRQn         = -14,    /*!< 2 Non Maskable */
  MemoryManagement_IRQn       = -12,    /*!< 4 Memory Management */
  BusFault_IRQn               = -11,    /*!< 5 Bus Fault */
  UsageFault_IRQn             = -10,    /*!< 6 Usage Fault */
  SVCall_IRQn                 = -5,     /*!< 11 SV Call */
  DebugMonitor_IRQn           = -4,     /*!< 12 Debug Monitor */
  PendSV_IRQn                     = -2,     /*!< 14 Pend SV */
  SysTick_IRQn                = -1,     /*!< 15 System Tick */
 
 
  /* The STM32F401 IRQs, see Reference manual, section 10.2 */
  WWDG_IRQn                   = 0,      /*!< Window WatchDog                                         */
  PVD_IRQn                    = 1,      /*!< PVD through EXTI Line detection                         */
  TAMP_STAMP_IRQn             = 2,      /*!< Tamper and TimeStamps through the EXTI line             */
  RTC_WKUP_IRQn               = 3,      /*!< RTC Wakeup through the EXTI line                        */
  FLASH_IRQn                  = 4,      /*!< FLASH global                                            */
  RCC_IRQn                    = 5,      /*!< RCC global                                              */
  EXTI0_IRQn                  = 6,      /*!< EXTI Line0                                              */
  EXTI1_IRQn                  = 7,      /*!< EXTI Line1                                              */
  EXTI2_IRQn                  = 8,      /*!< EXTI Line2                                              */
  EXTI3_IRQn                  = 9,      /*!< EXTI Line3                                              */
  EXTI4_IRQn                  = 10,     /*!< EXTI Line4                                              */
  DMA1_Stream0_IRQn           = 11,     /*!< DMA1 Stream 0 global                                    */
  DMA1_Stream1_IRQn           = 12,     /*!< DMA1 Stream 1 global                                    */
  DMA1_Stream2_IRQn           = 13,     /*!< DMA1 Stream 2 global                                    */
  DMA1_Stream3_IRQn           = 14,     /*!< DMA1 Stream 3 global                                    */
  DMA1_Stream4_IRQn           = 15,     /*!< DMA1 Stream 4 global                                    */
  DMA1_Stream5_IRQn           = 16,     /*!< DMA1 Stream 5 global                                    */
  DMA1_Stream6_IRQn           = 17,     /*!< DMA1 Stream 6 global                                    */
  ADC_IRQn                    = 18,     /*!< ADC1, ADC2 and ADC3 globals                             */
  CAN1_TX_IRQn                = 19,     /*!< CAN1 TX                                                 */
  CAN1_RX0_IRQn               = 20,     /*!< CAN1 RX0                                                */
  CAN1_RX1_IRQn               = 21,     /*!< CAN1 RX1                                                */
  CAN1_SCE_IRQn               = 22,     /*!< CAN1 SCE                                                */
  EXTI9_5_IRQn                = 23,     /*!< External Line[9:5]s                                     */
  TIM1_BRK_TIM9_IRQn          = 24,     /*!< TIM1 Break and TIM9 global                    */
  TIM1_UP_TIM10_IRQn          = 25,     /*!< TIM1 Update and TIM10 global                  */
  TIM1_TRG_COM_TIM11_IRQn     = 26,     /*!< TIM1 Trigger and Commutation and TIM11 global */
  TIM1_CC_IRQn                = 27,     /*!< TIM1 Capture Compare                                    */
  TIM2_IRQn                   = 28,     /*!< TIM2 global                                             */
  TIM3_IRQn                   = 29,     /*!< TIM3 global                                             */
  TIM4_IRQn                   = 30,     /*!< TIM4 global                                             */
  I2C1_EV_IRQn                = 31,     /*!< I2C1 Event                                              */
  I2C1_ER_IRQn                = 32,     /*!< I2C1 Error                                              */
  I2C2_EV_IRQn                = 33,     /*!< I2C2 Event                                              */
  I2C2_ER_IRQn                = 34,     /*!< I2C2 Error                                              */  
  SPI1_IRQn                   = 35,     /*!< SPI1 global                                             */
  SPI2_IRQn                   = 36,     /*!< SPI2 global                                             */
  USART1_IRQn                 = 37,     /*!< USART1 global                                           */
  USART2_IRQn                 = 38,     /*!< USART2 global                                           */
  USART3_IRQn                 = 39,     /*!< USART3 global                                           */
  EXTI15_10_IRQn              = 40,     /*!< External Line[15:10]s                                   */
  RTC_Alarm_IRQn              = 41,     /*!< RTC Alarm (A and B) through EXTI Line                   */
  OTG_FS_WKUP_IRQn            = 42,     /*!< USB OTG FS Wakeup through EXTI line                     */    
  TIM8_BRK_TIM12_IRQn         = 43,     /*!< TIM8 Break and TIM12 global                   */
  TIM8_UP_TIM13_IRQn          = 44,     /*!< TIM8 Update and TIM13 global                  */
  TIM8_TRG_COM_TIM14_IRQn     = 45,     /*!< TIM8 Trigger and Commutation and TIM14 global */
  TIM8_CC_IRQn                = 46,     /*!< TIM8 Capture Compare                                    */
  DMA1_Stream7_IRQn           = 47,     /*!< DMA1 Stream7                                            */
  FSMC_IRQn                   = 48,     /*!< FSMC global                                             */
  SDIO_IRQn                   = 49,     /*!< SDIO global                                             */
  TIM5_IRQn                   = 50,     /*!< TIM5 global                                             */
  SPI3_IRQn                   = 51,     /*!< SPI3 global                                             */
  UART4_IRQn                  = 52,     /*!< UART4 global                                            */
  UART5_IRQn                  = 53,     /*!< UART5 global                                            */
  TIM6_DAC_IRQn               = 54,     /*!< TIM6 global and DAC1&2 underrun error s                 */
  TIM7_IRQn                   = 55,     /*!< TIM7 global                                             */
  DMA2_Stream0_IRQn           = 56,     /*!< DMA2 Stream 0 global                                    */
  DMA2_Stream1_IRQn           = 57,     /*!< DMA2 Stream 1 global                                    */
  DMA2_Stream2_IRQn           = 58,     /*!< DMA2 Stream 2 global                                    */
  DMA2_Stream3_IRQn           = 59,     /*!< DMA2 Stream 3 global                                    */
  DMA2_Stream4_IRQn           = 60,     /*!< DMA2 Stream 4 global                                    */
  ETH_IRQn                    = 61,     /*!< Ethernet global                                         */
  ETH_WKUP_IRQn               = 62,     /*!< Ethernet Wakeup through EXTI line                       */
  CAN2_TX_IRQn                = 63,     /*!< CAN2 TX                                                 */
  CAN2_RX0_IRQn               = 64,     /*!< CAN2 RX0                                                */
  CAN2_RX1_IRQn               = 65,     /*!< CAN2 RX1                                                */
  CAN2_SCE_IRQn               = 66,     /*!< CAN2 SCE                                                */
  OTG_FS_IRQn                 = 67,     /*!< USB OTG FS global                                       */
  DMA2_Stream5_IRQn           = 68,     /*!< DMA2 Stream 5 global                                    */
  DMA2_Stream6_IRQn           = 69,     /*!< DMA2 Stream 6 global                                    */
  DMA2_Stream7_IRQn           = 70,     /*!< DMA2 Stream 7 global                                    */
  USART6_IRQn                 = 71,     /*!< USART6 global                                           */
  I2C3_EV_IRQn                = 72,     /*!< I2C3 event                                              */
  I2C3_ER_IRQn                = 73,     /*!< I2C3 error                                              */
  OTG_HS_EP1_OUT_IRQn         = 74,     /*!< USB OTG HS End Point 1 Out global                       */
  OTG_HS_EP1_IN_IRQn          = 75,     /*!< USB OTG HS End Point 1 In global                        */
  OTG_HS_WKUP_IRQn            = 76,     /*!< USB OTG HS Wakeup through EXTI                          */
  OTG_HS_IRQn                 = 77,     /*!< USB OTG HS global                                       */
  DCMI_IRQn                   = 78,     /*!< DCMI global                                             */
  CRYP_IRQn                   = 79,     /*!< CRYP crypto global                                      */
  HASH_RNG_IRQn               = 80,     /*!< Hash and Rng global                                     */
  FPU_IRQn                    = 81      /*!< FPU global                                              */
} IRQn_Type;

/**
 * The Cortex interrupt controller use a number of bits for the interrupt 
 * priority, which is set by the vendor (in silicon), to 4 in this case.
 * The number of bits used for the 'sub priority' versus 'pre-emption' priority is configurable
 * All bits used for sub-priority is how it is used here, as nested interrupts are not bieng used
 *  See the Cortex description of AIRCR i nthe Cortex-M4 generic user guide, section 4.3.5 
 */
#define     __NVIC_PRIO_BITS        4
#define     __NVIC_PRIORITYGROUP    0x7     

/*
 * This include file requires some types to be define dbefore inclusion 
 * Specifically, IRQn_Type, __NVIC_PRIO_BITS, SysTick_IRQn
 */
#include <core_cm4.h>       /* The CMSIS description of the Corted-M4 core */


/**                                 
* create a few types to lessen clutter
 */
typedef volatile uint32_t   vu32;
typedef volatile uint16_t   vu16;
typedef volatile uint8_t    vu8;

/**
 *  Clocks 
 *  The clocks are setup and controlled in the unit called RCC.   
 * NOTE There are several busses on the STM32F401, the ones control from RCC are
 *      AHB (Advanced High-perfomance Bus)
 *      APB (Advanced Peripheral Bus)
 * To find out which peripheral is on what bus see: the STM32f401 reference manual, section 2.3 Memory Map
 */
typedef struct 
{
  vu32  CR;             /*!< Control register */
  vu32  PLLCFGR;        /*!< PLL Configuration */
  vu32  CFGR;           /*!<  */
  vu32  CIR;            /*!<  */
  
  /*!< Peripheral Resets*/
  vu32  AHB1RSTR;
  vu32  AHB2RSTR;
  vu32  AHB3RSTR;
  vu32  Rsvd0;
  
  vu32  APB1RSTR;
  vu32  APB2RSTR;  
  vu32  Rsvd1[2];
  
  /*!<  Clock enable registers */
  vu32  AHB1ENR;
  vu32  AHB2ENR;
  vu32  AHB3ENR;
  vu32  Rsvd2;
  
  vu32  APB1ENR;
  vu32  APB2ENR;  
  vu32  Rsvd3[2]; 
  
  /*!< Clock enable in low power mode registers */
  vu32  AHB1LPENR;
  vu32  AHB2LPENR;
  vu32  AHB3LPENR;
  vu32  Rsvd4;
  
  vu32  APB1LPENR;
  vu32  APB2LPENR;
  vu32  Rsvd5[2]; 
  
  
  vu32  BDCR;       /*!< Backup Domain control*/
  vu32  CSR;        /*!< Clock control and status */
  vu32  Rsvd6[2]; 
  
  vu32  SSCGR;      /*!<  Spread Spectrum clock generation */
  vu32  PLLI2SCFGR; /*!<  I2S PLL configuration */
  vu32  DCKCFGR;    /*!<  Dedicated clocks config */
  
} Rcc_t;

typedef struct 
{
  vu32      CR;     /*!< power control */
  vu32      CSR;    /*!< power control/status */  
} Pwr_t;

/**
 * GPIO
 * The GPIO module also sets up the pin multiplex 
 * There are 16 GPIOs per block
 */
typedef struct 
{
  vu32  MODER;          /*!< select input/output/alt func/analog */
  vu32  OTYPER;         /*!< push pull versus open drain */
  vu32  OSPEEDR;        /*!< low/medium/fast/high - changes response of GPIO */
  vu32  PUPDR;          /*!< float/pull up/pull down */
  vu32  IDR;            /*!< Read pin states */
  vu32  ODR;            /*!< Set the output pin states*/
  vu32  BSRR;           /*!< Atomically set/clear pin states */
  vu32  LCKR;           /*!< Used to prevent configuration changes to the GPIO setup */
  vu32  AFRL;           /*!< 1 of 2 registers that setup the alternate function selection when mode is alt func */
  vu32  AFRH;           /*!< 1 of 2 registers that setup the alternate function selection when mode is alt func */
} Gpio_t;

/**
 * External Interrupt Controller
 * This blocks configures interrupts from external sources, the GPIO for instance.
 * the NVIC is define in the core.
 */
typedef struct 
{   
  vu32  IMR;            /*!< Interrupt mask */
  vu32  EMR;            /*!< Event mask */
  vu32  RTSR;           /*!< Rising trigger selection*/
  vu32  FTSR;           /*!< Falling trigger selection */
  vu32  SWIER;          /*!< Software interrupt event register */
  vu32  PR;             /*!< Pending register */  
} Exti_t;

typedef struct
{
  vu32 MEMRMP;          /*!< memory remap */
  vu32 PMC;             /*!< peripheral mode configuration */
  vu32 EXTICR[4];       /*!< external interrupt configuration */
  vu32 Rsvd[2];
  vu32 CMPCR;           /*!< Compensation cell control */
} Syscfg_t;

/**
 * Memory Map
 * See the stm32f401 datasheet, section 5
 */
#define APB1_BASE               0x40000000
#define APB2_BASE               0x40010000
#define AHB1_BASE               0x40020000
#define AHB2_BASE               0x50000000
#define CORTEXM4_INTERNALS      0xE0000000

#define GPIOA                   ((Gpio_t*)(AHB1_BASE + 0x0000))
#define GPIOB                   ((Gpio_t*)(AHB1_BASE + 0x0400))
#define GPIOC                   ((Gpio_t*)(AHB1_BASE + 0x0800))
#define GPIOD                   ((Gpio_t*)(AHB1_BASE + 0x0C00))
#define GPIOE                   ((Gpio_t*)(AHB1_BASE + 0x1000))
#define GPIOH                   ((Gpio_t*)(AHB1_BASE + 0x1C00))
#define RCC                     ((Rcc_t*)(AHB1_BASE + 0x3800))

#define SYSCFG                  ((Syscfg_t*)(APB2_BASE + 0x3800))
#define EXTI                    ((Exti_t*)(APB2_BASE + 0x3C00))
#define PWR                     ((Pwr_t*)(APB1_BASE + 0x7000))



/* GPIO register bits */
#define GPIO_MODER_INPUT        0x0
#define GPIO_MODER_OUTPUT       0x1
#define GPIO_MODER_ALTFUNC      0x2
#define GPIO_MODER_ANALOG       0x3
#define GPIO_MODER_MASK         0x3

/* Helper macro to correctly shift the mode mask */
#define GPIO_MODER_SET(pin,mode) (mode << (pin*2))

#define GPIO_OTYPER_PP          0
#define GPIO_OTYPER_OD          1
#define GPIO_OTYPER_MASK        1
/* Helper macro to correctly shift the Output typemask */
#define GPIO_OTYPER_SET(pin,mode) (mode << (pin))

#define GPIO_PUPDR_NONE         0
#define GPIO_PUPDR_PU           1
#define GPIO_PUPDR_PD           2
#define GPIO_PUPDR_MASK         3

/* Helper macro to correctly shift the Pull up/down mask */
#define GPIO_PUPDR_SET(pin,mode) (mode << (pin*2))



/* RCC register bits */
#define RCC_AHB1ENR_GPIOAEN            (1<<0)
#define RCC_AHB1ENR_GPIOBEN            (1<<1)
#define RCC_AHB1ENR_GPIOCEN            (1<<2)
#define RCC_AHB1ENR_GPIODEN            (1<<3)
#define RCC_AHB1ENR_GPIOEEN            (1<<4)

#define RCC_APB1ENR_PWREN              (1<<28)
#define RCC_APB2ENR_SYSCFGEN           (1<<14)

/* Syscfg bits*/
#define SYSCFG_EXTICR_PA                (0x0)
#define SYSCFG_EXTICR_PB                (0x1)
#define SYSCFG_EXTICR_PC                (0x2)
#define SYSCFG_EXTICR_PD                (0x3)
#define SYSCFG_EXTICR_PE                (0x4)
#define SYSCFG_EXTICR_PH                (0x7)
