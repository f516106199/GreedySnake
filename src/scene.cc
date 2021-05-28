#include"../include/scene.hpp"
#include"../include/color.hpp"
#include"windows.h"
#include<iostream>
#include<conio.h>
namespace snake{
    namespace scene{
void scene::init(mode m){
    if(posBorder.empty()){
        for(int i=borderxmin-2;i<=borderxmax+2;i+=2){
            posBorder.push_back({i,borderymin-1});
            posBorder.push_back({i,borderymax+1});
        }
        for(int j=borderymin;j<=borderymax;j++){
            posBorder.push_back({borderxmin-2,j});
            posBorder.push_back({borderxmax+2,j});
        }
    }
    if(m==mode::crazy){
        level="ج��";
    }
    else if(m==mode::easy){
        level="��";
    }
    else if(m==mode::hard){
        level="����";
    }
    else {
        level="һ��";
    }
    showborder();
    showtips();
}
void scene::showborder(){
    for(const auto& m:posBorder){
        std::cout<<"\033["<<m.second<<";"<<m.first<<"H\033[31m"<<squre<<"\033[0m\033[0;0H";
    }
}
void scene::showsnake(int x,int y){
    std::cout<<"\033["<<y<<";"<<x<<"H\033[32m"<<circle<<"\033[0m\033[0;0H";
}
void scene::showfood(int x,int y){
    std::cout<<"\033["<<y<<";"<<x<<"H\033[37m"<<holestar<<"\033[0m\033[0;0H";
}
void scene::showSuperf(int x,int y){
    std::cout<<"\033["<<y<<";"<<x<<"H\033[5;33;40m"<<star<<"\033[0m\033[0;0H";
}
void scene::showtips(){
    std::cout<<"\033["<<maxScorePos.second-7<<";"<<maxScorePos.first<<"H"<<titleEn;
    std::cout<<"\033["<<maxScorePos.second-5<<";"<<maxScorePos.first<<"H"<<titileCn;
    std::cout<<"\033["<<maxScorePos.second-3<<";"<<maxScorePos.first<<"H"<<"�Ѷ�"<<level;
    std::cout<<"\033["<<curScorePos.second-1<<";"<<curScorePos.first<<"H"<<curScoretxt;
    std::cout<<"\033["<<maxScorePos.second-1<<";"<<maxScorePos.first<<"H"<<maxScoretxt;
    std::cout<<"\033["<<curScorePos.second+2<<";"<<maxScorePos.first<<"H"<<guarde;
    std::cout<<"\033["<<curScorePos.second+4<<";"<<maxScorePos.first<<"H"<<instruct;
    showCurScore(0);
    showMaxScore(0);
}
// void scene::showOver(){

// }
void scene::showBlank(int x,int y){
    std::cout<<"\033["<<y<<";"<<x<<"H"<<"  "<<"\033[0m\033[0;0H";
}
void scene::showCurScore(int v=0){
    std::cout<<"\033["<<curScorePos.second<<";"<<curScorePos.first<<"H"<<v<<"\033[0m\033[0;0H";
}
void scene::showMaxScore(int v=0){
    std::cout<<"\033["<<maxScorePos.second<<";"<<maxScorePos.first<<"H"<<v<<"\033[0m\033[0;0H";
}

bool scene::showIfAgain(int cur,int max){
     for(int i=borderxmin+20;i!=borderxmin+55;++i){
         std::cout<<"\033["<<borderymin+8<<";"<<i<<"H\033[1;34m-\033[0m\033[0;0H";
         std::cout<<"\033["<<borderymin+24<<";"<<i<<"H\033[1;34m-\033[0m\033[0;0H";
     }
     for(int j=borderymin+9;j!=borderymin+24;++j){
         std::cout<<"\033["<<j<<";"<<borderxmin+19<<"H\033[1;34m|\033[0m\033[0;0H";
         std::cout<<"\033["<<j<<";"<<borderxmin+55<<"H\033[1;34m|\033[0m\033[0;0H";
     }
     std::cout<<"\033["<<borderymin+11<<";"<<borderxmin+33<<"H\033[1;34m����ˣ�\033[0m\033[0;0H";
     std::cout<<"\033["<<borderymin+13<<";"<<borderxmin+33<<"H\033[1;34m����:"<<cur<<"\033[0m\033[0;0H";
     std::cout<<"\033["<<borderymin+15<<";"<<borderxmin+32<<"H\033[1;34m��߷�:"<<max<<"\033[0m\033[0;0H";
     std::cout<<"\033["<<borderymin+18<<";"<<borderxmin+31<<"H\033[1;34m�Ƿ������Ϸ???\033[0m\033[0;0H";
     std::cout<<"\033["<<borderymin+22<<";"<<borderxmin+25<<"H\033[1;34m->�������Ҳ���  ��Ҳ������\033[0m\033[0;0H";
    char ch;
    bool again=1;
    while(1){
        if(_kbhit()){
            ch=getch();
            if(ch=='d'||ch=='D'){
                again=0;
                std::cout<<"\033["<<borderymin+22<<";"<<borderxmin+39<<"H\033[1;34m->\033[0m\033[0;0H";
                std::cout<<"\033["<<borderymin+22<<";"<<borderxmin+25<<"H\033[1;34m  \033[0m\033[0;0H";
            }
            else if(ch=='a'||ch=='A'){
                again=1;
                std::cout<<"\033["<<borderymin+22<<";"<<borderxmin+25<<"H\033[1;34m->\033[0m\033[0;0H";
                std::cout<<"\033["<<borderymin+22<<";"<<borderxmin+39<<"H\033[1;34m  \033[0m\033[0;0H";
            }
            else if(ch=='\r'){
                return again;
            }
        }
    }
}

// void scene::showProBar(){

// }

choice::Kind choice::retChoice(){
    return kind;
}
void choice::refresh(){
    std::cout<<"\033["<<begY+(int)prekind*2<<";"<<cursorX<<"H  \033[0m";
    prekind=kind;
    std::cout<<"\033["<<begY+(int)kind*2<<";"<<cursorX<<"H\033[1;33m->\033[0m\033[?25l";
}
void choice::show(){
    print();
    refresh();
    char ch;
    while(1){
        if(_kbhit()){
            ch=getch();
            if(ch==' '){
                kind =(Kind)(((int)kind +1)%5);
                refresh();
            }
            else if(ch=='\r'){
                return ;
            }
        }
    }
}
void choice::print(){
   std::cout<<"\033["<<begY-3<<";"<<begX-10<<"H\033[31m "<<"ʹ�ÿո��л�ѡ��,��enterȷ��\033[0m";
   std::cout<<"\033["<<begY<<";"<<begX<<"H ��\033[0m";
   std::cout<<"\033["<<begY+2<<";"<<begX<<"H һ��\033[0m";
   std::cout<<"\033["<<begY+4<<";"<<begX<<"H ����\033[0m";
   std::cout<<"\033["<<begY+6<<";"<<begX<<"H ج��\033[0m";
   std::cout<<"\033["<<begY+8<<";"<<begX<<"H �˳�\033[0m";
}
    }//namespace scene
}//namespace snake