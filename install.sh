#!/bin/bash

set -e

PROJECT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
cd "$PROJECT_DIR"

echo "[+] Compiling Fetch..."

g++ src/main.cpp \
    src/config.cpp \
    src/GPU/gpuinfo.cpp \
    src/oslogo.cpp \
    src/CPU/cpu.cpp \
    src/memory/memory.cpp \
    src/user/user.cpp \
    -Iinclude \
    -o fetch \
    -lX11 -lXrandr

echo "[+] Installing Fetch..."

sudo install -Dm755 fetch /usr/local/bin/fetch

echo "[+] Fetch installed successfully!"
echo "Run it with: fetch"
