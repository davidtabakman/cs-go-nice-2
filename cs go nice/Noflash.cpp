#include "Noflash.h"

Noflash::Noflash(){
	percentage = 0.0f;
}

Noflash::~Noflash(){

}

void Noflash::run(){
	while (true){
		//Check if noflash is toggled
		if (GetAsyncKeyState(keyBinds.noflash)){
			Cheats.noflash = !Cheats.noflash;
			if (Cheats.noflash){
				std::cout << "NF on \n";
				setPercentage(0.0f);
			}
			else{
				std::cout << "NF off \n";
				setPercentage(255.0f);
			}
			Sleep(200);
		}
		//-----------------------------------------------
		player.setFlashMaxAlpha(percentage);
	}
}

//Set the alpha
void Noflash::setPercentage(float a){
	percentage = a;
	player.setFlashMaxAlpha(percentage);
}