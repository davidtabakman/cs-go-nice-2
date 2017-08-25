#include "Aimbot.h"

Aimbot::Aimbot(){
	
}

Aimbot::~Aimbot(){
	
}

void Aimbot::setup(){

}

angle Aimbot::CalcAng(vec3 me, vec3 enemy, angle result, int fFlags){
	vec3 newEnemy;
	newEnemy.x = me.x - enemy.x;
	newEnemy.y = me.y - enemy.y;
	newEnemy.z = me.z - enemy.z;
	float hyp = sqrt(newEnemy.x*newEnemy.x + newEnemy.y*newEnemy.y);
	result.pitch = (float) (asinf(newEnemy.z / hyp) * 57.295779513f); //asinf results in radians, convert them do degrees
	result.yaw = (float) (atanf(newEnemy.y / newEnemy.x) * 57.295779513f);

	if (newEnemy.x >= 0.0)
	{
		result.yaw += 180.0f;
	}

	return result;
}

void Aimbot::run(EntityManager entityManager){
	DWORD AngPtr = Mem.ReadFromMemory<DWORD>(Mem.dwEngine + dwClientState);
	me.x = player.getX(); me.y = player.getY(); me.z = player.getZ(); enemy.x = entityManager.getEntityX(0); enemy.y = entityManager.getEntityY(0); enemy.z = entityManager.getEntityZ(0); newAngle.pitch = 0; newAngle.yaw = 0; newAngle.row = 0;
	if (entityManager.getEntityHealth(0) > 0){
		angle myAngle = Mem.ReadFromMemory<angle>(AngPtr + dwClientState_ViewAngles);
		newAngle = CalcAng(me, enemy, newAngle, 0);
		if (sqrt(pow((newAngle.pitch + 180) - (myAngle.pitch + 180), 2) + pow((newAngle.yaw + 180) - (myAngle.yaw + 180), 2)) < 50)
		Mem.WriteToMemory<angle>(AngPtr + dwClientState_ViewAngles, newAngle);
	}
}