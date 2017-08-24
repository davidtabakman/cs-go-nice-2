#ifndef CONTROL_H
#define CONTROL_H

#include <windows.h>

struct KeyBinds{
	int quit = VK_END;
	int triggerBot = VK_HOME;
	int glow = VK_INSERT;
	int bunnyhop = VK_DELETE;
	int noflash = VK_F6;
}; static KeyBinds keyBinds;

struct cheats{
	bool triggerbot = false;
	bool glow = false;
	bool bunnyhop = false;
	bool noflash = false;
}; static cheats Cheats;

#endif /* CONTROL_H */