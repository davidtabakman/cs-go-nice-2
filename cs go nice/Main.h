#pragma once


#include <TlHelp32.h>
#include "Control.h";
#include "Local Player.h"
#include "offsets.h"
#include "Triggerbot.h"
#include "Glow.h"
#include "Bunnyhop.h"
#include "Noflash.h"

ProcessManager Mem;
LocalPlayer player;
Triggerbot trigger;
Glow glow;
Bunnyhop bunnyhop;
Noflash noflash;

extern KeyBinds keyBinds;
extern cheats Cheats;
