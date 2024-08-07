#ifndef PAGEDARRAY_H
#define PAGEDARRAY_H

#include <iostream>
#include <filesystem>
#include <fstream>
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

    std::fstream file;


    // Checks
    int checkFreeFrames();
    int checkIfPageLoaded(int pageNum);

    // Read and Write
    void loadToFrame(int frameNum ,int pageNum);
    void saveFrame();

public:

    int operator[] (int index);

    PagedArray(const std::string& fileDir);

    void printInfo();
};


#endif //PAGEDARRAY_H
