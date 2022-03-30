#include <iostream>
#include "display.h"

int main() {
    int x, y;
    game newGame;

    printf("What size do you want your dispay to be.\n");
    printf("Colums: ");
    std::cin>> x;
    std::cout<<std::endl;
    printf("Rows: ");
    std::cin>> y;
    std::cout<<std::endl;

    newGame.initialize(x,y);
    return 1;
}
