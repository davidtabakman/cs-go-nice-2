#ifndef CONTROL_H
#define CONTROL_H

#include <windows.h>
#include <ctime>
#include <iostream>


typedef struct vec3{ float x; float y; float z; };
typedef struct angle{
	void normalize() {
		if (pitch > 89.0f) pitch = 89.0f;
		if (pitch < -89.0f) pitch = -89.0f;

		while (yaw > 180.0f) yaw -= 360.0f;
		while (yaw <= -180.0f) yaw += 360.0f;

		if (yaw > 180.0f) yaw = 180.0f;
		if (yaw < -180.0f) yaw = -180.0f;

		row = 0.0f;
	}

	angle(){

	}

	angle(float Pitch, float Yaw, float Row){
		pitch = Pitch; yaw = Yaw; row = Row;
	}
	angle operator + (angle Angle){
		return angle(pitch + Angle.pitch, yaw + Angle.yaw, row + Angle.row);
	}

	angle operator - (angle Angle){
		return angle(pitch - Angle.pitch, yaw - Angle.yaw, row - Angle.row);
	}

	angle operator * (float mult) {
		return angle(pitch * mult, yaw * mult, row * mult);
	}

	bool operator == (angle Angle){
		return pitch == Angle.pitch && yaw == Angle.yaw && row == Angle.row;
	}

	bool operator != (angle Angle) {
		return !(Angle == *this);
	}

	angle operator / (float div) {
		return angle(pitch / div, yaw / div, row / div);
	}

	void print() {
		std::cout << "X - " << pitch << ", Y - " << yaw << ", Z - " << row << std::endl;
	}

	
	float pitch; float yaw; float row; 
};

struct KeyBinds{
	int quit = VK_END;
	int triggerBot = VK_HOME;
	int glow = VK_INSERT;
	int bunnyhop = VK_DELETE;
	int noflash = VK_F6;
	int aimbotToggle = VK_RBUTTON;
	int aimbotKey = VK_LBUTTON;
	int aimbotNextMode = VK_F7;
}; static KeyBinds keyBinds;

struct cheats{
	bool triggerbot = false;
	bool glow = false;
	bool bunnyhop = false;
	bool noflash = false;
	bool aimbot = false;
}; static cheats Cheats;

enum ItemDefinitionIndex : int {
	WEAPON_DEAGLE = 1,
	WEAPON_ELITE = 2,
	WEAPON_FIVESEVEN = 3,
	WEAPON_GLOCK = 4,
	WEAPON_AK47 = 7,
	WEAPON_AUG = 8,
	WEAPON_AWP = 9,
	WEAPON_FAMAS = 10,
	WEAPON_G3SG1 = 11,
	WEAPON_GALILAR = 13,
	WEAPON_M249 = 14,
	WEAPON_M4A1 = 16,
	WEAPON_MAC10 = 17,
	WEAPON_P90 = 19,
	WEAPON_UMP45 = 24,
	WEAPON_XM1014 = 25,
	WEAPON_BIZON = 26,
	WEAPON_MAG7 = 27,
	WEAPON_NEGEV = 28,
	WEAPON_SAWEDOFF = 29,
	WEAPON_TEC9 = 30,
	WEAPON_TASER = 31,
	WEAPON_HKP2000 = 32,
	WEAPON_MP7 = 33,
	WEAPON_MP9 = 34,
	WEAPON_NOVA = 35,
	WEAPON_P250 = 36,
	WEAPON_SCAR20 = 38,
	WEAPON_SG556 = 39,
	WEAPON_SSG08 = 40,
	WEAPON_KNIFE = 42,
	WEAPON_FLASHBANG = 43,
	WEAPON_HEGRENADE = 44,
	WEAPON_SMOKEGRENADE = 45,
	WEAPON_MOLOTOV = 46,
	WEAPON_DECOY = 47,
	WEAPON_INCGRENADE = 48,
	WEAPON_C4 = 49,
	WEAPON_KNIFE_T = 59,
	WEAPON_M4A1_SILENCER = 60,
	WEAPON_USP_SILENCER = 61,
	WEAPON_CZ75A = 63,
	WEAPON_REVOLVER = 64,
	WEAPON_KNIFE_BAYONET = 500,
	WEAPON_KNIFE_FLIP = 505,
	WEAPON_KNIFE_GUT = 506,
	WEAPON_KNIFE_KARAMBIT = 507,
	WEAPON_KNIFE_M9_BAYONET = 508,
	WEAPON_KNIFE_TACTICAL = 509,
	WEAPON_KNIFE_FALCHION = 512,
	WEAPON_KNIFE_SURVIVAL_BOWIE = 514,
	WEAPON_KNIFE_BUTTERFLY = 515,
	WEAPON_KNIFE_PUSH = 516
};

#endif /* CONTROL_H */