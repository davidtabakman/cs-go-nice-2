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

int EntityManager::getEntityHealth(int entityIndex){
	return Mem.ReadFromMemory<int>(EntityList[entityIndex] + m_iHealth);
}

float EntityManager::getEntityX(int entityIndex){
DWORD dwBoneBase = Mem.ReadFromMemory<DWORD>(EntityList[entityIndex] + m_dwBoneMatrix);

return Mem.ReadFromMemory<float>(dwBoneBase + 0x30 * 7 + 0xC);

}

float EntityManager::getEntityY(int entityIndex){
DWORD dwBoneBase = Mem.ReadFromMemory<DWORD>(EntityList[entityIndex] + m_dwBoneMatrix);

return Mem.ReadFromMemory<float>(dwBoneBase + 0x30 * 7 + 0x1C);
}

float EntityManager::getEntityZ(int entityIndex){
	DWORD dwBoneBase = Mem.ReadFromMemory<DWORD>(EntityList[entityIndex] + m_dwBoneMatrix);

	return Mem.ReadFromMemory<float>(dwBoneBase + 0x30 * 7 + 0x2C);
}

vec3 EntityManager::getEntityBoneVec(int entityIndex, int boneID){
	DWORD dwBoneBase = Mem.ReadFromMemory<DWORD>(EntityList[entityIndex] + m_dwBoneMatrix);
	vec3 coords;
	coords.x = Mem.ReadFromMemory<float>(dwBoneBase + boneID * 0x30 + 0xC);
	coords.y = Mem.ReadFromMemory<float>(dwBoneBase + boneID * 0x30 + 0x1C);
	coords.z = Mem.ReadFromMemory<float>(dwBoneBase + boneID * 0x30 + 0x2C);
	return coords;
}

bool EntityManager::isDormant(int entityIndex){
	return Mem.ReadFromMemory<bool>(EntityList[entityIndex] + dwDormant);
}