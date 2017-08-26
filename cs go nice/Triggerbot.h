#pragma once

#include "Control.h"
#include "Local Player.h"
#include "offsets.h"
#include "Process Control.h"
#include <windows.h>
#include <TlHelp32.h>
#include "RCS.h"

struct EntityList{
	int i_Enemies[32];
	int i_Coutner;
};


extern ProcessManager Mem;
extern LocalPlayer player;

extern KeyBinds keyBinds;
extern cheats Cheats;

void FillEntityList();

class Triggerbot{
protected:
	int delayInMillis = 50;

public:

	Triggerbot();
	~Triggerbot();

	virtual void run();
	virtual void setDelay(int newDelay);
};