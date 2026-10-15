
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

#include "colors.h"
#include "system/GPU/gpuinfo.h"
#include "system/CPU/cpu.hpp"
#include "system/memory/memory.hpp"
#include "system/user/user.hpp"
#include "logos.h"

std::vector<std::string> parse_logo(const std::string& logo)
{
    std::vector<std::string> lines;
    std::istringstream stream(logo);
    std::string line;

    while (std::getline(stream, line))
        lines.push_back(line);

    while (!lines.empty() && lines.front().find_first_not_of(" \t") == std::string::npos)
        lines.erase(lines.begin());

    while (!lines.empty() && lines.back().find_first_not_of(" \t") == std::string::npos)
        lines.pop_back();

    return lines;
}

std::string get_logo(const std::string& distro)
{
    if (distro == "Arch Linux")
        return arch;

    if (distro == "Microsoft Windows")
        return windows;

    return "Unknown Linux distribution";
}

void print_fetch()
{
    std::vector<std::string> logo = parse_logo(get_logo(User::distro_name()));

    std::vector<std::string> info = {
        std::string(BLUE) + User::userl() + RESET + " @ " +
            BLUE + User::hostname() + RESET,
        "┌──────────────────────────────────────────┐",
        "  󰇺 Chassis: " + User::product_name(),
        "  󰣇 OS: " + User::distro_name(),
        "  󰍹 Resolution: " + GpuInfo::resolution(),
        "   Kernel: " + User::kernel(),
        "  󱗃 WM: " + User::waymang(),
        "   Shell: " + User::shell(),
        "  󰏗 Packages: " + User::install_packages(),
        "└──────────────────────────────────────────┘",
        "┌──────────────────────────────────────────┐",
        "   CPU: " + CPU::distro_cpu(),
        "  󰊴 GPU: " + GpuInfo::getGpuName(),
        "   GPU driver: " + GpuInfo::version_driver_nvidia(),
        "   RAM: " + std::to_string(Ram::usedram()) +
            " / " + std::to_string(Ram::totalram()) + " GB",
        "   Disk: " + std::to_string(Disk::disk_memory()) + " GB",
        "  󱫐 Uptime: " + User::sys_uptime(),
        "└──────────────────────────────────────────┘",
        std::string(RED) + "● " + YELLOW + "● " + BLUE + "● " +
            CYAN + "● " + GREEN + "● " + RED + "● " +
            YELLOW + "● " + BLUE + "●" + RESET
    };

    if (logo.empty())
        return;

    const std::size_t logo_width = std::max_element(
        logo.begin(), logo.end(),
        [](const std::string& a, const std::string& b)
        {
            return a.size() < b.size();
        }
    )->size();

    const std::size_t lines = std::max(logo.size(), info.size());

    for (std::size_t i = 0; i < lines; ++i)
    {
        std::string logo_line = i < logo.size() ? logo[i] : "";

        std::cout << CYAN << logo_line << RESET;

        std::cout << std::string(
            logo_width - logo_line.size() + 4, ' '
        );

        if (i < info.size())
            std::cout << info[i];

        std::cout << '\n';
    }
}
