#include "EntityManager.h"

EntityManager::EntityManager(){
	EntityNum = 0;
}

EntityManager::~EntityManager(){

}

void EntityManager::fillEntityList(){

	int CurrentTeam;
	DWORD CurrentEntity;

	for (int i = 0; i < 64; i++){
		CurrentEntity = Mem.ReadFromMemory<DWORD>(Mem.dwClient + dwEntityList + EntLoopDist*i);

		if (!CurrentEntity)
			break;

		CurrentTeam = Mem.ReadFromMemory<int>(CurrentEntity + m_iTeamNum);
		int playerTeam = player.Team();
		if (CurrentTeam != player.Team() && CurrentTeam <= 3 && CurrentTeam >= 2){
			EntityList[EntityNum] = CurrentEntity;
			EntityNum++;
		}
	}
}

float EntityManager::getEntityX(int entityIndex){
	return Mem.ReadFromMemory<float>(EntityList[entityIndex] + m_vecOrigin);
}

float EntityManager::getEntityY(int entityIndex){
	return Mem.ReadFromMemory<float>(EntityList[entityIndex] + m_vecOrigin + 0x4);
}

float EntityManager::getEntityZ(int entityIndex){
	return Mem.ReadFromMemory<float>(EntityList[entityIndex] + m_vecOrigin + 0x8);
}

int EntityManager::getEntityHealth(int entityIndex){
	return Mem.ReadFromMemory<int>(EntityList[entityIndex] + m_iHealth);
}