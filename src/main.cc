#include"../include/run.hpp"
#include "windows.h"
#include<iostream>
int main(){
    system("mode con cols=98 lines=38");
    system("color 0f");
    snake::run::runner G;
    G.play();
    system("pause");
}