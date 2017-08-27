#include "RCS.h"

RCS::RCS(){

}

RCS::~RCS(){

}

angle RCS::run(angle originalAngle){
	if (Mem.ReadFromMemory<bool>(Mem.dwClient + dwForceAttack)){
		shotsFired = Mem.ReadFromMemory<int>(player.Base() + m_iShotsFired);
		if (shotsFired >= 1){

			angle m_PunchAngle = player.getAimPunch();

			newAngle.pitch = originalAngle.pitch - m_PunchAngle.pitch * 2;
			newAngle.yaw = originalAngle.yaw - m_PunchAngle.yaw * 2;
			// remove the new "viewpunch" from the originalAngles
			

			oldAngle.pitch = m_PunchAngle.pitch * 2;
			oldAngle.yaw = m_PunchAngle.yaw * 2;
			// save the old "viewpunch"

			return newAngle;

		}
		else{
			
			oldAngle.pitch = 0;
			oldAngle.yaw = 0;
		}
	}
	else{
		
		oldAngle.pitch = 0;
		oldAngle.yaw = 0;
	}
	return originalAngle;
}

angle RCS::getNormal(){
	angle ViewAngle = player.getAng();

	angle m_PunchAngle = player.getAimPunch();

	ViewAngle.pitch = ViewAngle.pitch + oldAngle.pitch;
	ViewAngle.yaw = ViewAngle.yaw + oldAngle.yaw;

	return ViewAngle;
}

void RCS::reset(){
	oldAngle.pitch = 0;
	oldAngle.yaw = 0;
}