#include <iostream>
#include <iomanip>
#include "colors.h"
#include "system/GPU/gpuinfo.h"
#include "system/CPU/cpu.hpp"
#include "system/memory/memory.hpp"
#include "system/user/user.hpp"

GpuInfo gpu;
User user;
Ram ram;
Disk disk;
CPU cpu;

void arch_logo()
{

  std::cout << 
  R"(                            )" << user.userl() << " : " << user.hostname() << R"(
           /\             ┌──────────────────────────────────────────┐
          /  \              󰇺 Chassis: )" << user.product_name() << R"(
         /    \             󰣇 OS: )" << user.distro_name() << R"(
        /      \            󰍹 Resolution: )" << gpu.resolution() << R"(
       /   ,,   \            Kernel: )" << user.kernel() << R"(
      /   |  |   \        └──────────────────────────────────────────┘
     /_-''    ''-_\       ┌──────────────────────────────────────────┐
                            󱗃 WM: )" << user.waymang() << R"(
                             Shell: )" << user.shell() << R"(
                            󰏗 Packages: pacman )" << user.install_packages() << R"(
                          └──────────────────────────────────────────┘ 
                          ┌──────────────────────────────────────────┐
                             CPU: )" << cpu.distro_cpu() << R"(
                            󰊴 GPU: )" << gpu.getGpuName() << R"(
                             GPU driver: )" << gpu.version_driver_nvidia() << R"(
                             RAM: )" << std::setprecision(3) << ram.usedram() << " / " << std::setprecision(4) << ram.totalram() << " GB" << R"(
                             Disk: )" << disk.disk_memory() << " GB" << R"(
                            󱫐 Uptime: )" << user.sys_uptime() << R"(
                          └──────────────────────────────────────────┘
                            ● ● ● ● ● ● ● ●)" << '\n';
}

//void arch_logo2()
//{
//
//  std::cout << 
//  R"(                            )" << user() << " : " << hostname() << R"(
//           /\             ┌──────────────────────────────────────────┐
//          /  \              󰇺 Chassis: )" << product_name() << R"(
//         /    \             󰣇 OS: )" << distro_name() << R"(
//        /      \            󰍹 Resolution: )" << screen_resolution() << R"(
//       /   ,,   \            Kernel: )" << kernel_info() << R"(
//      /   |  |   \        └──────────────────────────────────────────┘
//     /_-''    ''-_\       ┌──────────────────────────────────────────┐
//                             CPU: )" << distro_cpu() << R"(
//                            󰊴 GPU: )" << gpu.getGpuName() << R"(
//                             GPU driver: )" << gpu.version_driver_nvidia() << R"(
//                             RAM: )" << std::setprecision(4) << distro_ram() << " / " << std::setprecision(4) << distro_totalram() << " GB" << R"(
//                            󱫐 Uptime: )" << sys_uptime() << R"(
//                          └──────────────────────────────────────────┘
//                            ● ● ● ● ● ● ● ●)" << '\n';
//}
//
//void arch_logo_color()
//{
//    std::cout <<
//    R"(                            )" 
//    << BLUE << user() << RESET 
//    << " @ " 
//    << BLUE << hostname() << RESET << '\n'
//
//    << CYAN << R"(
//           /\             ┌──────────────────────────────────────────┐
//          /  \              )" << RESET << RED << " 󰇺 Chassis: " << RESET << product_name() << R"(
//         /    \              )" << RED << "󰣇 OS: " << RESET << distro_name() << R"(
//        /      \             )" << YELLOW << "󰍹 Resolution: " << RESET << screen_resolution() << R"(
//       /   ,,   \            )" << YELLOW << " Kernel: " << RESET << kernel_info() << R"(
//      /   |  |   \        └──────────────────────────────────────────┐
//     /_-''    ''-_\       ┌──────────────────────────────────────────┐
//                            )" << CYAN << "󱗃 WM: " << RESET << distr_wm() << R"(
//                            )" << CYAN << " Shell: " << RESET << distro_shell() << R"(
//                            )" << CYAN << "󰏗 Packages: pacman " << RESET << install_packages() << R"(
//                          └──────────────────────────────────────────┘ 
//                          ┌──────────────────────────────────────────┐
//                            )" << GREEN << " CPU: " << RESET << distro_cpu() << R"(
//                            )" << GREEN << "󰊴 GPU: " << RESET << gpu.getGpuName() << R"(
//                            )" << GREEN << " GPU driver: " << RESET << gpu.version_driver_nvidia() << R"(
//                            )" << GREEN << " RAM: " << RESET << std::setprecision(3) << distro_ram() << " / " << std::setprecision(4) << distro_totalram() << " GB" << R"(
//                            )" << GREEN << " Disk: " << RESET << show_disk() << " GB" << R"(
//                            )" << GREEN << "󱫐 Uptime: " << RESET << sys_uptime() << R"(
//                          └──────────────────────────────────────────┘
//                            )"
//    << RED << "● " 
//    << YELLOW << "● " 
//    << BLUE << "● " 
//    << CYAN << "● " 
//    << GREEN << "● " 
//    << RED << "● " 
//    << YELLOW << "● " 
//    << BLUE << "●" << RESET
//    << '\n';
//}



//      /\  
//     /  \        
//    /    \       
//   /      \      
//  /   ,,   \     
// /   |  |   \    
///_-''    ''-_\   


//void mint_logo()
//{
//    std::cout << R"(___________                 OS:      )" << distro_name() << R"(
//|_          \               Kernel:  )" << kernel_info() << R"(
//  | | _____ |               WM:      )" << distr_wm() << R"(
//  | | | | | |               Shell:   )" << distro_shell() << R"(
//  | | | | | |               CPU:     )" << distro_cpu() << R"(
//  | \_____/ |               GPU:     )" << getGpuName() << R"(
//  \_________/               RAM:     )" << distro_ram() << " / " << distro_totalram() << " GB" << R"(
//                            Uptime:  )" << sys_uptime_hours() << " h " << sys_uptime_minute() << R"( min
//
//                            ● ● ● ● ● ● ● ●)" << '\n';
//}
//
//
//void fedora_logo()
//{
//    std::cout << R"(        ,'''''.                OS:      )" << distro_name() << R"(
//       |   ,.  |               Kernel:  )" << kernel_info() << R"(
//       |  |  '_'               WM:      )" << distr_wm() << R"(
//  ,....|  |..                  Shell:   )" << distro_shell() << R"(
//.'  ,_;|   ..'                 CPU:     )" << distro_cpu() << R"(
//|  |   |  |                    GPU:     )" << getGpuName() << R"(
//|  ',_,'  |                    RAM:     )" << distro_ram() << " / " << distro_totalram() << " GB" << R"(
// '.     ,'                     Uptime:  )" << sys_uptime_hours() << " h " << sys_uptime_minute() << R"( min
//   ''''
//
//                            ● ● ● ● ● ● ● ●)" << '\n';
//}