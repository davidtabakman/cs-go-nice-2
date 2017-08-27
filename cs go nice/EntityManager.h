#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include "Process Control.h"
#include "offsets.h"
#include "Local Player.h"
#include "Control.h"

extern ProcessManager Mem;
extern LocalPlayer player;

class EntityManager {
public:
	EntityManager();
	void fillEntityList();
	~EntityManager();
	float getEntityX(int entityIndex);
	float getEntityY(int entityIndex);
	float getEntityZ(int entityIndex);
	bool isDormant(int entityIndex);
	int getEntityHealth(int entityIndex);
	vec3 getEntityBoneVec(int entityIndex, int boneID);
	int EntityNum;
	bool isSpotted(int entityIndex);
private:
	
	DWORD EntityList[32];
	
};

static EntityManager entityManager;

#endif //ENTITYMANAGER_H