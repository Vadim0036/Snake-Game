#include "Snake_Cell.cpp"

#include <iostream>

#include "CONST.h"

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
        head = new Snake_Cell(ROWS / 2, COLUMNS / 2, 'l');
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

        for(int cell_num = 0; cell_num < num_cells; ++cell_num)
        {
            current_cell = snake_cells[cell_num];
            snake_dir = current_cell->get_dir();
            x_cord = current_cell->get_X();
            y_cord = current_cell->get_Y();

            // check if the snake violate board limits 
            if(!check_cordinate(current_cell, x_cord, y_cord, snake_dir))
            {
                if (snake_dir == 'l')       // left 
                {
                    current_cell->decrement_Y();
                }
                else if (snake_dir == 'r')  // right
                {
                    current_cell->increment_Y();
                }
                else if (snake_dir == 't')  // top
                {
                    current_cell->decrement_X();
                }
                else if(snake_dir == 'd')   // down
                {
                    current_cell->increment_X();
                }
            }
        }
    }
    
    bool check_cordinate(Snake_Cell *cur_cell, int x_cord, int y_cord, char dir)
    {   
        /* it will check if the snake goes out of the board dimensions  */
        /* it will adjust coordinates appropriately to fit the board    */

        // return true if any adjustments were made
        // retrun false if not 

        if(y_cord == 1 && dir == 'l')
        {
            cur_cell->update_Y(COLUMNS - 2);
            return true;
        }
        if(y_cord == (COLUMNS - 2) && dir == 'r')
        {
            cur_cell->update_Y(1);
            return true;
        }
        if(x_cord == 1 && dir == 't')
        {
            cur_cell->update_X(ROWS - 2);
            return true;
        }
        if(x_cord == (ROWS - 2) && dir == 'd')
        {
            cur_cell->update_X(1);
            return true;
        } 

        return false;
    }

    void add_cell()
    {
        //  this function will add new snake cell to the array of all cells
    }

    int get_number_cells()
    {
        return this->num_cells;
    }

    // functions
};