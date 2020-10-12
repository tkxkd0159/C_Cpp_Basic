//#include <Windows.h>
//
//int main()
//{
//    STARTUPINFOW si = { 0 };
//    si.cb = sizeof(si);
//    PROCESS_INFORMATION pi = { 0 };
//
//    // Create the child process
//    BOOL success = CreateProcessW(
//        L"C:\\Windows\\system32\\notepad.exe",  // Path to executable
//        NULL,                                   // Command line arguments
//        NULL,                                   // Process attributes
//        NULL,                                   // Thread attributes
//        FALSE,                                  // Inherit handles
//        0,                                      // Creation flags
//        NULL,                                   // Environment
//        NULL,                                   // Working directory
//        &si,                                    // Startup info
//        &pi);                                   // Process information
//
//    if (success)
//    {
//        // Wait for the process to exit
//        WaitForSingleObject(pi.hProcess, INFINITE);
//
//        // Process has exited - check its exit code
//        DWORD exitCode;
//        GetExitCodeProcess(pi.hProcess, &exitCode);
//
//        // At this point exitCode is set to the process' exit code
//
//        // Handles must be closed when they are no longer needed
//        CloseHandle(pi.hThread);
//        CloseHandle(pi.hProcess);
//    }
//}