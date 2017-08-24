#pragma once

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

class Noflash
{
public:
	Noflash();
	~Noflash();
	virtual void setPercentage(float a);
	virtual void run();
	
private:
	float percentage;
};