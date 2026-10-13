#include <string>
#include <fstream>
#include "system/CPU/cpu.hpp"
#include <unistd.h>

std::string CPU::distro_cpu()
{
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
    
}