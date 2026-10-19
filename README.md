# Fetch

A lightweight, cross-platform system information fetcher written in **C++**.

Fetch displays essential system information alongside an ASCII logo or a custom image, providing a clean and customizable overview of your system.

Currently, Fetch supports **Linux and Windows**. macOS support is planned.

## ✨ Features

- 🐧 Automatic operating system and Linux distribution detection
- 🎨 OS-specific ASCII logos
- 🖼️ Custom PNG image support
- 🎲 Random selection of custom images
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
         /\          anq3l1 @ arch
        /  \         ┌──────────────────────────────────────────┐
       /    \          󰇺 Chassis: Asus
      /      \         󰣇 OS: Arch Linux
     /   ,,   \        󰍹 Resolution: 1920x1080
    /   |  |   \        Kernel: 7.x.x-archx-x
   /_-''    ''-_\      󱗃 WM: Hyprland
                        Shell: zsh
                       󰏗 Packages: xxx
                     └──────────────────────────────────────────┘
                     ┌──────────────────────────────────────────┐
                        CPU: AMD Ryzen 5 5500U
                       󰊴 GPU: GeForce GTX 1650 Mobile
                        GPU driver: nvidia 615.xx.xx
                        RAM: 2.94 / 15.95 GB
                        Disk: 476 GB
                       󱫐 Uptime: 14h 48min
                       󱫐 OS Age: 90 days
                     └──────────────────────────────────────────┘
                     ● ● ● ● ● ● ● ●
```

### Windows 
```text
   .-----. .-----.             aspire\angel @ 
   |     | |     |             -------------------------------------
   |     | |     |               Chassis: Aspire A715-42G
   '-----' '-----'               OS: Microsoft Windows
   .-----. .-----.               Resolution: 1920x1080
   |     | |     |               Kernel: 10.0 (build 26300)
   |     | |     |               WM: Desktop Window Manager
   '-----' '-----'               Shell: C:\WINDOWS\system32\cmd.exe
                                 Terminal: PowerShell
                                 Packages: N/A
                                 CPU: AMD Ryzen 5 5500U with Radeon Graphics         
                                 GPU: Unknown
                                 GPU driver: Unkonwn
                                 RAM: 10.230335 / 15.338436 GB
                                 Disk: 180 GB
                                 Uptime: 253h 22min.
```

*Examples are illustrative. Actual output and available information depend on your hardware, operating system, and Fetch configuration.*

## 🖼️ Custom Images

You can customize Fetch by displaying your own images instead of the default ASCII logo.

### How to add your image

1. If you use Hyprland, go to ~/.config files.
2. Create a folders named `fetch/logo/` in the `~/.config`.
3. Place your image inside the `logo` folder.
4. Run Fetch.

Example directory structure:

```text
~/.config/
 └──fetch/
    └──logo/
       ├── arch.png
       ├── wallpaper.png
       └── custom.png
```

Fetch can select an image randomly from the `logo` directory when multiple supported images are available.

**Supported image formats:** PNG, JPG, JPEG, WEBP, and GIF.

> **Note:** Image display currently relies on Kitty's image protocol and is intended for use in the Kitty terminal. Support in other terminals may vary.

If no suitable image is found, Fetch falls back to the default ASCII logo.

## 🔧 Installation

Clone the repository:

```bash
git clone https://github.com/anq3l1/fetch.git
cd fetch
```

## 🛠️ Compilation

### Linux

Build and install Fetch using the provided installation script:

```bash
./install.sh
```

Run Fetch:

```bash
fetch
```

### Using CMake

Configure the project:

```bash
cmake -B build
```

Build:

```bash
cmake --build build
```

### Windows

Install a compatible C++ compiler and CMake.

Configure the project:

```bash
cmake -B build
```

Build:

```bash
cmake --build build --config Release
```

The executable's location depends on the selected compiler and CMake generator.

## 🔄 Cross-platform Development

Fetch uses conditional compilation and platform-specific implementations to support differences between Linux and Windows.

Some features rely on operating-system-specific APIs and may require separate implementations for each platform.

Cross-platform compatibility is an ongoing part of the project's development.

## 🗺️ Roadmap

- [x] Linux support
- [x] Windows support
- [x] Custom image support
- [ ] macOS support
- [ ] Improve terminal compatibility
- [ ] Expand hardware information support

## 📜 License

This project is licensed under the **MIT License**.

<p align="center">Made with ❤️ and C++</p>