#ifndef _FLAG_TIME
#define _FLAG_TIME 1
#include <iostream>
#include <ctime>
long _initial_clock_time;
long _final_clock_time;
double _print_time_elapsed ()
{
    double _time_elapsed;
    std::cout << "\033[4;32mtime elapsed:\033[m \033[3;35m" << (_time_elapsed = ((double) (_final_clock_time - _initial_clock_time))) / CLOCKS_PER_SEC << "\033[m \033[32mseconds \033[m";
    std::cout << "  \033[3;90m-->> clocks per sec = " << CLOCKS_PER_SEC << "\033[m" << std::endl;
    return _time_elapsed; 
}
#endif