#include <string>
#include <fstream>
#include "system/memory/memory.hpp"

float Ram::totalram()
{
    std::ifstream file("/proc/meminfo");

    std::string line = "";
    std::string result = "";

    while(std::getline(file, line))
    {
        if(line.rfind("MemTotal:", 0) == 0)
            result = line.substr(9);
    };
    
    float mem_total = std::stof(result) / 1024.0 / 1024.0;
    
    return mem_total;
}

float Ram::usedram()
{
    std::ifstream file("/proc/meminfo");

    std::string line = "";
    std::string result = "";

    float mem_total = totalram();

    while(std::getline(file, line))
    {
        if(line.rfind("MemAvailable:", 0) == 0)
            result = line.substr(13);
    };
    
    float mem_available = std::stof(result) / 1024.0 / 1024.0;
    
    return mem_total - mem_available;
}

long long Disk::disk_memory()
{
    std::ifstream file("/sys/block/nvme0n1/size");

    long long sectors;
    file >> sectors;

    return (sectors * 512) / (1024.0 * 1024.0 * 1024.0);
}