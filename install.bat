
@echo off
chcp 65001 >nul
setlocal

echo ============================
echo       Building Fetch
echo ============================

where cmake >nul 2>&1
if errorlevel 1 goto gpp_build

echo [INFO] CMake found.
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
if errorlevel 1 goto gpp_build

cmake --build build --config Release
if errorlevel 1 goto gpp_build

if exist build\fetch.exe (
    copy /Y build\fetch.exe fetch.exe >nul
    if errorlevel 1 goto error
    goto run
)

echo [WARN] CMake did not produce fetch.exe.
goto gpp_build

:gpp_build
echo.
echo [INFO] Trying direct compilation with g++.exe...

where g++.exe >nul 2>&1
if errorlevel 1 goto no_compiler

g++.exe -std=c++17 -Iinclude src/main.cpp src/config.cpp src/oslogo.cpp src/CPU/cpu.cpp src/GPU/gpuinfo.cpp src/memory/memory.cpp src/user/user.cpp -ladvapi32 -o fetch.exe
if errorlevel 1 goto error

goto run

:no_compiler
echo.
echo [ERROR] Neither CMake nor g++.exe is available.
echo Install CMake or add MinGW to PATH.
goto error

:run
echo.
echo [SUCCESS] Fetch built successfully!
echo Starting Fetch...
echo.

fetch.exe
if errorlevel 1 (
    echo [WARN] Fetch exited with an error.
)

pause
exit /b 0

:error
echo.
echo [ERROR] Build failed!
pause
exit /b 1
