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
    printf("We Will Start The Game Of Life!!\n");
}
int game::initialize(int w, int h) {
    // printf("Please enter the size of your simulation."); // need to add a way to git user input.
    width = w;
    height = h;
    char arr[width*height];

    for(int i=0; i<width*height; i++) { // creating a blank display
        arr[i] = '*';
    }
    screen = new display(width, height, arr);
    screen->print();
    printf("Please resize to your screen before the simulation begins.\n");
    
    get_data();
    // This is a funciton that pauses for 1 second
    
    //this doesn't
    //std::cout<<"Press ENTER to continue....."<<std::endl<<std::endl;
    //std::cin.ignore(1);

    //this works:)
    std::chrono::seconds timespan(1);
    std::this_thread::sleep_for(timespan);

    return 1;
}

int game::get_data() {
    std::fstream myFile;
    std::vector<std::string> data;
    std::string word;
    int temp_height;
    int temp_width;

    myFile.open("blinker.txt");

    // pushing in data from file
    while (myFile >> word) { // read and update file
        data.push_back(word);
    }
    
    word = data.at(0);
    std::string word1 = "width", word2 = "Width";

    if(word.find(word1) != std::string::npos
            || word.find(word2) != std::string::npos) {
    } else {
        std::cout<< "ERROR::Please enter 'Width: <your width>' into the \nfirst line of your .txt file" <<std::endl;
        return 0;
    }

    //we now have width in temp_width
    data.erase(data.begin());
    temp_width = std::stoi(data.at(0));
    data.erase(data.begin());
    

    // finding height
    word = data.at(0);
    word1 = "height", word2 = "Height";

    if(word.find(word1) != std::string::npos
            || word.find(word2) != std::string::npos) {
    } else {
        std::cout<< "ERROR::Please enter 'Height: <your height>' into the \nsecond line of your .txt file" <<std::endl;
        return 0;
    }

    //we now have height in temp_height
    data.erase(data.begin());
    temp_height = std::stoi(data.at(0));
    data.erase(data.begin());
   

    char newScreen[screen->get_height()*screen->get_width()];



    std::cout<< temp_height;
    std::cout<< temp_width;

    //print data
    for(int i=0; i<data.size(); i++)
        std::cout << data.at(i) << ' ';
    

    return 1;
}
