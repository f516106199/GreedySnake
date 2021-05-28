#ifndef _WELCOME_HPP_
#define _WELCOME_HPP_
#include"color.hpp"

#include<conio.h>
#include<ctime>
#include<deque>
#include<queue>
#include<utility>
#include<array>
#include<string>
#include<set>
#include<vector>
        namespace snake{
            namespace welcome{
class welcome{
    enum  style:int{
        blackGreen=0,
        blackWhite=1,
        blackBlue=2,
        blackPurple=3,
        blackYellow=4,
    };
public:
    void show();
    void showTxt();
    welcome():shiningTime(0),lastTime(5000){
        styleVec[0]=color::colorStream(color::bakColor::BLACK,color::fontColor::lgreen);
        styleVec[1]=color::colorStream(color::bakColor::BLACK,color::fontColor::lwhite);
        styleVec[2]=color::colorStream(color::bakColor::BLACK,color::fontColor::lblue);
        styleVec[3]=color::colorStream(color::bakColor::BLACK,color::fontColor::lpurpel);
        styleVec[4]=color::colorStream(color::bakColor::BLACK,color::fontColor::lyellow);
        styleVec[5]=color::colorStream(color::bakColor::BLACK,color::fontColor::lred);
    };
private:
    std::string longSTr;
    std::string snkStr;
    std::array<color::colorStream,6>styleVec;
    int shiningTime;
    int lastTime;
    std::deque<std::pair<int,int>>flowSneak;
    std::vector<std::deque<int>>flowPos;
    bool dir;
    void printSneak(const color::colorStream&os);
    void modiStatus_1();
    void modiStatus_2();
    void modiStatus_3();
    void readTxt();
    void gensnkStr();
    void printItem();
};
            }//namespace welcode
        }//namespace snake



#endif