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

float LocalPlayer::getX(){
	return Mem.ReadFromMemory<float>(PlayerBase + m_vecOrigin);
}

float LocalPlayer::getY(){
	return Mem.ReadFromMemory<float>(PlayerBase + m_vecOrigin + 0x4);
}

float LocalPlayer::getZ(){
	return Mem.ReadFromMemory<float>(PlayerBase + m_vecOrigin + 0x8);
}

vec3 LocalPlayer::getEyePos(){
	vec3 vecOrigin = Mem.ReadFromMemory<vec3>(PlayerBase + m_vecOrigin);
	vec3 vecViewOffset = Mem.ReadFromMemory<vec3>(PlayerBase + m_vecViewOffset);
	vecOrigin.x += vecViewOffset.x;
	vecOrigin.y += vecViewOffset.y;
	vecOrigin.z += vecViewOffset.z;
	return vecOrigin;
}

int LocalPlayer::getShotsFired(){
	return Mem.ReadFromMemory<int>(PlayerBase + m_iShotsFired);
}

angle LocalPlayer::getAimPunch(){
	return Mem.ReadFromMemory<angle>(PlayerBase + m_aimPunchAngle);
}

void LocalPlayer::setAng(angle a){
	DWORD AngPtr = Mem.ReadFromMemory<DWORD>(Mem.dwEngine + dwClientState);
	Mem.WriteToMemory<angle>(AngPtr + dwClientState_ViewAngles, a);
}

angle LocalPlayer::getAng(){
	DWORD AngPtr = Mem.ReadFromMemory<DWORD>(Mem.dwEngine + dwClientState);
	return Mem.ReadFromMemory<angle>(AngPtr + dwClientState_ViewAngles);
}