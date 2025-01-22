
class Snake_Cell
{
private:

    int  x_cordinate;
    int  y_cordinate;
    char direction;

public:

    Snake_Cell(int x, int y, char dir)
    {
        x_cordinate  =  x;
        y_cordinate  =  y;
        direction    =  dir;
    }

    Snake_Cell()
    {

    }

    // this func should be in Snake 
    void update_cell(char dir)
    {

        // direction will tell the function
        // in what direction to incriment each snake cell

    }
    

    static void check_cordinate()
    {

        // it will check if the snake goes out of the board dimensions 

    }

    int get_X()
    {
        return x_cordinate;
    }

    int get_Y()
    {
        return y_cordinate;
    }

    char get_dir()
    {
        return direction;
    }

    void update_X(int new_cord)
    {
        x_cordinate = new_cord;
    }

    void update_Y(int new_cord)
    {
        y_cordinate = new_cord;
    }

    // necessary functions;
};