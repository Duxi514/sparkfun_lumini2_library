
#ifndef COLORS_H_
#define COLORS_H_

int brightness;

void red(int b){
	brightness = set_brightness(b);
	send(brightness);
	send(0);
	send(0);
	send(255);
}

void blue(int b){
	brightness = set_brightness(b);
	send(brightness);
	send(255);
	send(0);
	send(0);
}

void green(int b){
	brightness = set_brightness(b);
	send(brightness);
	send(0);
	send(255);
	send(0);
}

void yellow(int b){
	brightness = set_brightness(b);
	send(brightness);
	send(0);
	send(255);
	send(255);
}

void purple(int b){
	brightness = set_brightness(b);
	send(brightness);
	send(255);
	send(0);
	send(255);
}

void orange(int b){
	brightness = set_brightness(b);
	send(brightness);
	send(0);
	send(128);
	send(255);
}

void cyan(int b){
	brightness = set_brightness(b);
	send(brightness);
	send(255);
	send(255);
	send(0);
}

void pink(int b){
	brightness = set_brightness(b);
	send(brightness);
	send(255);
	send(102);
	send(255);
}

void grey(int b){
	brightness = set_brightness(b);
	send(brightness);
	send(128);
	send(128);
	send(128);
}

void white(int b){
	brightness = set_brightness(b);
	send(brightness);
	send(255);
	send(255);
	send(255);
}

#endif /* COLORS_H_ */