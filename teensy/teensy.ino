#include "duckyTeensy.h"

#define WINDOWS 1
#define MAC 2
#define LINUX 3

void setup()
{
	//Initialise pins
	pinMode(1, INPUT_PULLUP);
	pinMode(2, INPUT_PULLUP);
	pinMode(4, INPUT_PULLUP);
	pinMode(5, INPUT_PULLUP);
	pinMode(6, INPUT_PULLUP);
	pinMode(7, INPUT_PULLUP);
	pinMode(8, INPUT_PULLUP);

	//Initialise ducky
	setLedPin(11);
	setLed(false);
	setDelay(100);
	wait(10);

	//Read DIP switch
	int dip1 = digitalRead(8) == LOW ? 1 : 0;
	int dip2 = digitalRead(7) == LOW ? 1 : 0;
	int dip3 = digitalRead(6) == LOW ? 1 : 0;
	int dip4 = digitalRead(5) == LOW ? 1 : 0;
	int dip5 = digitalRead(4) == LOW ? 1 : 0;
	int dip6 = digitalRead(3) == LOW ? 1 : 0;
	int dip7 = digitalRead(2) == LOW ? 1 : 0;
	int dip8 = digitalRead(1) == LOW ? 1 : 0;

	int os = 0;

	if(dip1)
		os = WINDOWS;
	else if(dip2)
		os = MAC;
	else if(dip3)
		os = LINUX;

	int op = dip4 << 4 | dip5 << 3 | dip6 << 2 | dip7 << 1 | dip8 << 0;

	char * command = (char *)"";
	switch (op)
	{
	    case 0:
	    	if(os == WINDOWS)
				command = (char *)"start \"\" https://www.youtube.com/watch?v=dQw4w9WgXcQ";
	    	else if(os == MAC)
				command = (char *)"osascript -e \"set Volume 10\";open https://www.youtube.com/watch?v=dQw4w9WgXcQ";
	    	else if(os == LINUX)
	    		command = (char *)"pactl set-sink-mute 0 0; pactl set-sink-volume 0 100%; amixer set Master unmute; amixer sset 'Master' 100%; xdg-open https://www.youtube.com/watch?v=dQw4w9WgXcQ";
	    	break;
	    case 1:
	    	if(os == MAC || os == LINUX)
	    		command = (char *)"curl parrot.live";
	    default:
	    	break;
	}

	if(os == WINDOWS)
		enterCommandWin(command);
	else if(os == MAC)
		enterCommandMac(command);
	else if(os == LINUX)
		enterCommandLinux(command);

	setLed(true);
}

void loop()
{
}
