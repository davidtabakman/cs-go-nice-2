#ifndef CONTROL_H
#define CONTROL_H

#include <windows.h>

typedef struct vec3{ float x; float y; float z; };
typedef struct angle{ float pitch; float yaw; float row; };

struct KeyBinds{
	int quit = VK_END;
	int triggerBot = VK_HOME;
	int glow = VK_INSERT;
	int bunnyhop = VK_DELETE;
	int noflash = VK_F6;
	int aimbot = VK_RBUTTON;
}; static KeyBinds keyBinds;

struct cheats{
	bool triggerbot = false;
	bool glow = false;
	bool bunnyhop = false;
	bool noflash = false;
	bool aimbot = false;
}; static cheats Cheats;

#endif /* CONTROL_H */