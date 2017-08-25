#pragma once

#include <windows.h>
#include <TlHelp32.h>
#include <iostream>
#include "Main.h"
#include <thread>

#include "glm-master\glm\vec3.hpp"
#include "glm-master\glm\vec4.hpp"
#include "glm-master\glm\matrix.hpp"


//Run functions for threads (in case I wanna run some kind of a setup aswell)
//--------------------------------------------------------------------------
void runBH(){
	bunnyhop.run();
}

void runTB(){
	trigger.run();
}

void runNF(){
	noflash.run();
	
}

void runGlow(){
	glow.run();
}
//---------------------------------------------------------------------------


glm::vec3 ExtractCameraPos_NoScale(const glm::mat4 & a_modelView)
{
	glm::mat3 rotMat(a_modelView);
	glm::vec3 d(a_modelView[3]);

	glm::vec3 retVec = -d * rotMat;
	return retVec;
}

int main(){

	//If csgo is running, get its handle
	if (Mem.GetProcessHandle("csgo.exe")){

		//Get the engine and client dll offsets
		std::cout << "process found \n";
		Mem.dwClient = Mem.GetModulePointer("client.dll");
		Mem.dwEngine = Mem.GetModulePointer("engine.dll");
		std::cout << "modules found \n\n";
		
		
		//Hard coded controls because I was lazy
		player.setup(Mem.dwClient);
		std::cout << "TB key: HOME \n";
		std::cout << "GLOW key: INSERT \n";
		std::cout << "BH key: DELETE \n";
		std::cout << "NF key: F6 \n";
		std::cout << "EXIT key: END \n\n";

		entityManager.fillEntityList();
		//Bunnyhop thread
		std::thread BH(runBH);
		BH.detach();

		//Triggerbot thread
		std::thread TB(runTB);
		TB.detach();

		//noflash thread
		std::thread NF(runNF);
		NF.detach();

		//glow thread
		std::thread Glow(runGlow);
		Glow.detach();

		//Check if the exit button is pressed, Sleep(2) so it won't take too much resources
		while (!GetAsyncKeyState(keyBinds.quit)){
			aimbot.run(entityManager);
			
			Sleep(2);
		}

		//Exit
		ExitProcess(0);

		
	}
}