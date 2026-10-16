# Fetch

A lightweight, cross-platform system information fetcher written in **C++**.

Fetch displays essential system information alongside an ASCII logo, providing a clean and customizable overview of your system.

Currently, Fetch supports **Linux and Windows**. Cross-platform compatibility is a work in progress, and some features may behave differently depending on the operating system.

## ✨ Features

- 🐧 Automatic operating system and distribution detection
- 🎨 OS-specific ASCII logos
- 🧠 CPU information
- 🎮 GPU detection and graphics card information
- ⚙️ GPU driver information
- 🖥️ Display resolution
- 🪟 Window manager detection on Linux
- 🐚 Shell detection
- 💾 RAM usage
- 💿 Disk information
- ⏱️ System uptime
- 🔧 Kernel and system version information
- 📦 Installed package count on supported Linux distributions
- 🚀 Lightweight and fast
- 🛠️ Written in modern C++

## 🖥️ Supported Platforms

| Platform | Status |
|---|---|
| Linux | Supported |
| Windows | Supported |
| macOS | Planned |

Fetch is designed with cross-platform compatibility in mind, using platform-specific implementations where necessary.

Linux-specific functionality relies on system interfaces such as `/proc` and `/sys`, while Windows uses its own system APIs and mechanisms to retrieve hardware and operating system information.

Some features may be unavailable or behave differently across platforms.

## 📸 Preview

### 🐧 Linux (Arch Linux)

```text
              angel @ arch

        /\             ┌──────────────────────────────────────┐
       /  \               󰣇 OS: Arch Linux
      /    \              󰍹 Resolution: 1920x1080
     /      \              Kernel: Linux 6.x
    /   ,,   \             󰍹 WM: Hyprland
   /   |  |   \             Shell: zsh
  /_-''    ''-_\         󰏗 Packages: pacman 935
                          └──────────────────────────────────────┘
                          ┌──────────────────────────────────────┐
                             CPU: AMD Ryzen 5 5500U
                            󰊴 GPU: NVIDIA GeForce GTX 1650
                             GPU Driver: NVIDIA
                             RAM: 6.04 / 14.95 GB
                             Disk: 476 GB
                            󱫐 Uptime: 1h 38min
                          └──────────────────────────────────────┘
                            ● ● ● ● ● ● ● ●
```

### 🪟 Windows

```text
             angel @ Windows

        ┌──────────────────────────────────────────┐
        │           System Information             │
        └──────────────────────────────────────────┘

        OS:          Windows 11
        Version:     25H2
        Resolution:  1920x1080
        Shell:       PowerShell
        ────────────────────────────────────────────
        CPU:         AMD Ryzen 5 5500U
        GPU:         NVIDIA GeForce GTX 1650
        GPU Driver:  NVIDIA
        RAM:         6.04 / 14.95 GB
        Disk:        476 GB
        Uptime:      1h 38min
        ────────────────────────────────────────────
```

*Examples are illustrative. Actual output and available information depend on your hardware, operating system, and Fetch configuration.*

## 🔧 Installation

Clone the repository:

```bash
git clone https://github.com/anq3l1/fetch.git
cd fetch
```

Build the project using one of the supported compilation methods below.

## 🛠️ Compilation

### Using g++

On Linux:

```bash
g++ src/main.cpp src/system.cpp src/config.cpp src/oslogo.cpp -Iinclude -o fetch
```

Run Fetch:

```bash
./fetch
```

### Using CMake

```bash
cmake -B build
cmake --build build
```

Run on Linux:

```bash
./build/fetch
```

On Windows, use a compatible C++ compiler and CMake installation. Build commands and executable paths may vary depending on the selected generator and toolchain.

## 🔄 Cross-platform Development

Fetch is being developed to work across different operating systems without relying on Linux-specific functionality everywhere.

The project uses conditional compilation and platform-specific implementations to handle differences between Linux and Windows.

Current development priorities include:

- Improving GPU detection and handling systems with multiple graphics adapters
- Correctly identifying GPU models and drivers
- Improving hardware information retrieval on Windows
- Implementing consistent system information output across platforms
- Adapting the output layout to Windows and Linux environments
- Improving operating system and version detection
- Ensuring graceful handling of unavailable system information

## 🛠️ Technologies

- **C++**
- **Standard C++ Library**
- **CMake**
- **Linux `/proc` and `/sys` interfaces**
- **`uname()` and `sysinfo()` on supported Unix-like systems**
- **Windows system APIs**

No external libraries are currently required for the core functionality.

## 📜 License

This project is licensed under the **MIT License**.

<p align="center">Made with ❤️ and C++</p>
