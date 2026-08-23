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
          /\
         /  \               OS:      Arch Linux
        /    \              Kernel:  7.1.6-arch1-1
       /      \             WM:      Hyprland
      /   ,,   \            Shell:   zsh
     /   |  |   \           CPU:     AMD Ryzen 5 5500U
    /_-''    ''-_\          GPU:     NVIDIA GeForce GTX 1650
                            RAM:     6.2 / 15.0 GB
                            Uptime:  4 h 27 min

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
git clone https://github.com/USERNAME/fetch.git
cd fetch
```
Compile:
```
g++ main.cpp -o fetch
```
Run:
```
./fetch
```
🎨 Logo Selection

Fetch automatically selects the logo based on the installed distribution.

You can also manually select a logo:
```
./fetch --arch-logo
./fetch --fedora-logo
./fetch --mint-logo
📂 Project Structure
fetch/
├── main.cpp
├── oslogo.h
├── system.h
└── README.md
main.cpp
```
Handles distribution detection, command-line arguments and logo selection.

oslogo.h

Contains ASCII logos and the system information layout.

system.h

Contains functions used to retrieve system information.

🛠️ Technologies
C++
Linux /proc
Linux /sys
uname()
sysinfo()
Standard C++ Library

No external libraries are required.

🚧 Roadmap
 Add more Linux distributions
 Improve distribution detection
 Add color themes
 Add disk usage
 Add battery information
 Add network information
 Add command-line help
 Improve GPU detection
📜 License

This project is licensed under the MIT License.

<p align="center"> Made with ❤️ and C++ on Linux </p>
