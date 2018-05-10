#define MOD_CONTROL_LEFT    (1<<0)
#define MOD_SHIFT_LEFT      (1<<1)
#define MOD_ALT_LEFT        (1<<2)
#define MOD_GUI_LEFT        (1<<3)
#define MOD_CONTROL_RIGHT   (1<<4)
#define MOD_SHIFT_RIGHT     (1<<5)
#define MOD_ALT_RIGHT       (1<<6)
#define MOD_GUI_RIGHT       (1<<7)

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

//Compound

void typeLine			(char * line);

void spotlight			(char * text);//Mac Specific

void run				(char * text);//Windows Specific

void term				();//Linux Specific

void enterCommandMac	(char * cmd);

void enterCommandWin	(char * cmd);

void enterCommandLinux	(char * cmd);
