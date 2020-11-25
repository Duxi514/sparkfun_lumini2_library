
#ifndef COLORS_H_
#define COLORS_H_

int brightness;

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

void red(int b_red){
	brightness = set_brightness(b_red);
	send(brightness);
	send(0);
	send(0);
	send(255);
}

void blue(int b_blue){
	brightness = set_brightness(b_blue);
	send(brightness);
	send(255);
	send(0);
	send(0);
}

void green(int b_green){
	brightness = set_brightness(b_green);
	send(brightness);
	send(0);
	send(255);
	send(0);
}

void yellow(int b_yellow){
	brightness = set_brightness(b_yellow);
	send(brightness);
	send(0);
	send(255);
	send(255);
}

void purple(int b_purple){
	brightness = set_brightness(b_purple);
	send(brightness);
	send(255);
	send(0);
	send(255);
}

void orange(int b_orange){
	brightness = set_brightness(b_orange);
	send(brightness);
	send(0);
	send(128);
	send(255);
}

void cyan(int b_cyan){
	brightness = set_brightness(b_cyan);
	send(brightness);
	send(255);
	send(255);
	send(0);
}

void pink(int b_pink){
	brightness = set_brightness(b_pink);
	send(brightness);
	send(255);
	send(102);
	send(255);
}

void grey(int b_grey){
	brightness = set_brightness(b_grey);
	send(brightness);
	send(128);
	send(128);
	send(128);
}

void white(int b_white){
	brightness = set_brightness(b_white);
	send(brightness);
	send(255);
	send(255);
	send(255);
}

#endif /* COLORS_H_ */