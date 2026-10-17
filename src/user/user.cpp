#include <iostream>
#include <fstream>
#include <memory>
#include "system/user/user.hpp"
#include <cstdio>
#include <memory>
#include <string>
#include <vector>

#include <chrono>

#ifdef __linux__
#include <sys/utsname.h>
#include <sys/sysinfo.h>
#endif

#ifdef _WIN32
#include <windows.h>
#include <intrin.h>
#endif

#include <unistd.h>

#ifndef _WIN32
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
#endif

std::string User::distro_name()
{
#ifdef _WIN32
    return "Microsoft Windows";
#else
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
#endif
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
#ifdef _WIN32
    char product_name[256] = {};
    DWORD size = sizeof(product_name);

    if (RegGetValueA(HKEY_LOCAL_MACHINE,
                     "HARDWARE\\DESCRIPTION\\System\\BIOS",
                     "SystemProductName",
                     RRF_RT_REG_SZ | RRF_RT_REG_EXPAND_SZ,
                     nullptr,
                     product_name,
                     &size) != ERROR_SUCCESS)
    {
        return "";
    }

    return product_name;
#else
    std::ifstream file("/sys/class/dmi/id/product_name");

    if(!file.is_open())
        return "";
    
    std::string line;
    std::string product_name;

    if (std::getline(file, line)) {
        product_name = line;
    }

    return product_name;
#endif
}

#ifndef _WIN32
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
#else
std::string User::install_packages()
{
    return "N/A";
}
#endif

std::string User::sys_uptime()
{
    int uptime = 0;
#ifndef _WIN32
    struct sysinfo si;

    if(sysinfo(&si) == 0)
    {
        uptime = si.uptime / 60; 
    }
#endif
#ifdef _WIN32

    uptime = GetTickCount64() / 1000;

#endif
    std::string line_uptime = "";
    int hours = uptime / 60;
    int minutes = uptime % 60;

    if(hours == 0)
        line_uptime = std::to_string(minutes) + " min.";
    else                     
        line_uptime = std::to_string(hours) + "h " + std::to_string(minutes) + "min.";

    return line_uptime;
}

std::string User::waymang()
{
#ifdef _WIN32
    return "Desktop Window Manager";
#else
    const char* desktop = std::getenv("XDG_CURRENT_DESKTOP");
    return desktop ? desktop : "Unknown";
#endif
}

std::string User::shell()
{
#ifdef _WIN32
    const char* shell = std::getenv("COMSPEC");
    return shell ? shell : "cmd.exe";
#else
    pid_t ppid = getppid();
    std::ifstream file("/proc/" + std::to_string(ppid) + "/comm");
    std::string name;

    std::getline(file, name);
    
    return name;
#endif
}

std::string User::kernel()
{
#ifdef _WIN32
    OSVERSIONINFOA version{};
    version.dwOSVersionInfoSize = sizeof(version);
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4996)
#endif
    if (GetVersionExA(&version)) {
        return std::to_string(version.dwMajorVersion) + "." + std::to_string(version.dwMinorVersion) +
               " (build " + std::to_string(version.dwBuildNumber) + ")";
    }
#ifdef _MSC_VER
#pragma warning(pop)
#endif
    return "Windows";
#else

    struct utsname buffer;
    std::string release;

    if(uname(&buffer) == 0)
    {
        release = buffer.release;
    }

    return release;
#endif
}

#ifdef __linux__
int User::osage()
{
    long long time = 0;

    std::shared_ptr<FILE> pipe(popen("stat -c %W /", "r"), pclose);
    char buffer[64];

    if(fgets(buffer, sizeof(buffer), pipe.get()) != nullptr) {
        time = std::stoll(buffer);
    }

    if (time <= 0)
    return 0;

    auto now = std::chrono::system_clock::now();
    auto installDate = std::chrono::system_clock::from_time_t(time);

    auto age = now - installDate;

    auto days = std::chrono::duration_cast<std::chrono::days>(age).count();

    return days;
}
#endif
