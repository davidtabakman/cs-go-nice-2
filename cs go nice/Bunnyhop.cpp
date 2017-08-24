#include "Bunnyhop.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h> 
#include <stdio.h>

Bunnyhop::Bunnyhop()
{
}

Bunnyhop::~Bunnyhop()
{
}

void Bunnyhop::run(){
	bool enabled = false;
	while (true){
		if (GetAsyncKeyState(keyBinds.bunnyhop)){
			Cheats.bunnyhop = !Cheats.bunnyhop;
			if (Cheats.bunnyhop)
				std::cout << "BH on \n";
			else
				std::cout << "BH off \n";
			Sleep(200);
		}
		if (GetAsyncKeyState(VK_SPACE) && Cheats.bunnyhop) // or other key, NOT space
		{

			keybd_event(0x45, 0x39, NULL, NULL);

			Sleep(14.5);

			keybd_event(0x45, 0x39, KEYEVENTF_KEYUP, NULL);

			Sleep(14.5);
		}
		Sleep(1);
	}
}