#pragma once

#include <string>

class GpuInfo
{
public:
    GpuInfo() = default;

   static std::string getGpuName();

   static std::string version_driver_nvidia();

   static std::string resolution();
};
