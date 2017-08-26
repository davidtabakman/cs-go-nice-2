#ifndef RCS_H
#define RCS_H

#include <windows.h>
#include <TlHelp32.h>
#include <iostream>
#include "Control.h"
#include "Local Player.h"
#include "EntityManager.h"

class RCS{
protected:
	angle newAngle;
	angle viewAngle;
	
	int shotsFired = 0;
public:
	RCS();
	angle oldAngle;
	angle run(angle originalAngle);
	~RCS();
	angle getNormal();
};
 
#endif