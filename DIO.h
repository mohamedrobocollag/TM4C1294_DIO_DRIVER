#ifndef  DIO_H_
#define  DIO_H_

#include <stdint.h>
#include "TM4C1294NCPDT.h"

#define  PORTA GPIOA_AHB
#define  PORTB GPIOB_AHB
#define  PORTC GPIOC_AHB
#define  PORTD GPIOD_AHB
#define  PORTE GPIOE_AHB
#define  PORTF GPIOF_AHB
#define  PORTG GPIOG_AHB
#define  PORTH GPIOH_AHB
#define  PORTJ GPIOJ_AHB
#define  PORTK GPIOK
#define  PORTL GPIOL
#define  PORTM GPIOM
#define  PORTN GPION
#define  PORTP GPIOP
#define  PORTQ GPIOQ

typedef enum
{
    PIN_INPUT  =0,
    PIN_OUTPUT =1
}DIRECTION_T;

typedef enum
{
  Pull_up   =0,
  pull_down =1
}PULLED_T;

typedef struct 
{
   GPIOA_AHB_Type*        port;
    uint8_t               pin;
    DIRECTION_T           direction;
    PULLED_T              pull_resistor;
}PIN_INIT_T;

void vGPIO_Pin_Init(PIN_INIT_T const*);


#define vGPIO_Pin_Set(config)     ( ((config.port)->DATA) |= (1<<config.pin) )
#define vGPIO_Pin_Reset(config)   ( ((config.port)->DATA) &=~ (1<<config.pin) )
#define vGPIO_Pin_Toggle(config)  ( ((config.port)->DATA) ^= (1<<config.pin) )
#define u8GPIO_Pin_Read(config)   ( (((config.port)->DATA)&(1<<config.pin))?  ((uint8_t)1)  : ((uint8_t)0)  )



#endif


