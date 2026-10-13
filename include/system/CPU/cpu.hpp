#pragma once

#include <string>

class CPU
{
public:
    CPU() = default;

    static std::string distro_cpu();
};