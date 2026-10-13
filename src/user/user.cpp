#include <iostream>
#include <fstream>
#include <memory>
#include "system/user/user.hpp"
#include <cstdio>
#include <memory>
#include <string>
#include <vector>
#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include <unistd.h>

std::string what_is_distro()
{
    std::vector<std::string> distros = {
        "arch",
        "fedora",
        "mint",
        "ubuntu",
        "debian",
        "kali",
        "fedora",
        "manjaro",
        "pop"
    };

    struct utsname buffer;
    if (uname(&buffer) != std::string::npos) 
    {
        std::string release = buffer.release;

        for(auto& distr : distros)
        {
            if(release.find(distr))
                return distr;
        }
    }

    return "";
}

std::string User::distro_name()
{
    std::ifstream file("/etc/os-release");
    std::string line;
    std::string name;

    while(std::getline(file, line))
    {
        if(line.find("PRETTY_NAME=") == 0)
            name = line.substr(12);
    }

    if (name.size() >= 2 &&
        name.front() == '"' && 
        name.back() == '"')
        {
            name = name.substr(1, name.size() - 2);
        }
        
    
    return name;
}

std::string User::hostname()
{
    std::ifstream file("/etc/hostname");
    std::string hostname;

    file >> hostname;

    return hostname;
}

std::string User::userl()
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

std::string User::product_name()
{
    std::ifstream file("/sys/class/dmi/id/product_name");

    if(!file.is_open())
        return "";
    
    std::string line;
    std::string product_name;

    if (std::getline(file, line)) {
        product_name = line;
    }

    return product_name;
}

std::string User::install_packages()
{
    const std::string distro = what_is_distro();
    std::string command;

    if (distro == "arch" ||
        distro == "manjaro" ||
        distro == "endeavouros")
    {
        command = "pacman -Qq | wc -l";
    }
    else if (distro == "debian" ||
             distro == "ubuntu" ||
             distro == "mint" ||
             distro == "pop")
    {
        command = "dpkg-query -W -f='${binary:Package}\\n' "
                  "2>/dev/null | wc -l";
    }
    else if (distro == "fedora" ||
             distro == "rhel" ||
             distro == "opensuse")
    {
        command = "rpm -qa --qf '%{NAME}\\n' | wc -l";
    }
    else if (distro == "alpine")
    {
        command = "apk info | wc -l";
    }
    else if (distro == "void")
    {
        command = "xbps-query -l | wc -l";
    }
    else if (distro == "gentoo")
    {
        command = "qlist -I | wc -l";
    }
    else
    {
        return "N/A";
    }

    std::shared_ptr<FILE> pipe(
        popen(command.c_str(), "r"),
        pclose
    );

    if (!pipe)
        return "N/A";

    char buffer[64] = {};

    if (fgets(buffer, sizeof(buffer), pipe.get()) == nullptr)
        return "N/A";

    std::string result(buffer);

    if (!result.empty() && result.back() == '\n')
        result.pop_back();

    return result;
}

std::string User::sys_uptime()
{
    struct sysinfo si;

    int uptime = 0;

    if(sysinfo(&si) == 0)
    {
        uptime = si.uptime / 60; 
    }

    int hours = uptime / 60;
    int minutes = uptime % 60;

    std::string line_uptime = std::to_string(hours) + "h " +
                              std::to_string(minutes) + "min.";

    return line_uptime;
}

std::string User::waymang()
{
    const char* desktop = std::getenv("XDG_CURRENT_DESKTOP");

    if (desktop != nullptr && *desktop != '\0')
        return desktop;

    return "Unknown";
}

std::string User::shell()
{
    pid_t ppid = getppid();
    std::ifstream file("/proc/" + std::to_string(ppid) + "/comm");
    std::string name;

    std::getline(file, name);
    
    return name;
}

std::string User::kernel()
{
    struct utsname buffer;
    std::string release;

    if(uname(&buffer) == 0)
    {
        release = buffer.release;
    }

    return release;
}