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
#include "colors.h"

bool configPars(const std::string& found_line)
{
    std::ifstream file("config.conf");

    if (!file)
        return false;

    std::string line;

    while (std::getline(file, line))
    {
        size_t pos = line.find(found_line);

        if (pos == std::string::npos)
            continue;

        std::string value =
            line.substr(pos + found_line.length());

        size_t first = value.find_first_not_of(" \t");

        if (first == std::string::npos)
            return false;

        value = value.substr(first);

        if (value == "true")
            return true;

        if (value == "false")
            return false;

        return false;
    }

    return false;
}
