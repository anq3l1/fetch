#include <string>
#include <fstream>
#include "system/memory/memory.hpp"


#ifdef _WIN32
#include <windows.h>

#else
    #include <sys/sysinfo.h>
#endif

float Ram::totalram()
{
#ifdef _WIN32
    MEMORYSTATUSEX memory{};
    memory.dwLength = sizeof(memory);
    return GlobalMemoryStatusEx(&memory) ? static_cast<float>(memory.ullTotalPhys / (1024.0 * 1024 * 1024)) : 0.0f;
#else
    struct sysinfo info {};
    return sysinfo(&info) == 0 ? static_cast<float>(info.totalram * info.mem_unit / (1024.0 * 1024 * 1024)) : 0.0f;
#endif
}

float Ram::usedram()
{
#ifdef _WIN32
    MEMORYSTATUSEX memory{};
    memory.dwLength = sizeof(memory);
    if (!GlobalMemoryStatusEx(&memory)) return 0.0f;
    return static_cast<float>((memory.ullTotalPhys - memory.ullAvailPhys) / (1024.0 * 1024 * 1024));
#else
    struct sysinfo info {};
    if (sysinfo(&info) != 0) return 0.0f;
    return static_cast<float>((info.totalram - info.freeram) * info.mem_unit / (1024.0 * 1024 * 1024));
#endif
}

long long Disk::disk_memory()
{
#ifdef __linux__
    std::ifstream file("/sys/block/nvme0n1/size");

    long long sectors = 0;
    file >> sectors;

    return (sectors * 512) / (1024.0 * 1024.0 * 1024.0);
#elif defined(_WIN32)
    char windows_path[MAX_PATH] = {};
    const UINT path_length = GetWindowsDirectoryA(windows_path, MAX_PATH);
    if (path_length == 0 || path_length >= MAX_PATH || windows_path[1] != ':')
        return 0;

    char drive_root[] = "C:\\";
    drive_root[0] = windows_path[0];

    ULARGE_INTEGER total_bytes{};
    if (!GetDiskFreeSpaceExA(drive_root, nullptr, &total_bytes, nullptr))
        return 0;

    constexpr unsigned long long bytes_per_gigabyte = 1024ULL * 1024 * 1024;
    return static_cast<long long>(total_bytes.QuadPart / bytes_per_gigabyte);
#endif
    return 0;
}
