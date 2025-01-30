#include <cstdlib>
#include <ctime>
#include <iostream>
#include <CONST.h>

class Apple
{
private:
    
    int cord_X;
    int cord_Y;

public:

    Apple(/* args */)
    {
        cord_X = random_cord(1, 10);
        cord_Y = random_cord(1, 10);

        std::cout << cord_X << " " << cord_Y << std::endl;

    }

    static int random_cord(int min, int max)
    {
        return rand() % (max - min + 1) + 1;
    }

    

};
