#include "Glow.h"

Glow::Glow()
{
}

Glow::~Glow()
{
}

struct Entity{
	DWORD dwBase;
	DWORD glowIndex;
	int team;
	bool isDormant;
};


void Glow::run(){
	DWORD glow_Pointer = Mem.ReadFromMemory<DWORD>(Mem.dwClient + dwGlowObjectManager);
	Entity currentEntity;
	while (true){
		if (GetAsyncKeyState(keyBinds.glow)){
			Cheats.glow = !Cheats.glow;
			if (Cheats.glow)
				std::cout << "GLOW on \n";
			else
				std::cout << "GLOW off \n";
			Sleep(200);
		}
		if (Cheats.glow)
			for (int i = 0; i < 32; i++){
				currentEntity.dwBase = Mem.ReadFromMemory<DWORD>(Mem.dwClient + dwEntityList + i * 0x10);
				currentEntity.team = Mem.ReadFromMemory<int>(currentEntity.dwBase + m_iTeamNum);
				currentEntity.glowIndex = Mem.ReadFromMemory<DWORD>(currentEntity.dwBase + m_iGlowIndex);
				currentEntity.isDormant = Mem.ReadFromMemory<bool>(currentEntity.dwBase + dwDormant);

				if (currentEntity.team <= 1 || currentEntity.isDormant)
					continue;
				else{
					if (currentEntity.team == player.Team()){
						Mem.WriteToMemory<float>((glow_Pointer + ((currentEntity.glowIndex * 0x38) + 0x4)), 0.f);
						Mem.WriteToMemory<float>((glow_Pointer + ((currentEntity.glowIndex * 0x38) + 0x8)), 1.f);
						Mem.WriteToMemory<float>((glow_Pointer + ((currentEntity.glowIndex * 0x38) + 0xC)), 0.f);
						Mem.WriteToMemory<float>((glow_Pointer + ((currentEntity.glowIndex * 0x38) + 0x10)), 1.f);
						Mem.WriteToMemory<bool>((glow_Pointer + ((currentEntity.glowIndex * 0x38) + 0x24)), true);
						Mem.WriteToMemory<bool>((glow_Pointer + ((currentEntity.glowIndex * 0x38) + 0x25)), false);
					}
					else {
						Mem.WriteToMemory<float>((glow_Pointer + ((currentEntity.glowIndex * 0x38) + 0x4)), 1.f);
						Mem.WriteToMemory<float>((glow_Pointer + ((currentEntity.glowIndex * 0x38) + 0x8)), 0.f);
						Mem.WriteToMemory<float>((glow_Pointer + ((currentEntity.glowIndex * 0x38) + 0xC)), 0.f);
						Mem.WriteToMemory<float>((glow_Pointer + ((currentEntity.glowIndex * 0x38) + 0x10)), 1.f);
						Mem.WriteToMemory<bool>((glow_Pointer + ((currentEntity.glowIndex * 0x38) + 0x24)), true);
						Mem.WriteToMemory<bool>((glow_Pointer + ((currentEntity.glowIndex * 0x38) + 0x25)), false);
					}
				}
		}

	}
}

void Glow::setup(){

}