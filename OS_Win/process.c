#include <stdio.h>
#include <windows.h>

int main() {
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));



	// Create child process
	if (!CreateProcess(
		L"C:\\Windows\\system32\\mspaint.exe",  // Path to executable
		NULL,                                   // Command line arguments
		NULL,                                   // Process attributes
		NULL,                                   // Thread attributes
		FALSE,                                  // Inherit handles
		0,                                      // Creation flags
		NULL,                                   // Environment
		NULL,                                   // Working directory
		&si,                                    // Startup info
		&pi))                                   // Process information
	{
		fprintf(stderr, "\nCreate Process Failed");
		return -1;
	}
	else {
		printf("\nWell, CreateProcess() looks OK \n");
		printf("exit when you terminate program  \n\n");
	}

	// Parent will wait for the child to complete
	WaitForSingleObject(pi.hProcess, INFINITE);
	printf("Child Complete");

	// Close handles
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);


}