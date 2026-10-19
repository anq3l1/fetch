#pragma once

#include <string>

class User
{
public:
    User() = default;

    static std::string userl();
    static std::string hostname();
    static std::string distro_name();
    static std::string product_name();
    static std::string install_packages();
    static std::string sys_uptime();

    static std::string waymang();

    static std::string shell();

    static std::string kernel();

#ifdef __linux__
    static int osage();
#endif
    static std::string terminal();
};

extern User user;