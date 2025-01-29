
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

    void increment_X(void)
    {
        this->x_cordinate++;
    }

    void increment_Y(void)
    {   
        this->y_cordinate++;
    }

    void decrement_X(void)
    {
        this->x_cordinate--;
    }

    void decrement_Y(void)
    {   
        this->y_cordinate--;
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

    void update_dir(char new_dir)
    {
        this->direction = new_dir;
    }

    // necessary functions;
};