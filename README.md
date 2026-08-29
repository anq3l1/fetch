# Fetch

A small and lightweight system information fetcher for Linux, written in **C++**.

Fetch displays useful system information alongside an ASCII logo of your Linux distribution.

## ✨ Features

- 🐧 Automatic distribution detection
- 🎨 Distribution-specific ASCII logos
- 🧠 CPU information
- 🎮 GPU information
- 🖥️ Window Manager
- 🐚 Shell
- 💾 RAM usage
- ⏱️ System uptime
- ⚙️ Kernel information
- 🚀 Lightweight and fast
- 🛠️ Written in C++

## 📸 Preview

```text                                                                     
                            user @ arch

           /\             ┌──────────────────────────────────────────┐
          /  \               󰇺 Chassis: пантера
         /    \              󰣇 OS: Arch Linux
        /      \             󰍹 Resolution: U:1920x1080p-0
       /   ,,   \             Kernel: 7.1.9-arch1-2
      /   |  |   \        └──────────────────────────────────────────┐
     /_-''    ''-_\       ┌──────────────────────────────────────────┐
                            󱗃 WM: Hyprland
                             Shell: zsh
                            󰏗 Packages: pacman 888
                          └──────────────────────────────────────────┘ 
                          ┌──────────────────────────────────────────┐
                             CPU: AMD Ryzen 5 5500U with Radeon Graphics
                            󰊴 GPU: [GeForce GTX 1650 Mobile / Max-Q] (rev a1)
                             GPU driver: nvidia 610.57.04
                             RAM: 2.6 / 14.95 GB
                            󱫐 Uptime: 5h 0min.
                          └──────────────────────────────────────────┘
                            ● ● ● ● ● ● ● ●
```
🐧 Supported Distributions

Currently supported:

Arch Linux
Fedora Linux
Linux Mint

More distributions can be added in the future.

🔧 Installation

Clone the repository:
```
git clone https://github.com/anq3l1/fetch.git
cd fetch
```
Run:
```
./fetch
```

## 🛠️ Compilation

Fetch can be compiled using either **g++** or **CMake**.

### Using g++

Compile all source files:

```bash
g++ src/main.cpp src/system.cpp src/config.cpp src/oslogo.cpp -Iinclude -o fetch
```

Run Fetch:

```bash
./fetch
```

### Using CMake

Create a build directory:

```bash
cmake -B build
```
Build the project:

```bash
cmake --build build
```
Run Fetch:

```bash
./build/fetch
```

📂 Project Structure
```
fetch/
├── config/
│   └── config.conf
├── include/
│   ├── config.h
│   ├── oslogo.h
│   ├── colors.h
│   └── system.h
├── src/
│   ├── config.cpp
│   ├── main.cpp
│   ├── oslogo.cpp
│   └── system.cpp
├── CMakeLists.txt
└── README.md
```
# src/main.cpp

Handles the main program logic, distribution detection, command-line arguments and logo selection.

# src/system.cpp

Contains functions used to retrieve system information such as CPU, GPU, RAM, kernel, shell, window manager and uptime.

# src/oslogo.cpp

Contains ASCII logos for supported Linux distributions.

# src/config.cpp

Handles reading and parsing the Fetch configuration file.

# include/

Contains header files with function declarations and interfaces used by the project.

# config/

Contains the Fetch configuration file.

## 🛠️ Technologies

- **C++**
- **Linux `/proc`**
- **Linux `/sys`**
- **`uname()`**
- **`sysinfo()`**
- **Standard C++ Library**
- **CMake**

> No external libraries are required.

## 🚧 Roadmap

- [ ] Add more Linux distributions
- [ ] Improve distribution detection
- [ ] Add color themes
- [ ] Add disk usage
- [ ] Add battery information
- [ ] Add network information
- [ ] Add command-line help
- [ ] Improve GPU detection
- [ ] Expand configuration system

## 📜 License

This project is licensed under the **MIT License**.

<p align="center"> Made with ❤️ and C++ on Linux </p> ```
