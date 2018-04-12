#define CTRL 	0b0001
#define ALT 	0b0010
#define SHIFT 	0b0100
#define GUI 	0b1000

//Config and Misc

void setLedPin			(int pin);

void setLed				(bool state);

void setDelay			(int del);

void wait				(int time);

void initialDelay		();

//Primitives

void typeString			(char * str);

void typeChar			(char c);

void combo				(int mods, char c);

//Compound

void typeLine			(char * line);

void spotlight			(char * text);//Mac Specific

void run				(char * text);//Windows Specific

void enterCommandMac	(char * cmd);

void enterCommandWin	(char * cmd);

void enterCommandLinux	(char * cmd);
