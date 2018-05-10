//Config and Misc

void setLedPin			(int pin);

void setLed				(bool state);

void setDelay			(long del);

void wait				(long time);

void initialDelay		();

//Primitives

void typeChar			(char c);

void combo				(char c, int mods);

void typeString			(char * str);

void typeLine			(char * line);

//Compound

void spotlight			(char * text);//Mac Specific

void run				(char * text);//Windows Specific

void term				();//Linux Specific

void enterCommandMac	(char * cmd);

void enterCommandWin	(char * cmd);

void enterCommandLinux	(char * cmd);
