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

User usr;

int main(int argc, char* argv[])
{
    if (argc == 1)
    {
        if (configPars("minimalism = ") == false)
        {
            if (usr.distro_name() == "Arch Linux" &&
                configPars("colorate = ") == true)
            {
                print_fetch_linux();
            }
        } 
    }
}
