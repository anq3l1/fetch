#pragma once

class Ram
{
public:
    Ram() = default;

    static float totalram();

    static float usedram();
};

class Disk
{
public:
    Disk() = default;

    static long long disk_memory();
};

