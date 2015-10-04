/* mipslabwork.c

   This file written 2015 by F Lundevall

   This file should be changed by YOU! So add something here:

   This file modified 2015-12-24 by Ture Teknolog 

  This file modified 2015-10-1 by Jonathan Rinnarv

   Latest update 2015-08-28 by F Lundevall

   For copyright and licensing, see file COPYING */

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */


int mytime = 0x5957;
//volatile int * porte = (volatile int*) 0xbf886110;
int tickCounter = 0;
int timeoutcount = 0;
int prime = 1234567;

char textstring[] = "text, more text, and even more text!";

/* Interrupt Service Routine */
void user_isr( void )
{
  IFS(0) &= ~(0x100);
  timeoutcount++;

  if(timeoutcount >= 10)
        timeoutcount = 0;
    else
      return;

 time2string( textstring, mytime );
 display_string( 3, textstring );
 display_update();
 tick( &mytime );
}

/* Lab-specific initialization goes here */
void labinit( void )
{ 
  enable_interrupt(); //From labwork.S
  IEC(0) |= 0x100; //enable interupt for TMR2
  IPC(2) |= 0x10; //set interupt priority to 4/7
  
  //volatile int * trise = (volatile int*) 0xbf886100;
  //*trise &= ~(0xff); //set bit 7 throu 0 to output (0)
  
  //TRISD |= (0xfe); //set bit 11 throu 5 to input (1)
  //TRISF |= (0x2);

  T2CON = 0x70; //prescaling 1:256
  TMR2 = 0; //Clear the timer register
  PR2 = 31250; //80*10^6/256/10 (100  ms)
  T2CON |= 0x8000; //Turn timer on
  return;
}

/* This function is called repetitively from the main program */
void labwork( void )
{
 prime = nextprime( prime );
 display_string( 0, itoaconv( prime ) );
 display_update();
}
