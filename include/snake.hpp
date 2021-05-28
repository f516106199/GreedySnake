#ifndef _GAME_HPP_
#define _GAME_HPP_
#include<deque>
#include"color.hpp"
#include<utility>
#include<vector>
#include<set>
        namespace snake{
            namespace run{
                class runner;
            }
class GreedySnake{
    friend class run::runner;
public:
    GreedySnake():life(1),len(3),headDirect(direction::down),color(color::fontColor::GREEN){}
    void init(int x,int y );
    bool mov();
    bool turnL();
    bool turnR();
    bool turnU();
    bool turnD();
    bool grow();
    bool superGrow();
    void clear(){
        len=3;
        headDirect=direction::down;
        body.clear();
        posSet.clear();
    }
        std::pair<int,int> retHeadPos(){
        return body.front();
    }
private:
    size_t life;  // the number of life
    enum class direction:int{
        unsure,
        right,
        left,
        up,
        down
    };
    size_t len;//total length of snake
    direction headDirect;
    std::deque<std::pair<int,int>>body;
    color::fontColor color;
    std::set<std::pair<int,int>>posSet;
};


        }//namespace snake
#endif