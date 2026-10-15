#include "system/GPU/gpuinfo.h"

#include <memory>

#include <fstream>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <X11/Xlib.h>
    #include <X11/extensions/Xrandr.h>
#endif

std::string GpuInfo::getGpuName()
{
#ifdef _WIN32
    return "Unknown"; // its function will be later..
#else
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
#endif
}

std::string GpuInfo::version_driver_nvidia()
{
#ifdef _WIN32
    return "Unkonwn";
#else
    std::ifstream file("/sys/class/drm/card0/device/driver/module/version");
    std::string line;
    std::string version;

    if (std::getline(file, line)) {
        version = "nvidia " + line;
    }

    return version;
#endif
}

std::string GpuInfo::resolution()
{
#ifdef _WIN32
    DEVMODEA mode{};
    mode.dmSize = sizeof(mode);

    if (!EnumDisplaySettingsA(nullptr, ENUM_CURRENT_SETTINGS, &mode))
        return {};

    return std::to_string(mode.dmPelsWidth) + "x" +
           std::to_string(mode.dmPelsHeight);
#else
    Display* display = XOpenDisplay(nullptr);
    if (!display)
        return {};

    const Window root = DefaultRootWindow(display);
    XRRScreenResources* resources = XRRGetScreenResourcesCurrent(display, root);

    if (!resources) {
        XCloseDisplay(display);
        return {};
    }

    // Сначала ищем основной монитор.
    RROutput output = XRRGetOutputPrimary(display, root);
    XRROutputInfo* outputInfo =
        output ? XRRGetOutputInfo(display, resources, output) : nullptr;

    // Если основной монитор не определён, берём первый подключённый.
    if (!outputInfo || outputInfo->connection != RR_Connected) {
        if (outputInfo)
            XRRFreeOutputInfo(outputInfo);

        outputInfo = nullptr;

        for (int i = 0; i < resources->noutput; ++i) {
            XRROutputInfo* candidate =
                XRRGetOutputInfo(display, resources, resources->outputs[i]);

            if (candidate && candidate->connection == RR_Connected &&
                candidate->crtc != None) {
                outputInfo = candidate;
                break;
            }

            if (candidate)
                XRRFreeOutputInfo(candidate);
        }
    }

    std::string result;

    if (outputInfo && outputInfo->crtc != None) {
        XRRCrtcInfo* crtc =
            XRRGetCrtcInfo(display, resources, outputInfo->crtc);

        if (crtc) {
            result = std::to_string(crtc->width) + "x" +
                     std::to_string(crtc->height);
            XRRFreeCrtcInfo(crtc);
        }
    }

    if (outputInfo)
        XRRFreeOutputInfo(outputInfo);

    XRRFreeScreenResources(resources);
    XCloseDisplay(display);
    return result;
#endif
}