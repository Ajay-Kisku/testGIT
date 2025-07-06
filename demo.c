//use all of the keywords in the C

#include <stdio.h>
#include <windows.h>

#include <wchar.h>


int main(){
    wchar_t* wide_text = L"Hello, wide ▀ world!";
    wprintf(L"%ls\n", wide_text);  // Print wide string

    // wprintf(L"Flower\n",);
    printf("Hi, there\n");
    printf("---------------------------------------------\n");
    printf("Name of the file is     : %s\n", __FILE__);
    printf("Date of the compilation : %s\n", __DATE__);
    printf("Time of the compilation : %s\n", __TIME__);
    printf("Timestamp of the compilation : %s\n\n", __TIMESTAMP__);

    printf("GCC version : %s\n", __VERSION__);
    printf("Test : %d\n", __COUNTER__);
    printf("Test : %d\n", __COUNTER__);

    printf("Base file : %s\n", __BASE_FILE__);
    printf("Test : %d\n", __BIGGEST_ALIGNMENT__);
    printf("ANSI C Standards         : %d\n", __STDC__);
    printf("ANSI C Standards version : %d\n", __STDC_VERSION__);
    printf("Hosted environment       : %d\n", __STDC_HOSTED__);


    //get the OS info 

    #if defined(_WIN32)
        printf("Operating System: Windows (32 or 64-bit)\n");
    #elif defined(_WIN64)
        printf("Operating System: Windows 64-bit\n");
    #elif defined(__linux__)
        printf("Operating System: Linux\n");
    #elif defined(__APPLE__) && defined(__MACH__)
        printf("Operating System: macOS\n");
    #elif defined(__unix__)
        printf("Operating System: Unix\n");
    #else
        printf("Operating System: Unknown\n");
    #endif


    OSVERSIONINFO info;
    info.dwOSVersionInfoSize = sizeof(info);
    if (GetVersionEx(&info)) {
        printf("Windows Version: %ld.%ld (Build %ld)\n",
               info.dwMajorVersion,
               info.dwMinorVersion,
               info.dwBuildNumber);
    } else {
        printf("Failed to get version info.\n");
    }


     SYSTEM_INFO sysinfo;
    GetSystemInfo(&sysinfo);

    printf("Number of logical processors: %u\n", sysinfo.dwNumberOfProcessors);

    return 0;
}