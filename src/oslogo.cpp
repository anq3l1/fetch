#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <filesystem>

#include "colors.h"
#include "system/GPU/gpuinfo.h"
#include "system/CPU/cpu.hpp"
#include "system/memory/memory.hpp"
#include "system/user/user.hpp"
#include "logos.h"

std::string indecation(bool up)
{

#ifdef __linux__
    if(up == true)    
        return std::string(GREY) + "┌──────────────────────────────────────────┐" + RESET;
    else
        return std::string(GREY) + "└──────────────────────────────────────────┘" + RESET;
#endif
    return "";
}

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

    if (distro == "Fedora" || distro == "Fedora Linux")
        return fedora;

    if (distro == "Ubuntu" || distro == "Ubuntu Linux")
        return ubuntu;
    
    return "Unknown Linux distribution";
}

namespace fs = std::filesystem;

std::string getPicFromFolder()
{
    if(User::distro_name() == "Arch Linux" || User::terminal() == "Kitty" && User::waymang() == "Hyprland")
    {
        const char* home = std::getenv("HOME");
        if (!home)
            return "";

        fs::path folder = fs::path(home) / ".config" / "fetch" / "logo";
        std::error_code ec;
        if (!fs::is_directory(folder, ec))
            return "";

        for (const auto& entry : fs::directory_iterator(folder, ec))
        {
            if (ec)
                break;

            if (!entry.is_regular_file(ec) || ec)
                continue;

            std::string ext = entry.path().extension().string();

            std::transform(ext.begin(), ext.end(), ext.begin(),
                [](unsigned char c) { return std::tolower(c); });

            if (ext == ".png" || ext == ".jpg" ||
                ext == ".jpeg" || ext == ".webp" ||
                ext == ".gif")
            {
                return entry.path().string();
            }
        }
    }
    return "";
}

std::string shellQuote(const std::string& str)
{
    std::string result = "'";

    for (char c : str)
    {
        if (c == '\'')
            result += "'\\''";
        else
            result += c;
    }

    return result + "'";
}

bool printImage(const std::string& path)
{
    if (path.empty())
        return false;

    std::cout << "\n\n" << std::flush;

    std::string command =
        "kitty +kitten icat --place 30x15@1x1 " +
        shellQuote(path);

    int result = std::system(command.c_str());

    // Перемещаем курсор ниже картинки.
    std::cout << "\033[16;1H" << std::flush;

    return result == 0;
}

void print_fetch()
{
    std::cout << "\033[2J\033[H" << std::flush;
    
    std::vector<std::string> logo = parse_logo(get_logo(User::distro_name()));

    std::vector<std::string> info = {
        std::string(BLUE) + User::userl() + RESET + " @ " +
            BLUE + User::hostname() + RESET,
        indecation(true),
        "  󰇺 Chassis: " + User::product_name(),
        "  󰣇 OS: " + User::distro_name(),
        "  󰍹 Resolution: " + GpuInfo::resolution(),
        "   Kernel: " + User::kernel(),
        "  󱗃 WM: " + User::waymang(),
        "   Shell: " + User::shell(),
    #ifdef __linux__
        "  󰆍 Terminal: " + User::terminal(),
    #endif
        "  󰏗 Packages: " + User::install_packages(),
        indecation(false),
        indecation(true),
        "   CPU: " + CPU::distro_cpu(),
        "  󰊴 GPU: " + GpuInfo::getGpuName(),
        "   GPU driver: " + GpuInfo::version_driver_nvidia(),
        "   RAM: " + std::to_string(Ram::usedram()) +
            " / " + std::to_string(Ram::totalram()) + " GB",
        "   Disk: " + std::to_string(Disk::disk_memory()) + " GB",
        "  󱫐 Uptime: " + User::sys_uptime(),
        "  󱫐 OS Age: " + std::to_string(User::osage()) + " Days",
        indecation(false),
#ifdef __linux__
        std::string(RED) + "● " + YELLOW + "● " + BLUE + "● " +
            CYAN + "● " + GREEN + "● " + RED + "● " +
            YELLOW + "● " + BLUE + "●" + RESET
#endif
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


    const std::string imagePath = getPicFromFolder();

    if (!imagePath.empty() && printImage(imagePath))
    {
        
        for (std::size_t i = 0; i < info.size(); ++i)
        {
            // 35-й столбец — справа от изображения шириной 30 ячеек.
            std::cout << "\033[" << i + 1 << ";35H"
                      << info[i] << "\033[K";
        }

        std::cout << "\033[" << info.size() + 1 << ";1H"
                  << std::flush;

        return;
    }

    
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
