

#ifndef HEADER_H_
#define HEADER_H_

#include <avr/io.h>
#include <util/delay.h>
#define CS      PINB2
#define MOSI    PINB3
#define SCK     PINB5

int  brightness;

void SPI_init(){
	DDRB |= (1 << CS) | (1 << MOSI) | (1 << SCK);
	SPCR = (1 << SPE) | (1 << MSTR);
}

void send(uint8_t data){
	SPDR = data;
	while(!(SPSR & (1 << SPIF)));
}

void startframe(){
	for (int start = 0; start<4; start++){
		send(0);
	}
}

void endframe(){
	for (int end = 0; end < 4; end++){
		send(255);
	}
}

void led_setup(int nr,int bl,int gr,int rd,int b){
	int num=nr;
	int blu=bl;
	int gre=gr;
	int red=rd;
	int bri=b;
	clear_ring();
	startframe();
	for (int i = 0; i<num;i++){
		send(224+bri);
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

void get_hun_flag(int c){
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
}

void rainbow(int c){
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
void waitforportcbutton(unsigned char n){
	DDRC &= (0<<n);
	PORTC |= (1<<n);

	while(PINB & (1<<n)!= (0<<n)){}	
	while(PINB & (1<<n)!= (1<<n)){}
	_delay_ms(10);
}

#endif /* HEADER_H_ */