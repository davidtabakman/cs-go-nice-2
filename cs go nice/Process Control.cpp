#pragma once

#include <windows.h>
#include <TlHelp32.h>
#include "Process Control.h"

ProcessManager::ProcessManager(){

}

ProcessManager::~ProcessManager(){
	CloseHandle(handleToProcess);
}

bool ProcessManager::GetProcessHandle(char* ProcessName){
	PROCESSENTRY32 pEntry;
	pEntry.dwSize = sizeof(pEntry);
	handleToProcess = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	
	//Get the first process in the snapshot "handleToProcess"
	Process32First(handleToProcess, &pEntry);

	//Check if it's the one we're looking for
	if (!strcmp(ProcessName, pEntry.szExeFile)){

		dwProcessID = pEntry.th32ProcessID;
		CloseHandle(handleToProcess);


		handleToProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwProcessID);
		return true;
	}

	//Continue to check the processes in the snapshot and search for the requested one
	while (Process32Next(handleToProcess, &pEntry)){
		if (!strcmp(ProcessName, pEntry.szExeFile)){

			dwProcessID = pEntry.th32ProcessID;
			CloseHandle(handleToProcess);


			handleToProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwProcessID);
			return true;
		}
	}

	//Process not found
	return false;
}

DWORD ProcessManager::GetModulePointer(LPSTR ModuleName){
	MODULEENTRY32 mEntry;
	mEntry.dwSize = sizeof(mEntry);
	HANDLE handleToModule = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, dwProcessID);

	//Check if the first module is the requested one
	while (Module32Next(handleToModule, &mEntry)){

		if (!strcmp(mEntry.szModule, ModuleName))
		{
			CloseHandle(handleToModule);
			return (DWORD)mEntry.modBaseAddr;
		}
	}

	return 0;
}