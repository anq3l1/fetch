#pragma once

class Ram
{
public:
    Ram() = default;

    float totalram();

    float usedram();
};

class Disk
{
public:
    Disk() = default;

    long long disk_memory();
};

