#include <iostream>
#include <sys/sysinfo.h>
#include <fstream>
#include <string>
#include <sstream>
#include <sys/utsname.h>
#include <memory>
#include "oslogo.h"
#include "system.h"
#include "colors.h"

std::string configPars(const std::string& found_line)
{
    std::ifstream file("config/config.conf");

    if(!file)
    {
        std::cerr << "Failed to open config.conf\n";
    }

    std::string line;

    while (std::getline(file, line))
    {
        size_t pos = line.find(found_line);

        if (pos == std::string::npos)
            continue;

        return line.substr(pos + found_line.length());
    }

    if(line != "true" || line != "false")
        std::cerr << RED << "[!] Error check your config file!\n";

    return "";
}