#include <iostream>
#include <sys/sysinfo.h>
#include <fstream>
#include <string>
#include <sstream>
#include <sys/utsname.h>
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
        if (configPars("minimalism = ") == false)
        {
            if (configPars("colorate = ") == true)
            {
                print_fetch_linux();
            }
        } 
    }
}
