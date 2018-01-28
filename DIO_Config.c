#include "DIO.h"

/*----------------PIN CONFIGURATION EX----------------*/
/*
const PIN_INIT_T PIN_NAME = {PORTA     , //from PORTA to PORTQ
                             0         , //from 0 to 7
                             PIN_INPUT , //PIN_INPUT or PIN_OUTPUT
                             Pull_up    //Pull_up or pull_down
                             };
*/

PIN_INIT_T LED  = {PORTF,4,PIN_OUTPUT,pull_down};

const PIN_INIT_T PUSH = {PORTJ,0,PIN_INPUT,Pull_up};


