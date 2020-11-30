#ifndef HEADER_H_
#define HEADER_H_

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define CS      PINB2			///<Chip select on port B pin 2
#define MOSI    PINB3			///<Master-out slave-in on port B pin 3
#define SCK     PINB5			///<System clock on port B pin 5

///Variable holding the brightness value
int  brightness;
///Variable holding the number of interrupts if enabled
int tot_overflow;


/**
 *		@brief Initialises SPI communication
 *
 *		DDRB |= (1 << CS) | (1 << MOSI) | (1 << SCK); --> Sets up output pins (chip select, master-out slave-in, system clock)
 *
 *		SPCR = (1 << SPE) | (1 << MSTR); --> Sets up uC as master
*/
void SPI_init(){
	DDRB |= (1 << CS) | (1 << MOSI) | (1 << SCK);
	SPCR = (1 << SPE) | (1 << MSTR);
}

/**
 *		@brief Sends the data through SPI
 *
 *		Waits until data transmit is finished
 *
*/
void send(uint8_t data){
	SPDR = data;
	while(!(SPSR & (1 << SPIF)));
}

/**
 * 		@brief Enables a number of LEDs with a specified color and brightness
 *
 * 		@param nr Number of LEDs ranging from 0 to 40
 *
 * 		@param bl Parameter for holding blue value (0-255)
 *
 * 		@param gr Parameter for holding green value (0-255)
 *
 * 		@param rd Parameter for holding red value (0-255)
 *
 * 		@param lb Parameter for holding brightness value (0-31)
 *
 *		@example led_setup.c Example how to use the led_setup function
*/
void led_setup(int nr,int bl,int gr,int rd,int lb){
	int num=nr;
	int blu=bl;
	int gre=gr;
	int red=rd;
	int b3 = set_brightness(lb);
	clear_ring();
	startframe();
	for (int i = 0; i<num;i++){
		send(b3);
		send(blu);
		send(gre);
		send(red);
	}
	endframe();
}


/**
*		@brief Set brightness
*
*		Add brightness bits to the first 111 bitframe
*
*		@param bright Brightness ranging 0-31
*		@return Output ranging from 11100000 to 11111111
*
*
*/
int set_brightness(int bright){
	int brightness = 224 + bright;
	return brightness;
}

/**
 *		@brief Displays the Hungarian flag on the ring
 *		
 *		@param c Brightness value (0-31)
 *
 *		@example set_brightness.c Example of the set_brightness function
*/
void get_hun_flag(int c){
	startframe();
	for(int count=0; count < 7; count++){
		red(c);
	}
	for(int count=0; count < 7; count++){
		white(c);
	}
	for(int count=0; count < 13; count++){
		green(c);
	}
	for(int count=0; count < 7; count++){
		white(c);
	}
	for(int count=0; count < 7; count++){
		red(c);
	}
	endframe();
}


/**
 *		Displays a rainbow on the LED of 8 colors
 *		
 *		@param c Brightness value (0-31)
 *
 *		@example rainbow.c Example of the rainbow function
*/
void rainbow(int c){
	startframe();
	for(int count = 0; count < 5; count++){
		purple(c);
		_delay_ms(100);
		blue(c);
		_delay_ms(100);
		green(c);
		_delay_ms(100);
		yellow(c);
		_delay_ms(100);
		orange(c);
		_delay_ms(100);
		red(c);
		_delay_ms(100);
		cyan(c);
		_delay_ms(100);
		grey(c);
		_delay_ms(100);
	}
	endframe();
}

/**
 *		Clears ring
 *
 *		Disables every LED on the ledring
 *
*/
void clear_ring(){
	startframe();
	for(int count=0;count<40;count++){
		send(225);
		send(0);
		send(0);
		send(0);
	}
	endframe();
}

/**
 *		@brief Timer0 initialisation
 *
 *		Enables the timer0 of the microcontroller to toggle the leds
 *		
 *		TCCR0B |= (1 << CS02)|(1 << CS00); --> prescaler setup for slow blinking
 *
 *		TCNT0 = 0; --> counter set to 0
 *
 *		TIMSK0 |= (1 << TOIE0); --> interrupt register setup
 *
 *		sei();  --> enable interrupts for toggling
 *
*/
void timer0_init(){
	TCCR0B |= (1 << CS02)|(1 << CS00);
	TCNT0 = 0;
	TIMSK0 |= (1 << TOIE0);
	sei();
}

/**
 *		@brief Interrupt callback function
 *
 *		Gets executed every time timer0 interrupts, then setting the LED for 5 different colors at each
 *
 *		For reference see: timer0_init()
 *		
*/
ISR(TIMER0_OVF_vect){
	tot_overflow++;
	switch (tot_overflow%5){
		case 0:
			led_setup(40,255,0,0,1);
			break;
		case 1:
			led_setup(40,0,255,0,1);
			break;
		case 2:
			led_setup(40,0,0,255,1);
			break;
		case 3:
			led_setup(40,255,0,255,1);
			break;
		case 4:
			led_setup(40,0,255,255,1);
			break;
	}
}

/**
 *		@brief Enables then diasbles the LEDs
 *
 *		Turns the LEDs on one by one then turns them off one by one
 *
 *		@param bl Parameter for blue value
 *
 *		@param gr Parameter for green value
 *
 *		@param rd Parameter for red value
 *
 *		@param b Parameter for brightness setting
 *
 *		@example fillandclear.c Example for the fillandclear function
*/

void fillandclear(int bl,int gr,int rd,int b){
	startframe();
	int b0 = set_brightness(b);
	for(int i=0;i<40;i++){
		send(b0);
		send(bl);
		send(gr);
		send(rd);
		_delay_ms(5);	
	}
	endframe();
	startframe();
	for(int i=40;i>0;i--){
		send(224);
		send(0);
		send(0);
		send(0);
		_delay_ms(5);
	}
	endframe();
}

/**
 *		@brief Pulse on the led ring
 *
 *		Slowly increasing then decreasing the brightness of the LEDs with a specified color
 *
 *		@param bl Parameter for blue value
 *
 *		@param gr Parameter for green value
 *
 *		@param rd Parameter for red value
 *
 *		@example pulse.c Example for the pulse function
*/

void pulse(int bl, int gr, int rd){
	for (int bit = 0;bit<31;bit++){
		 startframe();
		 int b1 = set_brightness(bit);
		for (int nr=0;nr<40;nr++){
			 send(b1);
			 send(bl);
			 send(gr);
			 send(rd);
		}
		endframe();
		_delay_ms(100);
	}
	for (int bit = 31;bit>0;bit--){
		startframe();
		int b2 = set_brightness(bit);
		for (int nr=0;nr<40;nr++){
			 send(b2);
			 send(bl);
			 send(gr);
			 send(rd);
		}
		endframe();
		_delay_ms(100);
	}
}
#endif /* HEADER_H_ */