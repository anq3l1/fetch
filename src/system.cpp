#include <iostream>
#include <sys/sysinfo.h>
#include <fstream>
#include <string>
#include <sstream>
#include <sys/utsname.h>
#include <memory>
#include <unistd.h>
#include "config.h"
#include "system.h"

std::string getGpuName() 
{
    if(configPars("show_gpu = ") == "true")
    {
        std::string result = "";
        std::shared_ptr<FILE> pipe(popen("lspci | grep -E 'VGA|3D|Display'", "r"), pclose);
        
        char buffer[128];
        if (fgets(buffer, sizeof(buffer), pipe.get()) != nullptr) {
            result = buffer;
        }

        size_t pos = result.find("[GeForce");
        if (pos != std::string::npos) {
            result = result.substr(pos);
        }

        if (!result.empty() && result.back() == '\n') {
            result.pop_back();
        }

        return result;
    }
    else if(configPars("show_gpu = ") == "false")
        return "-------------------------------";
    else
        return NULL;
}

int sys_uptime_minute()
{
    struct sysinfo si;
    int uptime = 0;

    if(sysinfo(&si) == 0)
    {
        uptime = si.uptime / 60;
    }

    return uptime;
}

int sys_uptime_hours()
{
    struct sysinfo si;
    int uptime = 0;

    if(sysinfo(&si) == 0)
    {
        uptime = si.uptime / 60 / 60;
    }

    return uptime;
}


std::string distr_wm()
{
    std::string result = "";
    std::shared_ptr<FILE> pipe(popen("echo $XDG_CURRENT_DESKTOP", "r"), pclose);
    char buffer[12];
    if (fgets(buffer, sizeof(buffer), pipe.get()) != nullptr) {
        result = buffer;
    }

    if (!result.empty() && result.back() == '\n') {
        result.pop_back();
    }

    return result;
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
    if(configPars("show_cpu = ") == "true")
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
    else if(configPars("show_cpu = ") == "false")
        return "-------------------------------";
    else
        return NULL;
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

std::string distro_shell()
{
    pid_t ppid = getppid();

    std::ifstream file("/proc/" + std::to_string(ppid) + "/comm");

    std::string name;
    std::getline(file, name);

    return name;
    
}

float distro_ram()
{
    struct sysinfo si;

    if(sysinfo(&si) == 0)
    {
        return (float)(si.totalram - si.freeram)
               / 1024 / 1024 / 1024 / 2;
    }

    return 0;
}
