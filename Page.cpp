//
// Created by Franco on 5/8/2024.
//

#include "Page.h"

Page::Page() {

    isLoaded = false;
    pageNumber = -1;
}

Page::Page(int loadedArray[], int pageNum) {

    // Creating Array Copy
    for (int i = 0; i < (sizeof(array) / sizeof(int)); i++) {

        array[i] = loadedArray[i];
    }

    // Page Setup
    isLoaded = true;
    pageNumber = pageNum;
}

int Page::operator[](int index) {
    return array[index];
}

bool Page::getLoaded() const {
    return isLoaded;
}

int Page::getPageNum() const {
    return pageNumber;
}

