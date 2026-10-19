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

int main(int argc, char* argv[])
{
    if (argc == 1)
    {
        print_fetch();
    }
}
