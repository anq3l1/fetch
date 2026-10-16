#include <string>
#include <fstream>
#include "system/CPU/cpu.hpp"
#include <unistd.h>
#ifdef _WIN32
#include <windows.h>
#include <intrin.h>
#ifndef NOMINMAX
#define NOMINMAX
#endif
#endif


std::string CPU::distro_cpu()
{
#ifdef _WIN32
    char name[256] = {};
    DWORD size = sizeof(name);
    if (RegGetValueA(HKEY_LOCAL_MACHINE,
                     "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0",
                     "ProcessorNameString", RRF_RT_REG_SZ, nullptr, name, &size) == ERROR_SUCCESS)
    {
        return name;
    }
    SYSTEM_INFO info{};
    GetSystemInfo(&info);

    return std::to_string(info.dwNumberOfProcessors) + " logical processors";
#else
    std::ifstream file("/proc/cpuinfo");
    std::string line;
    std::string cpu_name;
    
    while(std::getline(file, line))
    {
        if(line.find("model name	:") == 0)
            cpu_name = line.substr(12);
    }
    
    if (cpu_name.front() == ' ')
        cpu_name = cpu_name.substr(1, cpu_name.size() - 1);

    return cpu_name; 
#endif 
    
}
