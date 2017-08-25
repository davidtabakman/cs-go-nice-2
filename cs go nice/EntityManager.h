#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include "Process Control.h"
#include "offsets.h"
#include "Local Player.h"

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
	int getEntityHealth(int entityIndex);
private:
	
	DWORD EntityList[32];
	int EntityNum;
};

static EntityManager entityManager;

#endif //ENTITYMANAGER_H