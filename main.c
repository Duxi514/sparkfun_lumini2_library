/*! @mainpage APA102 Sparkfun LuMini library for Atmega328 microcontroller
 *
 *  @section Description 
 *	This is a library written for the Atmega328/328P microcontroller for handling the LuMini LED ring
 *	based on the APA102 addressable LED components. 
 *
 *	Implemented built in functions displaying different
 *	images/patterns, addressing specified number and color of LEDs and interfacing the component with timer0.
 *
 *	The library uses SPI communication protocol, the component takes 5 volts.
 *
 *	Author: Dániel Dukai
 *
 *	Date: 23.11.2020.
 *
 *	Code is written in C using Atmel Studio
 *	
 * 	Documentation made with Doxygen
 *
 *	Reference: https://www.doxygen.nl/index.html
*/

#include "header.h"
#include "colors.h"

///SPI initialization (and timer0 setup) functions go here outside of main loop
int main(void){
	
    while (1){
/*
		fillandclear(255,0,0,2);
		_delay_ms(100);
		get_hun_flag(2);
		_delay_ms(500);
		clear_ring();
		_delay_ms(100);
		rainbow(2);
		_delay_ms(100);
		clear_ring();
		pulse(0,255,0);		
		_delay_ms(100);
		clear_ring();
		led_setup(40,0,255,255,3);
		_delay_ms(300);
		clear_ring();
	*/			
	}
}