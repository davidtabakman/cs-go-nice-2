#pragma once

#include <windows.h>
#include <TlHelp32.h>

typedef float matrix4x4_t[4][4];

class ProcessManager{
protected:
	DWORD dwProcessID, dwProtection, dwCaveAddress;
	

public:
	DWORD dwClient, dwEngine;
	HANDLE handleToProcess;

	ProcessManager();
	~ProcessManager();

	template <class T>
	T ReadFromMemory(DWORD dwAddress)
	{
		T data;
		ReadProcessMemory(handleToProcess, (LPVOID)dwAddress, &data, sizeof(T), NULL);
		return data;
	}

	template <class T>
	bool WriteToMemory(DWORD dwAdress, T data){
		if (WriteProcessMemory(handleToProcess, (LPVOID) dwAdress, &data, sizeof(T), NULL)){
			return true;
		}
		return false;
	}


	virtual bool GetProcessHandle(char* ProcessName);
	virtual DWORD GetModulePointer(LPSTR ModuleName);
};