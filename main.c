
#include "header.h"
#include "colors.h"


int main(void){
	
	SPI_init();
	clear_ring();
	
    while (1){

		
		waitforportcbutton(0);
		led_setup(39,255,0,0,1);
		waitforportcbutton(0);
		clear_ring();
		
		
		/*
		startframe();
		rainbow(2);
		endframe();
		endframe();
		_delay_ms(1000);
		
		
		clear_ring();
		_delay_ms(1000);
		
		
		startframe();		
		get_hun_flag(2);
		_delay_ms(3000);
		endframe();
		endframe();
		*/
    }
}

