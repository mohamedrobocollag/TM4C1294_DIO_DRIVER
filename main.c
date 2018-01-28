#include "TM4C1294NCPDT.h"
#include "DIO.H"

extern const PIN_INIT_T LED;
extern const PIN_INIT_T PUSH;

int main()
{

  vGPIO_Pin_Init(&LED);
  vGPIO_Pin_Init(&PUSH);
  vGPIO_Pin_Reset(LED);
  while(1)
  {
    if(u8GPIO_Pin_Read(PUSH))
      vGPIO_Pin_Reset(LED);
    else
      vGPIO_Pin_Set(LED);
      
  }
  
}
