

#ifndef HEADER_H_
#define HEADER_H_

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define CS      PINB2
#define MOSI    PINB3
#define SCK     PINB5

int  brightness;
volatile uint8_t tot_overflow;

void SPI_init(){
	DDRB |= (1 << CS) | (1 << MOSI) | (1 << SCK);
	SPCR = (1 << SPE) | (1 << MSTR);
}

void send(uint8_t data){
	SPDR = data;
	while(!(SPSR & (1 << SPIF)));
}



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


int set_brightness(int bright){ //224 containing the 3 led bits
	int brightness = 224 + bright;
	return brightness;
}

void get_hun_flag(int h){
	startframe();
	for(int count=0; count < 7; count++){
		red(h);
	}
	for(int count=0; count < 7; count++){
		white(h);
	}
	for(int count=0; count < 13; count++){
		green(h);
	}
	for(int count=0; count < 7; count++){
		white(h);
	}
	for(int count=0; count < 7; count++){
		red(h);
	}
	endframe();
}

void rainbow(int r){
	startframe();
	for(int count = 0; count < 5; count++){
		purple(r);
		_delay_ms(100);
		blue(r);
		_delay_ms(100);
		green(r);
		_delay_ms(100);
		yellow(r);
		_delay_ms(100);
		orange(r);
		_delay_ms(100);
		red(r);
		_delay_ms(100);
		cyan(r);
		_delay_ms(100);
		grey(r);
		_delay_ms(100);
	}
	endframe();
}

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

void timer0_init(){
	TCCR0B |= (1 << CS02)|(1 << CS00);
	TCNT0 = 0;						   //set the timer/counter to zero
	TIMSK0 |= (1 << TOIE0);			   //interrupt register setup
	sei();							   //function call to enable interrupts
}

ISR(TIMER0_OVF_vect){					//OVERFLOW FUNCTION HANDLING THE SQUAREWAVE
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