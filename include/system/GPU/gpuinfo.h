#pragma once

#include <string>

class GpuInfo
{
public:
    GpuInfo() = default;

   std::string getGpuName();

   std::string version_driver_nvidia();

   std::string resolution();
};
