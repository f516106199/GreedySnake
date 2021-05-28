#ifndef _COLOR_HPP_
#define _COLOR_HPP_
#include<string>
#include<iostream>
    namespace snake{
        namespace color{
enum class fontColor:int{
    BLACK=30,
    RED=31,
    GREEN=32,
    YELLOW=33,
    BLUE=34,
    PURPLE=35,
    DEEPGRREN=36,
    WHITE=37,
    lblack=00,
    lred=91,
    lgreen=92,
    lyellow=93,
    lblue=94,
    lpurpel=95,
    lDgreen=96,
    lwhite=97,
};

enum class bakColor:int{
    BLACK=40,
    DRED=41,
    GREEN=42,
    YELLOW=43,
    BLUE=44,
    PURPLE=45,
    DGREEN=46,
    WHITE=47
};

class colorStream{
    bakColor bc;
    fontColor fc;
public:
    colorStream(bakColor bc=bakColor::BLACK,fontColor fc=fontColor::WHITE):bc(bc),fc(fc){}
    friend 
    std::ostream&
    operator<<(std::ostream&os,const colorStream& cs){
        return os<<"\033["<<(int)cs.bc<<";"<<(int)cs.fc<<"m";
    }
};


        }//namespace color
    }//namespace snake
#endif