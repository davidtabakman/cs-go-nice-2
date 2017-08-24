#ifndef BUNNYHOP_H
#define BUNNYHOP_H


#include "Control.h";
class Bunnyhop
{
public:
	Bunnyhop();
	~Bunnyhop();
	virtual void run();
};

extern KeyBinds keyBinds;
extern cheats Cheats;
#endif /* BUNNYHOP_H */