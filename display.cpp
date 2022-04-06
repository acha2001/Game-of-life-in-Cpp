#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <thread>
#include "display.h"

display::display (int w, int h, char *input) {
    width = w;
    height = h;
    grid = new char [width*height];
    for (int i=0; i<width*height; i++) {
        grid[i] = input[i];
    }
}

display::~display() {
    delete[] grid;
}

// Will print the current grid
int display::print() {
    int printed = 0;
    for (int i=0; i<width*height; i++) {
        printed++;
        std::cout<< grid[i] <<" ";
        if (printed == width) {
            printed=0;
            std::cout<<std::endl;
        }
    }
    std::cout<<std::endl;
    return 1;
}

// updates grid but does not update size
int display::update(char* input) {
    
    for (int i=0; i<width*height; i++) {
        grid[i] = input[i];
    }
    return 1; 
}

int display::get_height() {
    return height;
}

int display::get_width() {
    return width;
}

game::game() {
    width=20;
    height=20;
    printf("We Will Start The Game Of Life!!\n");
}

int game::initialize() {

    char arr[width*height];
    std::vector<int> cordinates;

    for(int i=0; i<width*height; i++) { // creating a blank display
        arr[i] = '*';
    }
    
    cordinates = get_data();

    for (int i=0; i<cordinates.size(); i+=2) {
        arr[width*cordinates[i+1]+cordinates[i]] = 'O';     
    } 

    screen = new display(width, height, arr);
    screen->print();

    // This will pause the for 1 second
    std::chrono::seconds timespan(1);
    std::this_thread::sleep_for(timespan);

    return 1;
}

// This will read throught the file and put cordinats 
// into an array. when reading will need to convert
// list into ordered pairs
std::vector<int> game::get_data() {

    std::fstream myFile;
    std::vector<int> data;
    std::string word;
    int temp;
    
    myFile.open("blinker.txt");

    // pushing in data from file
    while (myFile >> word) { // read and update file
        temp = std::stoi(word);
        data.push_back(temp);
    }
    
    /*
    //print data
    for(int i=0; i<data.size(); i++)
        std::cout << data.at(i) << ' ';
    */ 
    return data;
}



