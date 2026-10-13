#pragma once

#include <string>

class User
{
public:
    User() = default;

    std::string userl();
    std::string hostname();
    std::string distro_name();
    std::string product_name();
    std::string install_packages();
    std::string sys_uptime();

    std::string waymang();

    std::string shell();

    std::string kernel();
};

extern User user;