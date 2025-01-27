#include <iostream>
#include <cstdlib>
#include <iomanip>

#include "Snake.cpp"

class Board
{
private:

    char   board[ROWS][COLUMNS];
    Snake  *snake_obj;

public:

    Board()
    {
        for(int row = 0; row < ROWS; ++row)
        {
            for(int column = 0; column < COLUMNS; ++column)
            {
                if(row == 0 || row == (ROWS - 1))
                {   
                    board[row][column] = '-';
                    //std::cout << std::setw(3) << '-';
                }
                else if(column == 0 || column == (COLUMNS - 1))
                {
                    board[row][column] = '|';
                    //std::cout << std::setw(3) << '|';
                }
                else
                {
                    board[row][column] = ' ';
                    //std::cout << std::setw(3) << ' ';
                }
            }
        }
        snake_obj = new Snake();
    }

    void display()
    {
        system("clear");
        std::cout << std::endl;

        for(int row = 0; row < ROWS; ++row)
        {
            for(int column = 0; column < COLUMNS; ++column)
            {
               std::cout << std::setw(2) << board[row][column];
            }
            std::cout << "\n";
        }

        std::cout << std::endl;
    }

    void update()
    {
        // board update

        // update the snake's cells 
        // reset the board to default  
        // copy snake cells from snake array into board array 

        snake_obj->update_cells();  // updates snake cells in the array in object SNAKE
        
        redraw();                   // reset the board to default 

        Snake_Cell *current_cell;

        int x_cord;
        int y_cord;

        int number_cells = snake_obj->get_number_cells();
        
        // iterate throug snake cells array, not board array
        for(int i = 0; i < number_cells; ++i)
        {
            current_cell = snake_obj->snake_cells[i];
            x_cord = current_cell->get_X();
            y_cord = current_cell->get_Y();

            // we dont draw anything here, just update array 
            board[x_cord][y_cord] = '*';
        }

        std::cout << "Updated!";
    }

    // will redraw board to default before adding updated snake cells
    void redraw()
    {
        for(int row = 0; row < ROWS; ++row)
        {
            for(int column = 0; column < COLUMNS; ++column)
            {
                if(row == 0 || row == (ROWS - 1))
                {   
                    board[row][column] = '-';
                    //std::cout << std::setw(3) << '-';
                }
                else if(column == 0 || column == (COLUMNS - 1))
                {
                    board[row][column] = '|';
                    //std::cout << std::setw(3) << '|';
                }
                else
                {
                    board[row][column] = ' ';
                    //std::cout << std::setw(3) << ' ';
                }
            }
        }
    }

    
    // create DESTRUCTOR  Later

};