#include"../include/food.hpp"
#include<ctime>
    namespace snake{
        namespace food{

void food::setPos(int x,int y){
    pos.first=x;
    pos.second=y;
}
void superfood::setPos(int x,int y){
    pos.first=x;
    pos.second=y;
    isexited=true;
    sTime=clock();
}
size_t superfood::recordTime(){
    eTime=clock();
    return eTime-sTime;
}


        }//namespace food
    }//namespace snake