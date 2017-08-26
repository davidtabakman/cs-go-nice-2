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

void Aimbot::run(EntityManager entityManager){
	DWORD AngPtr = Mem.ReadFromMemory<DWORD>(Mem.dwEngine + dwClientState);
	while (true){
		//Check if toggled
		if (GetAsyncKeyState(keyBinds.aimbot)){
			
			int i = closestEntityIndex(entityManager);
			if (i != -1){
				me = player.getEyePos(); enemy = entityManager.getEntityBoneVec(i, 8); newAngle.pitch = 0; newAngle.yaw = 0; newAngle.row = 0;
				
					//angle myAngle = Mem.ReadFromMemory<angle>(AngPtr + dwClientState_ViewAngles);
					angle myAngle = rcs.getNormal();

					newAngle = CalcAng(me, enemy, 0);
					angle betweenAngle;
					if (myAngle.yaw > 0.0f && newAngle.yaw < 0.0f){
						betweenAngle = angSub(newAngle, myAngle);
						if (betweenAngle.yaw < -180.0f){
							newAngle.yaw += 360.0f;
							betweenAngle = angSub(newAngle, myAngle);
							newAngle.yaw -= 360.0f;
						}
						

						if (betweenAngle.yaw > 180.0f || betweenAngle.yaw <= -180.0f){
							betweenAngle.yaw = (360 - betweenAngle.yaw)*-1;
						}
						if (betweenAngle.yaw > 180.0f || betweenAngle.yaw <= -180.0f)
							std::cout << "banned";

						if (betweenAngle.yaw < fovDeg && betweenAngle.yaw > -fovDeg && betweenAngle.pitch < fovDeg && betweenAngle.pitch > -fovDeg){
							betweenAngle = angDiv(betweenAngle, soomthener);
							newAngle = angAdd(myAngle, betweenAngle);

							newAngle.pitch = clampFloat(newAngle.pitch, -89.0f, 89.0f);
							newAngle = rcs.run(newAngle);
							player.setAng(newAngle);
						}
					}
					else if (newAngle.yaw < 0.0f && myAngle.yaw < 0.0f){
						newAngle.yaw += 360.0f;
						myAngle.yaw += 360.0f;
						betweenAngle = angSub(newAngle, myAngle);
						myAngle.yaw -= 360.0f;
						newAngle.yaw -= 360.0f;

						if (betweenAngle.yaw > 180.0f || betweenAngle.yaw <= -180.0f){
							betweenAngle.yaw = (360 - betweenAngle.yaw)*-1;
						}
						if (betweenAngle.yaw > 180.0f || betweenAngle.yaw <= -180.0f)
							std::cout << "banned";

						if (betweenAngle.yaw < fovDeg && betweenAngle.yaw > -fovDeg && betweenAngle.pitch < fovDeg && betweenAngle.pitch > -fovDeg){
							betweenAngle = angDiv(betweenAngle, soomthener);
							newAngle = angAdd(myAngle, betweenAngle);

							newAngle.pitch = clampFloat(newAngle.pitch, -89.0f, 89.0f);
							
							
							newAngle = rcs.run(newAngle);
						
							player.setAng(newAngle);
						}
					}			
					else {
						betweenAngle = angSub(newAngle, myAngle);

						if (betweenAngle.yaw > 180.0f || betweenAngle.yaw <= -180.0f){
							betweenAngle.yaw = (360 - betweenAngle.yaw)*-1;
						}
						if (betweenAngle.yaw > 180.0f || betweenAngle.yaw <= -180.0f)
							std::cout << "banned";
						if (betweenAngle.yaw < fovDeg && betweenAngle.yaw > -fovDeg && betweenAngle.pitch < fovDeg && betweenAngle.pitch > -fovDeg){
							betweenAngle = angDiv(betweenAngle, soomthener);
							newAngle = angAdd(myAngle, betweenAngle);

							newAngle.pitch = clampFloat(newAngle.pitch, -89.0f, 89.0f);
							newAngle = rcs.run(newAngle);
							player.setAng(newAngle);
						}
					}
					
					
					
					
			
			}
		}
		Sleep(2);
	}
}