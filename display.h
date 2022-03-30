// this is a display class that can be used to print the grid.
// It will not update size. So if we want so increase the size
// we will need to create a new display object and delete the 
// current one.
class display {
    private:
        int width, height;
        char *grid;
    public:
        display(int w, int h, char *input);
        ~display();
        int update(char* input);
        int print();
        int get_width();
        int get_height();
};
// This will hold game logic and edit the display as we go
class game {
    private:
        //char *init_data;
        int width, height;
        display *screen;
        char *data;
    public:
        game();
        int get_data();
        int initialize(int w, int h); //will read the input data, and format it to be in the center of the screen.
};
