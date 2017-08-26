#ifndef LOCALPLAYER_H
#define LOCALPLAYER_H

#include <windows.h>
#include <TlHelp32.h>
#include "offsets.h"
#include "Process Control.h"
#include "Control.h"

extern ProcessManager Mem;

class LocalPlayer{
protected:
	uintptr_t PlayerBase;
	
public:

	LocalPlayer();
	~LocalPlayer();

	virtual bool setup(DWORD pClient);
	virtual DWORD Base();
	virtual int CrosshairID();
	virtual int Health();
	virtual int Team();
	virtual int CurrentWeapon();
	virtual void setFlashMaxAlpha(float a);
	int getShotsFired();
	angle getAimPunch();
	vec3 getEyePos();
	float getX();
	float getY();
	float getZ();
	angle getAng();
	void setAng(angle a);
	
};

#endif /*LOCALPLAYER.H*/