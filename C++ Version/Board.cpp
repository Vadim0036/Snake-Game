#include <iostream>
#include <cstdlib>
#include <iomanip>

#include "Snake.cpp"

const int ROWS = 18;
const int COLUMNS = 12;

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
               std::cout << std::setw(3) << board[row][column];
            }
            std::cout << "\n";
        }

        std::cout << std::endl;
    }

    void update()
    {
        // board update

        // it will take an array from the Snake object and copy all cells from there
        // to the board array
        // 

        snake_obj->update_cells();

        int cord_x;
        int cord_y;

        Snake_Cell *current_cell;

        for(int cell = 0; cell < 1024; cell++)
        {
            current_cell = snake_obj->snake_cells[cell];
            cord_x = current_cell->get_X();
            cord_y = current_cell->get_Y();

            std::cout << "X: " << cord_x << '\n';
            std::cout << "Y: " << cord_y << '\n';

            board[cord_x][cord_y] = '*';

            // need somehow remove previous snake cell
        }

        std::cout << "Updated!";
    }

};