#include <iostream>
#include "system.h"


void arch_logo()
{
    std::cout << R"(          /\
         /  \               OS:      )" << distro_name() << R"(
        /    \              Kernel:  )" << kernel_info() << R"(
       /      \             WM:      )" << distr_wm() << R"(
      /   ,,   \            Shell:   )" << distro_shell() << R"(
     /   |  |   \           CPU:     )" << distro_cpu() << R"(
    /_-''    ''-_\          GPU:     )" << getGpuName() << R"(
                            RAM:     )" << distro_ram() << " / " << distro_totalram() << " GB" << R"(
                            Uptime:  )" << sys_uptime_hours() << " h " << sys_uptime_minute() << R"( min

                            ● ● ● ● ● ● ● ●)" << '\n';
}


void mint_logo()
{
    std::cout << R"(___________                 OS:      )" << distro_name() << R"(
|_          \               Kernel:  )" << kernel_info() << R"(
  | | _____ |               WM:      )" << distr_wm() << R"(
  | | | | | |               Shell:   )" << distro_shell() << R"(
  | | | | | |               CPU:     )" << distro_cpu() << R"(
  | \_____/ |               GPU:     )" << getGpuName() << R"(
  \_________/               RAM:     )" << distro_ram() << " / " << distro_totalram() << " GB" << R"(
                            Uptime:  )" << sys_uptime_hours() << " h " << sys_uptime_minute() << R"( min

                            ● ● ● ● ● ● ● ●)" << '\n';
}


void fedora_logo()
{
    std::cout << R"(      ,'''''.                 OS:      )" << distro_name() << R"(
     |   ,.  |                 Kernel:  )" << kernel_info() << R"(
     |  |  '_'                 WM:      )" << distr_wm() << R"(
,....|  |..                    Shell:   )" << distro_shell() << R"(
.'  ,_;|   ..'                 CPU:     )" << distro_cpu() << R"(
|  |   |  |                    GPU:     )" << getGpuName() << R"(
|  ',_,'  |                    RAM:     )" << distro_ram() << " / " << distro_totalram() << " GB" << R"(
 '.     ,'                     Uptime:  )" << sys_uptime_hours() << " h " << sys_uptime_minute() << R"( min
   ''''

                            ● ● ● ● ● ● ● ●)" << '\n';
}