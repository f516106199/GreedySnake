#include"../include/welcome.hpp"
#include<fstream>
#include<windows.h>
#include<iostream>
#include<algorithm>
#include"../include/utility.hpp"
    namespace snake{
        namespace welcome{
            using bcolor=color::bakColor;
            using fcolor=color::fontColor;

void welcome::gensnkStr(){
    snkStr.clear();
    for(int i=0;i!=4;++i){
        if(flowPos[i].empty()){
            snkStr+="\n\b";
            continue;
        }
        for(int j=0,k=flowPos[i].size()-1;k!=-1;++j){
            if(flowPos[i].at(k)==j){
                snkStr+=squre;
                ++j;
                --k;
            }
            else {
                snkStr+=" ";
            }
        }
        snkStr+="\n\b";
    }
}
void welcome::showTxt(){
    system("cls");
    std::cout<<"\n\n\n\n\n";
    std::cout<<styleVec[5]<<longSTr<<"\033[0m";
}

void welcome::show(){
    readTxt();
    flowSneak.clear();
    flowSneak.push_front(std::make_pair(0,1));
    flowPos.clear();
    flowPos.resize(4);
    flowPos[1].push_front(flowSneak.front().first);
    color::colorStream cS;
    dir=0;
    int i=0;
    while(1){
        i=i%6;
        cS=(styleVec[i]);
        ++i;
        gensnkStr();
        system("cls"); 
        printSneak(cS);
        if(flowSneak.empty()){
            break;
        }
        else if(flowSneak.size()<9&&flowSneak.front().first<winX-2){
            modiStatus_1();
        }
        else if(flowSneak.size()<9&&flowSneak.front().first==winX-2){
            modiStatus_3();
        }
        else if(flowSneak.size()==9){
            modiStatus_2();
        }
        Sleep(15);
    }
    Sleep(800);
    std::cout<<std::endl<<std::endl<<std::endl;
    std::cout<<"\t\t\t\t   "<<color::colorStream(color::bakColor::BLACK,color::fontColor::WHITE)<<" press any key to start ..."<<"\033[0m"<<std::endl<<std::endl;
    std::cout<<"\t\t\t\t   "<<color::colorStream(color::bakColor::BLACK,color::fontColor::WHITE)<<"   请按任意键开始游戏..."<<"\033[0m";
}

void welcome::printSneak(const color::colorStream& cS){
    std::cout<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl;
    std::cout<<cS<<longSTr<<"\033[0m";
    std::cout<<std::endl<<std::endl<<std::endl;
    std::cout<<styleVec[0]<<snkStr<<"\033[0m";
}       

void welcome::modiStatus_1(){
    if(!dir){
        auto p=flowSneak.front();
        if(p.second==1){
            dir=!dir;
        }
        p.first+=2;
        p.second-=1;
        flowSneak.push_front(p);
        flowPos[p.second].push_front(p.first);
    }
    else {
        auto p=flowSneak.front();
        if(p.second==2){
            dir=!dir;
        }
        p.first+=2;
        p.second+=1;
        flowSneak.push_front(p);
        flowPos[p.second].push_front(p.first);
    }
}

void welcome::modiStatus_2(){
    auto tail=flowSneak.back();
    flowPos[tail.second].pop_back();
    flowSneak.pop_back();
    auto p=flowSneak.front();
    if(p.first==winX-2){
        return ;
    }
    if(!dir){
        if(p.second==1){
            dir=!dir;
        }
        p.first+=2;
        p.second-=1;
        flowSneak.push_front(p);
        flowPos[p.second].push_front(p.first);
    }
    else{
        if(p.second==2){
            dir=!dir;
        }
        p.first+=2;
        p.second+=1;
        flowSneak.push_front(p);
        flowPos[p.second].push_front(p.first);
    }
}
void welcome::modiStatus_3(){
    auto tail=flowSneak.back();
    flowPos[tail.second].pop_back();
    flowSneak.pop_back();
}
void welcome::readTxt(){
    std::ifstream is;
    is.open("../data/preText.txt");
    if(!is.is_open()){
        std::cerr<<"lack of file preText.txt "<<std::endl;
        exit(-1);
    }
    char ch;
    longSTr+="\t\t";
    while(is.get(ch)){
        if(ch=='*'){
            is.get(ch);
            longSTr+=squre;
        }
        else if(ch=='\n'){
            longSTr+="\n\b\t\t";
        }
        else
            longSTr+=" ";
    }
    is.close();
}
        }//namespace snake
    }//namespace welcome