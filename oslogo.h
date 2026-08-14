#ifndef OSLOGO_H
#define OSLOGO_H

#include <iostream>

std::string distro_name();
std::string kernel_info();
std::string distro_cpu();
std::string getGpuName();
float distro_ram();
float distro_totalram();
int sys_uptime();

void arch_logo()
{
    std::cout << R"(          /\
         /  \               OS:      )" << distro_name() << R"(
        /    \              Kernel:  )" << kernel_info() << R"(
       /      \             CPU:     )" << distro_cpu() << R"(
      /   ,,   \            GPU:     )" << getGpuName() << R"(
     /   |  |   \           RAM:     )" << distro_ram() << " / " << distro_totalram() << " GB"<< R"(
    /_-''    ''-_\          Uptime:  )" << sys_uptime() << " min" << R"(
                            
                            ● ● ● ● ● ● ● ●)" << '\n';
}


// ___________    
//|_          \   
//  | | _____ | 
//  | | | | | |    
//  | | | | | | 
//  | \_____/ |   
//  \_________/ 


//        ,'''''.    
//       |   ,.  |   
//       |  |  '_'   
//  ,....|  |..      
//.'  ,_;|   ..'     
//|  |   |  |        
//|  ',_,'  |         
// '.     ,'         
//   '''''    

#endif
