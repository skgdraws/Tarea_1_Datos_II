#include "PagedArray.h"


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
        return -1;
}


int PagedArray::checkIfPageLoaded(int pageNum) {

    if (frame1.getPageNum() == pageNum)
        return 1;
    else if (frame2.getPageNum() == pageNum)
        return 2;
    else if (frame3.getPageNum() == pageNum)
        return 3;
    else if (frame4.getPageNum() == pageNum)
        return 4;
    else
        return -1;
}


void PagedArray::loadToFrame(int frameNum, int pageNum) {

    // Loading file
    int buffer[128];

    file.seekg(128 * pageNum * sizeof(int));
    file.read((char*) &buffer, sizeof(int) * 128);

    switch (frameNum) {

        case 1:
            frame1 = Page(buffer, pageNum);
            break;

        case 2:
            frame2 = Page(buffer, pageNum);
            break;

        case 3:
            frame3 = Page(buffer, pageNum);
            break;

        case 4:
            frame4 = Page(buffer, pageNum);
            break;

        default:
            int randFrame = 1 + rand() % 4;
            loadToFrame(randFrame, pageNum);
            break;

    }
}


PagedArray::PagedArray(const std::string &fileDir) {

    // Open File
    file.open(fileDir, std::ios::in | std::ios::out);

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

    int pageID = checkIfPageLoaded(pageNum);

    if (pageID < 0) {

        pageFault++;

        // Check Free Frames
        const int availableFrame = checkFreeFrames();
        loadToFrame(availableFrame, pageNum);
    }
    else
        pageHit++;

    // ACTUALLY GIVES YOU THE FUCKING NUMBER :SKULL:
    if (frame1.getPageNum() == pageNum)
        return frame1[relativeIndex];
    else if (frame2.getPageNum() == pageNum)
        return frame2[relativeIndex];
    else if (frame3.getPageNum() == pageNum)
        return frame3[relativeIndex];
    else if (frame4.getPageNum() == pageNum)
        return frame4[relativeIndex];


}

void PagedArray::printInfo() {
    std::cout << "Page hit = " << pageHit << std::endl <<  "Page fault = " << pageFault << std::endl;
}