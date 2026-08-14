#ifndef SYSTEM_H
#define SYSTEM_H
#include <iostream>
#include <sys/sysinfo.h>
#include <fstream>
#include <string>
#include <sstream>
#include <sys/utsname.h>
#include <memory>

std::string getGpuName() {
    std::string result = "";
    std::shared_ptr<FILE> pipe(popen("lspci | grep -E 'VGA|3D|Display'", "r"), pclose);
    
    char buffer[128];
    if (fgets(buffer, sizeof(buffer), pipe.get()) != nullptr) {
        result = buffer;
    }
    
    size_t pos = result.find("M [GeForce");
    if (pos != std::string::npos) {
        result = result.substr(pos + 2);
    }

    if (!result.empty() && result.back() == '\n') {
        result.pop_back();
    }
    
    return result;
}


int sys_uptime()
{
    struct sysinfo si;
    int uptime;

    if(sysinfo(&si) == 0)
    {
        uptime = si.uptime / 60;
    }

    return uptime;
}

std::string kernel_info()
{
    struct utsname buffer;
    std::string release;

    if(uname(&buffer) == 0)
    {
        release = buffer.release;
    }

    return release;
}

std::string distro_name()
{
    std::ifstream file("/etc/os-release");
    std::string line;
    std::string name;

    while(std::getline(file, line))
    {
        if(line.find("PRETTY_NAME=") == 0)
            name = line.substr(12);
    }
    if (name.front() == '"' && name.back() == '"')
    name = name.substr(1, name.size() - 2);

    return name;
}

std::string distro_cpu()
{
    std::ifstream file("/proc/cpuinfo");
    std::string line;
    std::string cpu_name;

    while(std::getline(file, line))
    {
        if(line.find("model name	:") == 0)
            cpu_name = line.substr(12);
    }

    return cpu_name;
}

float distro_totalram()
{
    struct sysinfo si;
    if(sysinfo(&si) == 0)
    {
        return (float)si.totalram * si.mem_unit / 1024 / 1024 / 1024;
    }

    return 0;
}

float distro_ram()
{
    struct sysinfo si;

    if(sysinfo(&si) == 0)
    {
        return (float)(si.totalram - si.freeram) * si.mem_unit
               / 1024 / 1024 / 1024;
    }

    return 0;
}

#endif
