#include "Snake_Cell.cpp"


class Snake
{
private:

    Snake_Cell *head;
    Snake_Cell *tail;

    int num_cells = 0;

public: 

    Snake_Cell *snake_cells[1024];

    Snake()
    {
        head = new Snake_Cell(4, 5, 'l');
        tail = head;

        snake_cells[num_cells] = head;

        num_cells = 1;
    }

    void update_cells()
    {
        // direction will tell the function
        // in what direction to incriment each snake cell

        Snake_Cell *current_cell;

        char snake_dir;
        int x_cord;
        int y_cord;

        for(int cell_num = 0; cell_num < 1; ++cell_num)
        {
            current_cell = snake_cells[cell_num];
            snake_dir = current_cell->get_dir();
            x_cord = current_cell->get_X();
            y_cord = current_cell->get_Y();

            if(snake_dir == 'l')
            {
                x_cord++;
            }

            current_cell->update_cell(x_cord);
        }
    }
    
    
    void check_cordinate()
    {
        // it will check if the snake goes out of the board dimensions 
    }

    void add_cell()
    {
        //  this function will add new bord cell to the array of all cells
    }



    // functions
};