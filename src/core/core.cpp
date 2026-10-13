#include <iostream>

std::string getOS()
{
#if defined(__linux__)
    return "Linux";
#elif defined(_WIN32)
    return "Windows";
#elif defined(__APPLE__)
    return "macOS";
#else
    return "Unknown";
#endif
}
