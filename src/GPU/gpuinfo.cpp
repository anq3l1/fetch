#include "system/GPU/gpuinfo.h"

#include <memory>

#include <fstream>

std::string GpuInfo::getGpuName()
{
    std::string gpuname = "";
    std::shared_ptr<FILE> pipe(popen("lspci | grep -E 'VGA|3D|Display'", "r"), pclose);
    char buffer[128];
    if (fgets(buffer, sizeof(buffer), pipe.get()) != nullptr) {
        gpuname = buffer;
    }
    size_t pos = gpuname.find("[GeForce");
    if (pos != std::string::npos) {
        gpuname = gpuname.substr(pos);
    }
    if (!gpuname.empty() && gpuname.back() == '\n') {
        gpuname.pop_back();
    }
    return gpuname;
}

std::string GpuInfo::version_driver_nvidia()
{
    std::ifstream file("/sys/class/drm/card0/device/driver/module/version");
    std::string line;
    std::string version;

    if (std::getline(file, line)) {
        version = "nvidia " + line;
    }

    return version;
}

std::string GpuInfo::resolution()
{
    std::ifstream file("/sys/class/graphics/fb0/subsystem/fb0/modes");
    std::string resolution = "";

    file >> resolution;
    
    return resolution;
}