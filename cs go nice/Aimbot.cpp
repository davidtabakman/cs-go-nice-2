#include "Aimbot.h"

Aimbot::Aimbot(){
	
}

Aimbot::~Aimbot(){
	
}

void Aimbot::setup(){

}

angle Aimbot::CalcAng(vec3 me, vec3 enemy, int fFlags){
	vec3 newEnemy;
	angle result;
	newEnemy.x = me.x - enemy.x;
	newEnemy.y = me.y - enemy.y;
	newEnemy.z = me.z - enemy.z;
	float hyp = sqrt(newEnemy.x*newEnemy.x + newEnemy.y*newEnemy.y);
	result.pitch = (float) (asinf(newEnemy.z / hyp) * 57.295779513f); //asinf results in radians, convert them do degrees
	result.yaw = (float) (atanf(newEnemy.y / newEnemy.x) * 57.295779513f);
	result.row = 0.0f;

	if (newEnemy.x >= 0.0)
	{
		result.yaw += 180.0f;
	}

	if (result.yaw > 180.0f || result.yaw <= -180.0f){
		result.yaw = (360 - result.yaw)*-1;
	}

	return result;
}

angle angSub(angle a, angle b){
	angle c;
	c.pitch = a.pitch - b.pitch;
	c.yaw = a.yaw - b.yaw;
	c.row = a.row - b.row;
	return c;
}

angle angAdd(angle a, angle b){
	angle c;
	c.pitch = a.pitch + b.pitch;
	c.yaw = a.yaw + b.yaw;
	c.row = a.row + b.row;
	return c;
}

angle angMul(angle a, float b){
	angle c;
	c.pitch = a.pitch * b;
	c.yaw = a.yaw * b;
	c.row = a.row * b;
	return c;
}

angle angDiv(angle a, float b){
	angle c;
	c.pitch = a.pitch / b;
	c.yaw = a.yaw / b;
	c.row = a.row / b;
	return c;
}

float clampFloat(float var , float min, float max ){
	if (var < min){
		var = min;
	}
	if (var > max){
		var = max;
	}
	return var;
}



float getDist(EntityManager entityManager, int i){
	float xDist, yDist, zDist, totalDist, minDist = 10000000.0f;
	xDist = entityManager.getEntityX(i) - player.getX();
	yDist = entityManager.getEntityY(i) - player.getY();
	zDist = entityManager.getEntityZ(i) - player.getZ();
	totalDist = sqrtf(xDist * xDist + yDist * yDist + zDist * zDist);
	return totalDist;
}

int closestEntityIndex(EntityManager entityManager){
	float xDist, yDist, zDist, totalDist, minDist = 10000000.0f;
	int minIndex = -1;
	for (int i = 0; i < entityManager.EntityNum; i++){
		if (entityManager.getEntityHealth(i) > 0 && !entityManager.isDormant(i)){
			xDist = entityManager.getEntityX(i) - player.getX();
			yDist = entityManager.getEntityY(i) - player.getY();
			zDist = entityManager.getEntityZ(i) - player.getZ();
			totalDist = sqrtf(xDist * xDist + yDist * yDist + zDist * zDist);
			if (totalDist < minDist){
				minDist = totalDist;
				minIndex = i;
			}
		}
	}
	
	return minIndex;
}

angle Aimbot::closestEntityToCrosshair(EntityManager entityManager, angle newAngle, int bone){
	me = player.getEyePos();
	angle lowestAngle, myAngle, betweenAngle, distAngAbs;
	lowestAngle.pitch = 999999999.f;
	float minDist = 999999999.f, dist, dist2, newFov;
	
	for (int i = 0; i < entityManager.EntityNum; i++){
		if (entityManager.getEntityHealth(i) > 0 && !entityManager.isDormant(i) && entityManager.isSpotted(i)){
			enemy = entityManager.getEntityBoneVec(i, bone);
			myAngle = rcs.getNormal();
			newAngle = CalcAng(me, enemy, 0);
			newAngle.normalize();



			betweenAngle = angSub(newAngle, myAngle);
			betweenAngle.normalize();
				
			dist = sqrtf(betweenAngle.yaw * betweenAngle.yaw + betweenAngle.pitch * betweenAngle.pitch);
			distAngAbs = betweenAngle;
			distAngAbs.pitch = fabsf(distAngAbs.pitch);
			distAngAbs.yaw = fabsf(distAngAbs.yaw);
			dist2 = getDist(entityManager, i);
			float fRealDistanceYaw = sin(D3DXToRadian(distAngAbs.yaw)) * dist2;
			float fRealDistancePitch = sin(D3DXToRadian(distAngAbs.pitch)) * dist2;
			if (fRealDistanceYaw < fovDeg && fRealDistancePitch < fovDeg){
				minDist = dist;
				if (fRealDistancePitch < fovDeg / 2.5 && fRealDistanceYaw < fovDeg / 2.5)
					betweenAngle = angDiv(betweenAngle, soomthener);
				else if (fRealDistancePitch < fovDeg / 1.5 && fRealDistanceYaw < fovDeg / 1.5)
					betweenAngle = angDiv(betweenAngle, soomthener/1.5);
				else
					betweenAngle = angDiv(betweenAngle, soomthener / 2.5);
				lowestAngle = angAdd(myAngle, betweenAngle);
				lowestAngle.pitch = clampFloat(lowestAngle.pitch, -89.0f, 89.0f);
			}
		}
		
	}
	return lowestAngle;
}

void Aimbot::run(EntityManager entityManager){
	DWORD AngPtr = Mem.ReadFromMemory<DWORD>(Mem.dwEngine + dwClientState);
	firstAim = true;
	firstRelease = false;
	std::srand(time(NULL));
	while (true){
		//Check if toggled
		if (GetAsyncKeyState(keyBinds.aimbotNextMode)){
			if (mode == 2)
				mode = 0;
			else if (mode == 0)
				mode = 1;
			else
				mode = 2;
			std::cout << "Current mode: " << mode << std::endl;
			Sleep(100);
		}
		if (mode == 1){
			if (GetAsyncKeyState(keyBinds.aimbotKey)){
				aim(entityManager);
			}
		}
		else if (mode == 2){
			if (GetAsyncKeyState(keyBinds.aimbotToggle)){
				Cheats.aimbot = !Cheats.aimbot;
				std::cout << "Aimbot is " << Cheats.aimbot << std::endl;
				Sleep(100);
			}
			if (Cheats.aimbot){
				aim(entityManager);
			}
		}
		Sleep(2);
	}
}

void Aimbot::aim(EntityManager entityManager){
	
	int currentWeapon = player.CurrentWeapon();
	if (firstAim){
		bone = rand() % 3 + 6;
		if (currentWeapon == WEAPON_SG556 || currentWeapon == WEAPON_DEAGLE)
			bone = 8;
		firstAim = false;
		firstRelease = true;
	}
	newAngle = closestEntityToCrosshair(entityManager, newAngle, bone);
	if (newAngle.pitch != 999999999.f){

		if (currentWeapon != WEAPON_USP_SILENCER && currentWeapon != WEAPON_DEAGLE && currentWeapon != WEAPON_FIVESEVEN && currentWeapon != WEAPON_GLOCK && currentWeapon != WEAPON_P250)
			newAngle = rcs.run(newAngle);
		player.setAng(newAngle);
	}
	else {
		if (firstRelease) {
			firstAim = true;
			firstRelease = false;
		}
		rcs.reset();
	}
}