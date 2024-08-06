//
// Created by Franco on 5/8/2024.
//

#ifndef FRAME_H
#define FRAME_H

/*
*/
class Page {

private:

    // Arrays and data
    bool isLoaded;
    int pageNumber;

    int array[128];

public:

    Page();
    Page(int loadedArray[], int pageNum);

    int operator[] (int index);

    bool getLoaded() const;
    int getPageNum() const;

};

#endif //FRAME_H
