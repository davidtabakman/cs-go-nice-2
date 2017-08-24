#pragma once

#include <windows.h>
#include <TlHelp32.h>


class ProcessManager{
protected:
	DWORD dwProcessID, dwProtection, dwCaveAddress;
	HANDLE handleToProcess;

public:
	DWORD dwClient, dwEngine;

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