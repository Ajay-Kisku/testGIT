#include <windows.h>
#include <tlhelp32.h>
#include <tchar.h>
#include <stdio.h>

int main() {
    HANDLE hProcessSnap;
    PROCESSENTRY32 pe32;

    // Take a snapshot of all processes in the system.
    hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hProcessSnap == INVALID_HANDLE_VALUE) {
        printf("Failed to create process snapshot.\n");
        return 1;
    }

    pe32.dwSize = sizeof(PROCESSENTRY32);

    // Retrieve information about the first process
    if (!Process32First(hProcessSnap, &pe32)) {
        printf("Failed to get first process.\n");
        CloseHandle(hProcessSnap);
        return 1;
    }

    printf("List of running processes:\n");

    // Now walk the snapshot of processes
    do {
        #ifdef UNICODE
                wprintf(L"Process ID: %u \t Executable: %s\n", pe32.th32ProcessID, pe32.szExeFile);
        #else
                printf("Process ID: %u \t Executable: %s\n", pe32.th32ProcessID, pe32.szExeFile);
        #endif
        } while (Process32Next(hProcessSnap, &pe32));

    CloseHandle(hProcessSnap);
    return 0;
}
