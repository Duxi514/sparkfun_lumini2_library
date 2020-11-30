
#ifndef COLORS_H_
#define COLORS_H_

///Variable for holding brightness values
int brightness;

/**
 *	@brief APA102 start frame
 *
 *	Sends the start frame that indicates the start of data input on the LED ring.
 *	Consists of 4 bytes of zeros
*/
void startframe(){
	for (int start = 0; start<4; start++){
		send(0);
	}
}

/**
 *	@brief APA102 end frame
 *
 *	Sends the end frame that indicates the end of data input on the LED ring.
 *	Consists of 4 bytes of ones
*/
void endframe(){
	for (int end = 0; end < 4; end++){
		send(255);
	}
}

/**
 *	@brief red signal
 *
 *	Sends 4 bytes of a signal frame, containing a color code for red color.
 *	Does not send start and end frames, possible to execute unlimited times.
 *	Takes a brightness input as parameter ranging 0-31
*/
void red(int b){
	brightness = set_brightness(b);
	send(brightness);
	send(0);
	send(0);
	send(255);
}

/**
 *	@brief blue signal
 *
 *	Sends 4 bytes of a signal frame, containing a color code for blue color.
 *	Does not send start and end frames, possible to execute unlimited times.
 *	Takes a brightness input as parameter ranging 0-31
*/
void blue(int b){
	brightness = set_brightness(b);
	send(brightness);
	send(255);
	send(0);
	send(0);
}

/**
 *	@brief green signal
 *
 *	Sends 4 bytes of a signal frame, containing a color code for green color.
 *	Does not send start and end frames, possible to execute unlimited times.
 *	Takes a brightness input as parameter ranging 0-31
*/
void green(int b){
	brightness = set_brightness(b);
	send(brightness);
	send(0);
	send(255);
	send(0);
}

/**
 *	@brief yellow signal
 *
 *	Sends 4 bytes of a signal frame, containing a color code for yellow color.
 *	Does not send start and end frames, possible to execute unlimited times.
 *	Takes a brightness input as parameter ranging 0-31
*/
void yellow(int b){
	brightness = set_brightness(b);
	send(brightness);
	send(0);
	send(255);
	send(255);
}

/**
 *	@brief purple signal
 *
 *	Sends 4 bytes of a signal frame, containing a color code for purple color.
 *	Does not send start and end frames, possible to execute unlimited times.
 *	Takes a brightness input as parameter ranging 0-31
*/
void purple(int b){
	brightness = set_brightness(b);
	send(brightness);
	send(255);
	send(0);
	send(255);
}

/**
 *	@brief orange signal
 *
 *	Sends 4 bytes of a signal frame, containing a color code for orange color.
 *	Does not send start and end frames, possible to execute unlimited times.
 *	Takes a brightness input as parameter ranging 0-31
*/
void orange(int b){
	brightness = set_brightness(b);
	send(brightness);
	send(0);
	send(128);
	send(255);
}

/**
 *	@brief cyan signal
 *
 *	Sends 4 bytes of a signal frame, containing a color code for cyan color.
 *	Does not send start and end frames, possible to execute unlimited times.
 *	Takes a brightness input as parameter ranging 0-31
*/
void cyan(int b){
	brightness = set_brightness(b);
	send(brightness);
	send(255);
	send(255);
	send(0);
}

/**
 *	@brief pink signal
 *
 *	Sends 4 bytes of a signal frame, containing a color code for pink color.
 *	Does not send start and end frames, possible to execute unlimited times.
 *	Takes a brightness input as parameter ranging 0-31
*/
void pink(int b){
	brightness = set_brightness(b);
	send(brightness);
	send(255);
	send(102);
	send(255);
}

/**
 *	@brief grey signal
 *
 *	Sends 4 bytes of a signal frame, containing a color code for grey color.
 *	Does not send start and end frames, possible to execute unlimited times.
 *	Takes a brightness input as parameter ranging 0-31
*/
void grey(int b){
	brightness = set_brightness(b);
	send(brightness);
	send(128);
	send(128);
	send(128);
}

/**
 *	@brief white signal
 *
 *	Sends 4 bytes of a signal frame, containing a color code for white color.
 *	Does not send start and end frames, possible to execute unlimited times.
 *	Takes a brightness input as parameter ranging 0-31
*/
void white(int b){
	brightness = set_brightness(b);
	send(brightness);
	send(255);
	send(255);
	send(255);
}

#endif /* COLORS_H_ */