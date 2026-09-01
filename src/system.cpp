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
#include <format>
#include <vector>


std::string getGpuName() 
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

std::string sys_uptime()
{
    struct sysinfo si;

    int uptime = 0;

    if(sysinfo(&si) == 0)
    {
        uptime = si.uptime / 60;
    }

    int hours = uptime / 60;
    int minutes = uptime % 60;

    std::string line_uptime = std::format("{}h {}min.", hours, minutes);

    return line_uptime;
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

float distro_totalram()
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
    std::ifstream file("/proc/meminfo");

    std::string line = "";
    std::string result = "";

    float mem_total = distro_totalram();

    while(std::getline(file, line))
    {
        if(line.rfind("MemAvailable:", 0) == 0)
            result = line.substr(13);
    };
    
    float mem_available = std::stof(result) / 1024.0 / 1024.0;
    
    return mem_total - mem_available;
}

std::string install_packages()
{
    std::string result = "";
    std::shared_ptr<FILE> pipe(popen("pacman -Q | wc -l ", "r"), pclose);
    char buffer[12];

    if (fgets(buffer, sizeof(buffer), pipe.get()) != nullptr) {
        result = buffer;
    }

    if (!result.empty() && result.back() == '\n') {
        result.pop_back();
    }

    return result;
}

std::string screen_resolution()
{
    std::ifstream file("/sys/class/graphics/fb0/subsystem/fb0/modes");
    std::string resolution = "";

    file >> resolution;
    
    return resolution;
}

std::string product_name()
{
    std::ifstream file("/sys/class/dmi/id/product_name");
    std::string line;
    std::string product_name;

    if (std::getline(file, line)) {
        product_name = line;
    }

    return product_name;
}

std::string version_driver_nvidia()
{
    std::ifstream file("/sys/class/drm/card0/device/driver/module/version");
    std::string line;
    std::string version;

    if (std::getline(file, line)) {
        version = "nvidia " + line;
    }

    return version;
}

std::string hostname()
{
    std::ifstream file("/etc/hostname");
    std::string hostname;

    file >> hostname;

    return hostname;
}

std::string user()
{
    std::string user = "";

    std::shared_ptr<FILE> pipe(popen("whoami", "r"), pclose);
    char buffer[64];

    if(fgets(buffer, sizeof(buffer), pipe.get()) != nullptr) {
        user = buffer;
    }
    if(!user.empty() && user.back() == '\n')
            user.pop_back();
    
    return user;
}

long long show_disk()
{
    std::ifstream file("/sys/block/nvme0n1/size");

    long long sectors;
    file >> sectors;

    return (sectors * 512) / (1024.0 * 1024.0 * 1024.0);
}