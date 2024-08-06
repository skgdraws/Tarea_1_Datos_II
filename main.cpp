#include <iostream>
#include "generator.h"
#include "PagedArray.h"

int main() {

    // Generator generator("LARGE", "test1");

    PagedArray test("C:\\Users\\Franco\\CLionProjects\\Tarea 1 Datos II\\test1.fran");
    std::cout << test[150];
    std::cout << test[365];
    std::cout << test[550];
    std::cout << test[75];

    return 0;
}
