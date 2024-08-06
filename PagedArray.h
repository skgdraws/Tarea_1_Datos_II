//
// Created by Franco on 5/8/2024.
//

#ifndef PAGEDARRAY_H
#define PAGEDARRAY_H

#include <iostream>
#include <filesystem>
#include <fstream>
#include <ctime>
#include "Page.h"

/*
*/
class PagedArray {

private:

    int pageHit;
    int pageFault;

    Page frame1;
    Page frame2;
    Page frame3;
    Page frame4;

    std::ifstream file;

    int* loadFromFile(int pageNum);
    int checkFreeFrames();
    void loadToFrame(int frameNum ,int pageNum);
    int checkIfPageLoaded(int pageNum);
    void saveFile();

public:

    int operator[] (int index);

    PagedArray(const std::string& fileDir);
};


#endif //PAGEDARRAY_H
