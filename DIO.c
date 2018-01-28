#include "DIO.h"
#include "TM4C1294NCPDT.h"




void vGPIO_Pin_Init( PIN_INIT_T const* config_ptr)
{
  //clock gating 
  SYSCTL->RCGCGPIO |=(1<<(((unsigned long)(config_ptr->port)-(unsigned long)PORTA)>>12));
  int x =(unsigned long)(config_ptr->port)-(unsigned long)PORTA;
  //digital enable
  (config_ptr->port)->DEN |=(1<<config_ptr->pin);
  //port direction
  if(config_ptr->direction == PIN_INPUT)
    (config_ptr->port)->DIR &=~(1<<config_ptr->pin);
  else
    (config_ptr->port)->DIR |=(1<<config_ptr->pin);
  //pullup or pull down
  if(config_ptr->pull_resistor == Pull_up)
   (config_ptr->port)->PUR |=(1<<config_ptr->pin);
  else
   (config_ptr->port)->PDR |=(1<<config_ptr->pin);
   x++;
}

