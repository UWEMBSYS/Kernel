/**
 * pinmux.c
 * Setup the pin modes for the modules used 
 */
#include <nucleoboard.h>


void SetupPinmux()
{
  Gpio_t* gpio;
  
  /* Set the User Button to be an input, there is an external pull up */
  gpio = GPIO_BLOCK_USER_BUTTON;
  gpio->MODER &= ~GPIO_MODER_SET(GPIO_PIN_USER_BUTTON, GPIO_MODER_MASK);    
  gpio->MODER |= GPIO_MODER_SET(GPIO_PIN_USER_BUTTON, GPIO_MODER_INPUT);   
  
  gpio->PUPDR &=  ~GPIO_PUPDR_SET(GPIO_PIN_USER_BUTTON, GPIO_PUPDR_MASK); 
  gpio->PUPDR |=  ~GPIO_PUPDR_SET(GPIO_PIN_USER_BUTTON, GPIO_PUPDR_NONE); 

  /* Set the LED to be an output, Push Pull */
  gpio = GPIO_BLOCK_LD2;
  gpio->MODER &= ~GPIO_MODER_SET(GPIO_PIN_LD2, GPIO_MODER_OUTPUT);    
  gpio->MODER |= GPIO_MODER_SET(GPIO_PIN_LD2, GPIO_MODER_OUTPUT);   

 
  gpio->OTYPER &= ~GPIO_OTYPER_SET(GPIO_PIN_LD2, GPIO_OTYPER_MASK);
  gpio->OTYPER |= GPIO_OTYPER_SET(GPIO_PIN_LD2, GPIO_OTYPER_PP);
  
}