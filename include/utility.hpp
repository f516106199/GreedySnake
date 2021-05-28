#ifndef _RANDOM_HPP_
#define _RANDOM_HPP_
#include<ctime>
#include<cstdlib>
namespace snake{
     enum class mode{
            easy,
            mid,
            hard,
            crazy
         };

    inline void seeds(){
        std::srand(time(0));
    }
    extern  int winX;
    extern  int winY;
    extern  int borderxmin;
    extern  int borderxmax;
    extern  int borderymin;
    extern  int borderymax;
    extern const char* squre;
    extern const char* circle;
    extern const char* star;
    extern const char* holestar;
}
#endif