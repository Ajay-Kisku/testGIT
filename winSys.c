#include <windows.h>
#include <stdio.h>
// #include <sysinfoapi.h>
#include <tchar.h>
#include <psapi.h>

int main() {
    // === SYSTEM INFO ===
    SYSTEM_INFO sysinfo;
    GetSystemInfo(&sysinfo);

    printf("==== SYSTEM INFO ====\n");

    printf("Processor Architecture: ");
    switch (sysinfo.wProcessorArchitecture) {
        case PROCESSOR_ARCHITECTURE_AMD64: printf("x64 (AMD or Intel)\n"); break;
        case PROCESSOR_ARCHITECTURE_INTEL: printf("x86\n"); break;
        // case PROCESSOR_ARCHITECTURE_ARM64: printf("ARM64\n"); break;
        default: printf("Unknown\n"); break;
    }

    printf("Number of Logical Processors: %u\n", sysinfo.dwNumberOfProcessors);
    printf("Page Size: %u bytes\n", sysinfo.dwPageSize);
    printf("Minimum Application Address: 0x%p\n", sysinfo.lpMinimumApplicationAddress);
    printf("Maximum Application Address: 0x%p\n", sysinfo.lpMaximumApplicationAddress);
    printf("Allocation Granularity: %u bytes\n", sysinfo.dwAllocationGranularity);
    printf("Processor Level: %u\n", sysinfo.wProcessorLevel);
    printf("Processor Revision: 0x%04X\n", sysinfo.wProcessorRevision);

    // === MEMORY INFO ===
    MEMORYSTATUSEX meminfo;
    meminfo.dwLength = sizeof(meminfo);
    GlobalMemoryStatusEx(&meminfo);

    printf("\n==== MEMORY INFO ====\n");
    printf("Total Physical Memory: %llu MB\n", meminfo.ullTotalPhys / (1024 * 1024));
    printf("Available Physical Memory: %llu MB\n", meminfo.ullAvailPhys / (1024 * 1024));
    printf("Total Virtual Memory: %llu MB\n", meminfo.ullTotalVirtual / (1024 * 1024));
    printf("Available Virtual Memory: %llu MB\n", meminfo.ullAvailVirtual / (1024 * 1024));
    printf("Memory Load: %lu%%\n", meminfo.dwMemoryLoad);

    // === COMPUTER NAME ===
    TCHAR computerName[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD size = sizeof(computerName) / sizeof(computerName[0]);
    if (GetComputerName(computerName, &size)) {
        printf("\n==== COMPUTER INFO ====\n");
        printf("Computer Name: %ls\n", computerName);
    }

    // === SYSTEM DIRECTORY ===
    TCHAR sysDir[MAX_PATH];
    GetSystemDirectory(sysDir, MAX_PATH);
    printf("System Directory: %ls\n", sysDir);

    // === UPTIME ===
    ULONGLONG uptime_ms = GetTickCount();
    DWORD uptime_sec = (DWORD)(uptime_ms / 1000);
    DWORD hours = uptime_sec / 3600;
    DWORD minutes = (uptime_sec % 3600) / 60;
    DWORD seconds = uptime_sec % 60;

    printf("\n==== UPTIME ====\n");
    printf("System Uptime: %02u:%02u:%02u (hh:mm:ss)\n", hours, minutes, seconds);

    return 0;
}
