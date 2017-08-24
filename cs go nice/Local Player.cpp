#pragma once

#include <windows.h>
#include <TlHelp32.h>
#include "Local Player.h"
#include "offsets.h"

LocalPlayer::LocalPlayer(){
	
}

LocalPlayer::~LocalPlayer(){

}



bool LocalPlayer::setup(DWORD pClient){

	PlayerBase = Mem.ReadFromMemory<uintptr_t>(pClient + dwLocalPlayer);
	return true;
}

DWORD LocalPlayer::Base(){
	return PlayerBase;
}

int LocalPlayer::CrosshairID(){
	return Mem.ReadFromMemory<int>(PlayerBase + m_iCrosshairId);
}

int LocalPlayer::Health(){
	return Mem.ReadFromMemory<int>(PlayerBase + m_iHealth);
}

int LocalPlayer::Team(){
	return Mem.ReadFromMemory<int>(PlayerBase + m_iTeamNum);
}

int LocalPlayer::CurrentWeapon(){
	DWORD WepHandle = Mem.ReadFromMemory<DWORD>(PlayerBase + m_hActiveWeapon);
	DWORD WepEntity = Mem.ReadFromMemory<DWORD>(Mem.dwClient + dwEntityList + ((WepHandle & 0xFFF) - 1) * 0x10);
	return Mem.ReadFromMemory<int>(WepEntity + m_iItemDefinitionIndex); //finds the current weapon
}

void LocalPlayer::setFlashMaxAlpha(float a){
	Mem.WriteToMemory<float>(PlayerBase + m_flFlashMaxAlpha, a);
}
