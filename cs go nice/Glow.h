#ifndef GLOW_H
#define GLOW_H

#include <windows.h>
#include <TlHelp32.h>
#include <iostream>
#include "Control.h"
#include "Local Player.h"
#include "offsets.h"


extern ProcessManager Mem;
extern LocalPlayer player;

extern KeyBinds keyBinds;
extern cheats Cheats;

class Glow
{
public:
	Glow();
	~Glow();
	virtual void run();
	virtual void setup();
private:
	
};

#endif /*GLOW_H*/



