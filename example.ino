#include "ducky.h"

#define WINPIN 0
#define MACPIN 1
#define LINUXPIN 2

void setup()
{
	//Initialise pins
	pinMode(WINPIN, INPUT_PULLUP);
	pinMode(MACPIN, INPUT_PULLUP);
	pinMode(LINUXPIN, INPUT_PULLUP);

	//Initialise ducky
	setLedPin(11);
	setLed(false);
	setDelay(100);
	wait(10);

	int win = digitalRead(WINPIN);
	int mac = digitalRead(MACPIN);
	int linux = digitalRead(LINUXPIN);

	if(win == LOW)
	{
		char commandWin[] = "start \"\" https://www.youtube.com/watch?v=dQw4w9WgXcQ";
		enterCommandWin(commandWin);
	}
	else if(mac == LOW)
	{
		char commandMac[] = "osascript -e \"set Volume 10\";open https://www.youtube.com/watch?v=dQw4w9WgXcQ";
		enterCommandMac(commandMac);
	}
	else if(linux == LOW)
	{
		char commandLinux[] = "pactl set-sink-mute 0 0; pactl set-sink-volume 0 100%; amixer set Master unmute; amixer sset 'Master' 100%; sensible-browser https://www.youtube.com/watch?v=dQw4w9WgXcQ";
		enterCommandLinux(commandLinux);
	}

	setLed(true);
}

void loop()
{
}
