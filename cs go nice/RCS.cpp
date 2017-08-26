#include "RCS.h"

RCS::RCS(){

}

RCS::~RCS(){

}

angle RCS::run(angle originalAngle){
	if (Mem.ReadFromMemory<bool>(Mem.dwClient + dwForceAttack)){
		shotsFired = Mem.ReadFromMemory<int>(player.Base() + m_iShotsFired);
		if (shotsFired > 1){
			originalAngle = player.getAng();

			angle m_PunchAngle = player.getAimPunch();

			originalAngle.pitch = originalAngle.pitch + oldAngle.pitch;
			originalAngle.yaw = originalAngle.yaw + oldAngle.yaw;

			// Add the old "viewpunch" so we get the "center" of the screen again

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