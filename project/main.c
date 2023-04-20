//Make a sound and alternate lights when a button is pushed
#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "button.h"
#include "buzzer.h"

int main(void){
  led_init();
  switch_init();
  buzzer_init();
  wdt_init();

  

  configureClocks();             //setup master oscillator, CPU & peripheral clocks
  enableWDTInterrupts();         //enable periodic interrupt

  or_sr(0x18);                   //CPU off, GIE on
}

void led_init(){
  P1DIR |= LEDS;
  P1OUT &= ~LEDS;                //leds initially off
}

void switch_init(){
  P1REN |= SWITCHES;             //enables resistors for switches
  P1IE |= SWITCHES;              //enable interrupts from switches
  P1OUT |= SWITCHES;             //pull-ups for switches
  P1DIR &= ~SWITCHES;            //set switches bits for input
}

void buzzer_init(){
  timerAUpmode();                //used to drive speaker
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;                  //enable output to speaker
}

void wdt_init(){
  configureClocks();             //setup master oscillator, CPU & peripheral clocks
  enableWDTInterrupts();         //enable periodic interrupt
}
