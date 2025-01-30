#include "Snake_Cell.cpp"

#include <iostream>

#include "CONST.h"

class Snake
{
private:

    Snake_Cell *head;

    int num_cells = 0;

public: 

    Snake_Cell *snake_cells[CELLS];

    Snake()
    {
        head = new Snake_Cell(ROWS / 2, COLUMNS / 2, 'l');
        snake_cells[num_cells] = head;

        snake_cells[1] = new Snake_Cell(head->get_X(), head->get_Y() + 1, 'l');
        snake_cells[2] = new Snake_Cell(head->get_X(), head->get_Y() + 2, 'l');

        num_cells = 3;
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

    void update_dir(char new_dir)
    {
        // it will update the direction of the snake 

        // can posibly add another instance of the snake cell
        // called prev direction 

        // when head is updated the cell prevously from head receives previous direction of the head

        Snake_Cell *current_cell;

        // direction of the head before adjustment

        char prev_direction = head->get_dir();

        for(int cell_num = 0; cell_num < num_cells; ++cell_num)
        {
            current_cell = snake_cells[cell_num];

            if(current_cell == head)
            {
                switch (new_dir)
                {
                case 'a': 
                    current_cell->update_dir('l');
                    break;
                
                case 'd':
                    current_cell->update_dir('r');
                    break;
                case 'w':
                    current_cell->update_dir('t');
                    break;
                case 's':
                    current_cell->update_dir('d');
                    break;
                }   
                
                // !!!! Make sure the snake can't go to the opposite direction 

            }
            else
            {
                char temp = current_cell->get_dir();
                current_cell->update_dir(prev_direction);
                prev_direction = temp;
            }
        }
    }

    void add_cell()
    {
        //  this function will add new snake cell to the array of all cells

        // this function should be called when the head is on the apple's cordiante  
        // and thid function will add another cells to the tail


    }

    int get_number_cells()
    {
        return this->num_cells;
    }

    // functions
};