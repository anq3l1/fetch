#include <iostream>
#include "system.h"
#include <iomanip>
#include "colors.h"

void arch_logo()
{

  std::cout << 
  R"(                            )" << user() << " : " << hostname() << R"(
           /\             ┌──────────────────────────────────────────┐
          /  \              󰇺 Chassis: )" << product_name() << R"(
         /    \             󰣇 OS: )" << distro_name() << R"(
        /      \            󰍹 Resolution: )" << screen_resolution() << R"(
       /   ,,   \            Kernel: )" << kernel_info() << R"(
      /   |  |   \        └──────────────────────────────────────────┘
     /_-''    ''-_\       ┌──────────────────────────────────────────┐
                            󱗃 WM: )" << distr_wm() << R"(
                             Shell: )" << distro_shell() << R"(
                            󰏗 Packages: pacman )" << install_packages() << R"(
                          └──────────────────────────────────────────┘ 
                          ┌──────────────────────────────────────────┐
                             CPU: )" << distro_cpu() << R"(
                            󰊴 GPU: )" << getGpuName() << R"(
                             GPU driver: )" << version_driver_nvidia() << R"(
                             RAM: )" << "" << " / " << std::setprecision(4) << distro_totalram() << " GB" << R"(
                            󱫐 Uptime: )" << sys_uptime() << R"(
                          └──────────────────────────────────────────┘
                            ● ● ● ● ● ● ● ●)" << '\n';
}

void arch_logo2()
{

  std::cout << 
  R"(                            )" << user() << " : " << hostname() << R"(
           /\             ┌──────────────────────────────────────────┐
          /  \              󰇺 Chassis: )" << product_name() << R"(
         /    \             󰣇 OS: )" << distro_name() << R"(
        /      \            󰍹 Resolution: )" << screen_resolution() << R"(
       /   ,,   \            Kernel: )" << kernel_info() << R"(
      /   |  |   \        └──────────────────────────────────────────┘
     /_-''    ''-_\       ┌──────────────────────────────────────────┐
                             CPU: )" << distro_cpu() << R"(
                            󰊴 GPU: )" << getGpuName() << R"(
                             GPU driver: )" << version_driver_nvidia() << R"(
                             RAM: )" << "" << " / " << std::setprecision(4) << distro_totalram() << " GB" << R"(
                            󱫐 Uptime: )" << sys_uptime() << R"(
                          └──────────────────────────────────────────┘
                            ● ● ● ● ● ● ● ●)" << '\n';
}

void arch_logo_color()
{
    std::cout <<
    R"(                            )" 
    << BLUE << user() << RESET 
    << " @ " 
    << BLUE << hostname() << RESET << '\n'

    << CYAN << R"(
           /\             ┌──────────────────────────────────────────┐
          /  \              )" << RESET << RED << " 󰇺 Chassis: " << RESET << product_name() << R"(
         /    \              )" << RED << "󰣇 OS: " << RESET << distro_name() << R"(
        /      \             )" << YELLOW << "󰍹 Resolution: " << RESET << screen_resolution() << R"(
       /   ,,   \            )" << YELLOW << " Kernel: " << RESET << kernel_info() << R"(
      /   |  |   \        └──────────────────────────────────────────┐
     /_-''    ''-_\       ┌──────────────────────────────────────────┐
                            )" << CYAN << "󱗃 WM: " << RESET << distr_wm() << R"(
                            )" << CYAN << " Shell: " << RESET << distro_shell() << R"(
                            )" << CYAN << "󰏗 Packages: pacman " << RESET << install_packages() << R"(
                          └──────────────────────────────────────────┘ 
                          ┌──────────────────────────────────────────┐
                            )" << GREEN << " CPU: " << RESET << distro_cpu() << R"(
                            )" << GREEN << "󰊴 GPU: " << RESET << getGpuName() << R"(
                            )" << GREEN << " GPU driver: " << RESET << version_driver_nvidia() << R"(
                            )" << GREEN << " RAM: " << RESET << "" << " / " << std::setprecision(4) << distro_totalram() << " GB" << R"(
                            )" << GREEN << "󱫐 Uptime: " << RESET << sys_uptime() << R"(
                          └──────────────────────────────────────────┘
                            )"
    << RED << "● " 
    << YELLOW << "● " 
    << BLUE << "● " 
    << CYAN << "● " 
    << GREEN << "● " 
    << RED << "● " 
    << YELLOW << "● " 
    << BLUE << "●" << RESET
    << '\n';
}



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