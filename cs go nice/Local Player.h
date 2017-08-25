#ifndef LOCALPLAYER_H
#define LOCALPLAYER_H

#include <windows.h>
#include <TlHelp32.h>
#include "offsets.h"
#include "Process Control.h"

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
	float getX();
	float getY();
	float getZ();
	
};

#endif /*LOCALPLAYER.H*/