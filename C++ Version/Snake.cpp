#include "Snake_Cell.cpp"

#include <iostream>

const int CELLS = 1024;

class Snake
{
private:

    Snake_Cell *head;
    Snake_Cell *tail;

    int num_cells = 0;

public: 

    Snake_Cell *snake_cells[CELLS];

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
            //printf("I am here\n");
            current_cell = snake_cells[cell_num];
            snake_dir = current_cell->get_dir();
            x_cord = current_cell->get_X();
            y_cord = current_cell->get_Y();

            //std::cout << "Current X: " << x_cord;
            //std::cout << "Current Y: " << y_cord;

            //std::cout << '\n';

            if(snake_dir == 'l')
            {
                current_cell->decrement_Y();
            }

            //current_cell->update_X(x_cord);
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