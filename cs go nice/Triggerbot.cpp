#pragma once

#include "Triggerbot.h"
#include <windows.h>
#include <TlHelp32.h>
#include <iostream>

static EntityList entityList;

/* Stolen c+p
void FillEntityList(){
	entityList.i_Coutner = 0;
	for (int i = 0; i < 64; i++)
	{
		//Loop From Base Entity Address by 0x10 On Each Iteration
		DWORD dwEntity = Mem.ReadFromMemory<DWORD>((dwEntityList + 0xA4C3E4) + (i * 0x10));

		//Prevent Crash From Reading Null Pointer - also stop counting when weve read the last entity
		if (!dwEntity)
			continue;

		int e_team = Mem.ReadFromMemory<int>(dwEntity + m_iTeamNum);

		//If An Enemy Has Been Found, Store Their Entity Index ID Inside Array
		if (e_team != player.Team() && e_team > 1)
		{
			entityList.i_Enemies[entityList.i_Coutner] = Mem.ReadFromMemory<int>(dwEntity + 0x64);
			entityList.i_Coutner++;
		}
	}
}
*/

Triggerbot::Triggerbot(){
	//stolen
	//FillEntityList();
}

Triggerbot::~Triggerbot(){

}

void Triggerbot::run(){
	//Soon I'll change the triggerbot delay to work based on ammo
	int delayWork = delayInMillis;
	bool firstShot = true;
	bool firstRelease = false;
	//RCS
	while (true){
		//Check if toggled
		if (GetAsyncKeyState(keyBinds.triggerBot)){
			Cheats.triggerbot = !Cheats.triggerbot;
			if (Cheats.triggerbot){
				std::cout << "TB on \n";
				delayWork = delayInMillis;
			}
			else
				std::cout << "TB off \n";
			Sleep(200);
		}

		if (Cheats.triggerbot){
			uintptr_t EnemyInCH = Mem.ReadFromMemory<uintptr_t>(Mem.dwClient + dwEntityList + ((player.CrosshairID() - 1) * EntLoopDist));
			int EnemyTeam = Mem.ReadFromMemory<int>(EnemyInCH + m_iTeamNum);

			if (EnemyTeam != player.Team() && EnemyTeam > 1 && EnemyTeam <= 3 && player.CrosshairID() <= 32 && !GetAsyncKeyState(VK_LBUTTON)){
				if (firstShot){
					Mem.WriteToMemory<bool>(Mem.dwClient + dwForceAttack, true);
					Sleep(10);
				}
				firstRelease = true;
				firstShot = false;
				
				
			}
			else
			{
				if (firstRelease){
					Mem.WriteToMemory<bool>(Mem.dwClient + dwForceAttack, false);
					Sleep(10);
				}
				firstShot = true;
				firstRelease = false;
			}

			Sleep(1);
		}
	}
}

void Triggerbot::setDelay(int newDelay){
	delayInMillis = newDelay;
}