//
// Created by Franco on 5/8/2024.
//

#ifndef GENERATOR_H
#define GENERATOR_H

// Dependencies and Imports
#include <vector>
#include <iostream>
#include <ctime>
#include <stdexcept>

// Manage Files
#include <fstream>
#include <filesystem>

/*
█▀▀ █░░ ▄▀█ █▀ █▀ ▀   █▀▀ █▀▀ █▄░█ █▀▀ █▀█ ▄▀█ ▀█▀ █▀█ █▀█
█▄▄ █▄▄ █▀█ ▄█ ▄█ ▄   █▄█ ██▄ █░▀█ ██▄ █▀▄ █▀█ ░█░ █▄█ █▀▄
*/
class Generator {

private:

    // Generated File Size
    enum SIZE : std::size_t {
        SMALL = 512ull * (1024 * 1024),
        MEDIUM = 1024ull * (1024 * 1024),
        LARGE = 2ull * 1024 * (1024 * 1024)
    };

    // Random Number Generation
    std::vector<int> rng_array;
    void generateArray (SIZE size);
    static SIZE parseSize(const std::string& sizeStr);

    // File Location and Saving
    void saveFile(const std::string& fileName, SIZE size);
    static std::filesystem::path getProjectPath();

public:

    // Gets and Prints
    void printArray();
    const std::vector<int>& getArray() const;

    // Constructor
    Generator(const std::string& sizeStr, const std::string& fileName);
};
#endif //GENERATOR_H
