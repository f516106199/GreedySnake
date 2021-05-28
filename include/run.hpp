#ifndef _RUN_HPP_
#define _RUN_HPP_
#include"snake.hpp"
#include"food.hpp"
#include"utility.hpp"
#include"score.hpp"
#include"scene.hpp"
#include"welcome.hpp"
    namespace snake{
        namespace run{
class runner{
public:
    runner(){}
    void play();
    void init();
private:  
    enum class interval{
        easy=100,
        mid=80,
        hard=60,
        crazy=40
    };
    interval inter;
    size_t xmax;
    size_t ymax;
    size_t xmin;
    size_t ymin;
    GreedySnake snake_;
    food::food food_;
    food::superfood superfood_;
    score::score score_;
    scene::scene winMain;
    welcome::welcome greet;
    scene::choice option;
    std::pair<int,int> eat();
    bool willEat();
    bool willSuperEat();
    bool isDied();    
    std::pair<int,int> superEat();
    mode level;
    void setLevel(const mode&);
    void setBorder(size_t,size_t,size_t,size_t);
    void generateFood();
    void generateSupFood();
    bool crackBorder();
    void clear();
    void running();
};


        }//namespace run
    }//naemspace snake
#endif