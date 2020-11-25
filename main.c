#include "header.h"
#include "colors.h"


int main(void){
	
	SPI_init();
	clear_ring();
	//timer0_init();
	
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
		pulse(255,0,0);
		
			
	}
}