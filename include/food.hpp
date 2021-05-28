#ifndef _FOOD_HPP_
#define _FOOD_HPP_
#include"color.hpp"
#include<utility>
        namespace snake{
            namespace food{
class food{
public:
    food():color(color::fontColor::PURPLE){}
    virtual void setPos(int,int);
    std::pair<int,int> RetPos(){
        return pos;
    }
protected:
    std::pair<int,int>pos; 
    color::fontColor color;
};
class superfood:public food{
public:
    void clear(){
        erase();
    }
    bool isExited(){
        return isexited;
    }
    size_t recordTime();
    bool Timeover(){
        if(recordTime()>=showTime){
            isexited=0;
            return 1;
        }
        return 0;
    }
    void erase(){
        isexited=0;
    }
    virtual void setPos(int,int)override; 
    superfood():food(),showTime(7000){}
private:
    int sTime;
    int eTime;
    bool isexited;
    int showTime;
};
            }//namespace food
        }//namespace snake
#endif