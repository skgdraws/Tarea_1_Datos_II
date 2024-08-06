//
// Created by Franco on 5/8/2024.
//

#ifndef PAGEDARRAY_H
#define PAGEDARRAY_H

#include <iostream>
#include <filesystem>
#include <fstream>
#include "Page.h"

/*
█▀▀ █░░ ▄▀█ █▀ █▀ ▀   █▀█ ▄▀█ █▀▀ █▀▀ █▀▄   ▄▀█ █▀█ █▀█ ▄▀█ █▄█
█▄▄ █▄▄ █▀█ ▄█ ▄█ ▄   █▀▀ █▀█ █▄█ ██▄ █▄▀   █▀█ █▀▄ █▀▄ █▀█ ░█░
*/
class PagedArray {

private:

    Page frame1;
    Page frame2;
    Page frame3;
    Page frame4;

    std::ofstream file;

public:

    int operator[] (int index);

    PagedArray(const std::string& fileDir);
    ~PagedArray();
};


#endif //PAGEDARRAY_H
