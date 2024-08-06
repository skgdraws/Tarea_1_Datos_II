//
// Created by Franco on 5/8/2024.
//

#include "PagedArray.h"

int* PagedArray::loadFromFile(int pageNum) {

    // Loading Page Logic
    file.seekg(128 * pageNum * sizeof(int));

    int buffer[128];
    file.read((char*) &buffer, sizeof(int) * 128);

    for (int i : buffer) {

        std::cout << i << ", ";
    }

    return buffer;
}

int PagedArray::checkFreeFrames() {

    if (!frame1.getLoaded())
        return 1;
    else if (!frame2.getLoaded())
        return 2;
    else if (!frame3.getLoaded())
        return 3;
    else if (!frame4.getLoaded())
        return 4;
    else
        return 0;
}

void PagedArray::loadToFrame(int frameNum, int pageNum) {

    int* loadArray;

    switch (frameNum) {

        case 1:
            loadArray = loadFromFile(pageNum);
            frame1 = Page(loadArray, pageNum);
            free(loadArray);
            break;

        case 2:
            loadArray = loadFromFile(pageNum);
            frame2 = Page(loadArray, pageNum);
            free(loadArray);
            break;

        case 3:
            loadArray = loadFromFile(pageNum);
            frame3 = Page(loadArray, pageNum);
            free(loadArray);
            break;

        case 4:
            loadArray = loadFromFile(pageNum);
            frame4 = Page(loadArray, pageNum);
            free(loadArray);
            break;

        default:
            int randFrame = 1 + rand() % 4;
            loadToFrame(randFrame, pageNum);
            break;

    }
}

PagedArray::PagedArray(const std::string &fileDir) {

    // Open File
    file.open(fileDir, std::ifstream::in);

    // Initializing page stats
    pageFault = 0;
    pageHit = 0;

    // Initializing Pages
    frame1 = Page();
    frame2 = Page();
    frame3 = Page();
    frame4 = Page();

}

int PagedArray::operator[](int index) {

    // Calculating Index and Page
    int pageNum = index / 128;
    int relativeIndex = index % 128;

    // Check Free Frames
    const int availableFrame = checkFreeFrames();
    loadToFrame(availableFrame, pageNum);

    // ACTUALLY GIVES YOU THE FUCKING NUMBER :SKULL:
    if (frame1.getPageNum() == pageNum)
        return 1;
    else if (frame2.getPageNum() == pageNum)
        return 2;
    else if (frame3.getPageNum() == pageNum)
        return 3;
    else if (frame4.getPageNum() == pageNum)
        return 4;

}
