#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <chrono>
#include <thread>

#include "Board.cpp"


const std::chrono::milliseconds UPDATE_TIME(500);


//void setNonCanonicalMode(bool enable);

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
        char dir_input;

        setNonCanonicalMode(true);

        while(isOver == false)
        {
            dir_input = 'q';

            if(kbhit())
            {
                dir_input = getchar();
            }

            std::cout << dir_input << "\n";

            game_board->update(dir_input);

            game_board->display();

            std::this_thread::sleep_for(UPDATE_TIME);
        }
    }

    void setNonCanonicalMode(bool enable) 
    {
        static struct termios oldt, newt;

        if (enable) 
        {
            tcgetattr(STDIN_FILENO, &oldt); // Save current terminal settings
            newt = oldt;
            newt.c_lflag &= ~(ICANON | ECHO); // Disable canonical mode and echo
            tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        } 
        else 
        {
            tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Restore terminal settings
        }
    }

    bool kbhit() 
    {
        struct termios oldt, newt;
        int ch;
        int oldf;

        // Get current terminal settings
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;

        // Disable canonical mode and echo
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);

        // Set non-blocking mode
        oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
        fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

        ch = getchar();

        // Restore terminal settings and blocking mode
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        fcntl(STDIN_FILENO, F_SETFL, oldf);

        if (ch != EOF) 
        {
            ungetc(ch, stdin); // If a key was pressed, put it back for reading
            return true;
        }

        return false;
    }

};