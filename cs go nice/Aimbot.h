#ifndef AIMBOT_H
#define AIMBOT_H

#include <windows.h>
#include <TlHelp32.h>
#include <iostream>
#include "Control.h"
#include "Local Player.h"
#include "EntityManager.h"
#include "RCS.h"
#include <math.h>

#define PI (3.141592653589793)
#define D3DXToRadian(degree) ((degree) * (PI / 180.0f))


extern LocalPlayer player;

extern RCS rcs;

class Aimbot {
public:
	Aimbot();
	virtual void run(EntityManager entityManager);
	~Aimbot();
private:
	vec3 me;
	vec3 enemy;
	angle newAngle;
	angle closestEntityToCrosshair(EntityManager entityManager, angle newAngle, int bone);
	float soomthener = 15;
	float fovDeg = 20;
	virtual void setup();
	virtual angle CalcAng(vec3 me, vec3 enemy, int fFlags);
};

#endif /* AIMBOT_H */