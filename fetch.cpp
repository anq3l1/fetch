#include <iostream>
#include <sys/sysinfo.h>
#include <fstream>
#include <string>
#include <sstream>
#include <sys/utsname.h>
#include <memory>
#include "oslogo.h"
#include "system.h"

std::string nodename()
{
    struct utsname buffer;

    if (uname(&buffer) == 0)
        return buffer.nodename;

    return "";
}

int main()
{
    struct utsname buffer;

    if(nodename() == "arch")
        arch_logo();
    
    return 0;
}
