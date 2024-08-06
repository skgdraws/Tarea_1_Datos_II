//
// Created by Franco on 5/8/2024.
//

#include "generator.h"
#include <filesystem>


/*
*/
void Generator::generateArray(SIZE size) {

    std::size_t numElements = size/sizeof(int);

    rng_array.clear();
    rng_array.reserve(numElements);

    for (std::size_t i = 0; i < numElements; i++) {

        rng_array.push_back(std::rand());
    }
}


/*
*/
Generator::SIZE Generator::parseSize(const std::string &sizeStr) {

    if (sizeStr == "SMALL") {
        return SMALL;
    }
    else if (sizeStr == "MEDIUM") {
        return MEDIUM;
    }
    else if (sizeStr == "LARGE") {
        return LARGE;
    }
    else {
        throw std::invalid_argument("Tamaño no válido. Pruebe: 'SMALL', 'MEDIUM', 'LARGE'");
    }
}


/*
*/
void Generator::saveFile(const std::string &fileName, SIZE size) {

    std::filesystem::path projectPath = getProjectPath();
    std::filesystem::path fileBin = fileName + ".fran";
    std::filesystem::path filePath = projectPath / fileBin;

    std::ofstream file(filePath, std::ios::binary);
    if (!file) {

        throw std::runtime_error("No se pudo abrir el archivo para escritura");
    }

    file.write (reinterpret_cast<const char *>(rng_array.data()), rng_array.size() * sizeof(int));

    file.close();
}


/*
*/
std::filesystem::path Generator::getProjectPath() {

    std::filesystem::path currentPath = std::filesystem::current_path();

    while (currentPath.has_parent_path()) {

        currentPath = currentPath.parent_path();

        if (std::filesystem::exists(currentPath / "CMakeLists.txt"))
        {
            return currentPath;
        }
    }

    // throw std::runtime_error("No se pudo encontrar la ruta del proyecto");
}


/*
*/
void Generator::printArray() {

    for (std::size_t i = 0; i < rng_array.size(); i++) {

        std::cout << rng_array[i] << ", ";

        if ((i+1) % 10 == 0){

            std::cout << std::endl;
        }
    }
}


/*
*/
const std::vector<int> &Generator::getArray() const {

    return rng_array;
}


/*
*/
Generator::Generator(const std::string &sizeStr, const std::string &fileName) {

    // Generating Random Seed
    std::srand(std::time(nullptr));

    // Generating Random Numbers
    SIZE size = parseSize(sizeStr);
    generateArray(size);
    saveFile(fileName, size);
}
