#include <iostream>
#include <sys/sysinfo.h>
#include <fstream>
#include <string>
#include <sstream>
#include <sys/utsname.h>
#include <memory>
#include "oslogo.h"
#include "system.h"
#include "config.h"

int main(int argc, char* argv[])
{ 
    if(argc == 1)
    {
        if(configPars("minimalism = ") == "false")
        {
            if(distro_name() == "Arch Linux" && configPars("colorate = ") == "false")
                arch_logo();
            else if(distro_name() == "Arch Linux" && configPars("colorate = ") == "true")
                arch_logo_color();
            //else if(distro_name() == "Fedora Linux")
                //fedora_logo();

            //else if(distro_name() == "Linux Mint")
                //mint_logo();
        }
        else if(configPars("minimalism = ") == "true")
        {
            if(distro_name() == "Arch Linux")
                arch_logo2();

            //else if(distro_name() == "Fedora Linux")
                //fedora_logo();

            //else if(distro_name() == "Linux Mint")
                //mint_logo();
        }

    }
    else if(argc > 1)
    {
        if(std::string(argv[1]) == "--arch-logo")
            arch_logo();
        //if(std::string(argv[1]) == "--fedora-logo")
        //    fedora_logo();
        //if(std::string(argv[1]) == "--mint-logo")
        //    mint_logo();
    }

    return 0;
}
