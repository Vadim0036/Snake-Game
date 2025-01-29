#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>
#include <unistd.h>

/*
// Shared atomic character, initialized to 'g'
std::atomic<char> current_char('g');

// Worker thread function
void printChar() {
    while (true) {
        //std::cout << current_char.load() << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}

int main() {
    // Start the worker thread
    std::thread worker(printChar);

    std::cout << "Type 'n' and press Enter to change output to 'n'.\n";

    // Main thread: handle user input
    while (true) {
        char input;
        std::cin >> input;
        if (input == 'n' || input == 'N') {
            current_char.store('n');
        } else {
            current_char.store('g');
        }
    }

    // Join the worker thread (unreachable in this example)
    worker.join();
    return 0;
}

*/

/*
void print_char()
{
    char input;
    std::cin >> input;

    write(stdin, 'g', 1);



}

*/


int main(void)
{
    // Start the threat
    std::thread worker(print_char); 

    bool status = true;
    char input;

    while(status)
    {
        std::cin >> input;
        if(input == 'q')
        {
            status = false;
        }
    }

    return 0;
}