#include <iostream>

#ifdef __linux__
#include <sys/sysinfo.h>
#include <sys/utsname.h>
#endif

#include <fstream>
#include <string>
#include <sstream>
#include <memory>
#include "oslogo.h"
#include "config.h"
#include "system/user/user.hpp"

std::string getOS()
{
#if defined(__linux__)
    return "Linux";
#elif defined(_WIN32)
    return "Windows";
#elif defined(__APPLE__)
    return "macOS";
#else
    return "Unknown";
#endif
}

int main(int argc, char* argv[])
{
    if (argc == 1 && getOS() == "Linux")
    {
        print_fetch();
    }
}
