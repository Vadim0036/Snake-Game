#include <thread>
#include <chrono>

#include "Board.cpp"

const std::chrono::milliseconds UPDATE_TIME(500);

class SnakeGame
{
private:

    Board *game_board;

    bool isOver;

public:

    SnakeGame()
    {
        game_board = new Board();
        isOver = false;
    }

    ~SnakeGame()
    {
        delete game_board;
    }

    void start_game()
    {
        while(isOver == false)
        {
            game_board->update();

            game_board->display();

            std::this_thread::sleep_for(UPDATE_TIME);
        }
    }

};