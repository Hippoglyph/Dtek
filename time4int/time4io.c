#include <stdint.h>
#include <pic32mx.h>
#include "mipslab.h"

int getsw(){
    return (PORTD &= 0xf00)>>8;
}

int getbtns(void){
	return ((PORTF & 2)>>1) | (PORTD &= 0xe0)>>4;
}