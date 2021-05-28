#include"../include/run.hpp"
#include"../include/utility.hpp"
#include<windows.h>
    namespace snake{
    int winX=98;
    int winY=38;
    int borderxmin=4;
    int borderxmax=70;
    int borderymin=3;
    int borderymax=34;
    const char* squre="¡ö";
    const char* circle="¡ñ";
    const char* star="¡ï";
    const char* holestar="¡î";
        namespace run{
std::pair<int,int> runner::eat(){
    auto p=food_.RetPos();
    score_.update();
    generateFood();
    return p;
}
std::pair<int,int> runner::superEat(){
    auto p=superfood_.RetPos();
    superfood_.erase();
    score_.updatasup();
    return p;
}
bool runner::willEat(){
    if(snake_.retHeadPos()==food_.RetPos()){
        return true;
    }
    else return false;
}
bool runner::isDied(){
    return crackBorder();
}
bool runner::willSuperEat(){
    if(snake_.retHeadPos()==superfood_.RetPos()){
        return true;
    }
    else return false;
}

void runner::setLevel(const mode& m){
    level=m;
}
void runner::init(){
    srand(time(0));
    switch (level){
        case mode::crazy:
        inter=interval::crazy;break;
        case mode::easy:
        inter=interval::easy;break;
        case mode::hard:
        inter=interval::hard;break;
        case mode::mid:
        default:
            inter=interval::mid;break;
    }
    setBorder(borderxmin,borderxmax,borderymin,borderymax);
    system("cls");
    winMain.init(level);
    score_.init(level);
    snake_.init((borderxmax+borderxmin-1)/2,(borderymin+borderymax-1)/2);
    for(auto m:snake_.posSet){
        winMain.showsnake(m.first,m.second);
    }
    generateFood();
    winMain.showfood(food_.RetPos().first,food_.RetPos().second);
}
void runner::setBorder(size_t a ,size_t b,size_t c,size_t d){
    xmin=a;xmax=b;ymin=c;ymax=d;
}
bool runner::crackBorder(){
    auto headPos=snake_.retHeadPos();
    if(headPos.first<xmin||headPos.first>xmax){
        return 1;
    }
    if(headPos.second>ymax||headPos.second<ymin){
        return 1;
    }
    return 0;
}
void runner::generateFood(){
    int x,y;
    int xmod=(xmax-xmin)/2;
    int ymod=(ymax-ymin)/2;
    if(!superfood_.isExited()){
        while(1){
            x=rand()%xmod+1;
            y=rand()%ymod+1;
            x=xmin+2*x;
            y=ymin+2*y;
            if(snake_.posSet.find({x,y})==snake_.posSet.end()){
                break;
            }
        }
    }
    else{
        while(1){
            x=rand()%xmod+1;
            y=rand()%ymod+1;
            x=xmin+2*x;
            y=ymin+2*y;
            if(snake_.posSet.find({x,y})!=snake_.posSet.end()){
                continue;
            }
            if(x==superfood_.RetPos().first&&y==superfood_.RetPos().second){
                continue;
            }
            break;
        }
    }
    food_.setPos(x,y);
}
void runner::generateSupFood(){
    int mod6=rand()%20;
    int xmod=(xmax-xmin)/2;
    int ymod=(ymax-ymin)/2;
    if(mod6==3){
        int x,y;
        while(1){
            x=rand()%xmod+1;
            y=rand()%ymod+1;
            x=xmin+2*x;
            y=ymin+2*y;
            if(snake_.posSet.find({x,y})!=snake_.posSet.end()){
                continue;
            }
            if((x==superfood_.RetPos().first)&&y==superfood_.RetPos().second){
               continue;
            }
            break;
        }
        superfood_.setPos(x,y);
    }
    return ;
}

void runner::play(){
    greet.show();
    getch();
    while(1){
       system("cls");
       greet.showTxt();
       option.show();
       auto kind=option.retChoice();
       switch (kind){
           case scene::choice::Kind::easy :
           level=mode::easy;break;
           case scene::choice::Kind::mid :
           level=mode::mid;break;
           case  scene::choice::Kind::hard:
           level=mode::hard;break;
           case scene::choice::Kind::crazy :
           level=mode::crazy;break;
           case scene::choice::Kind::exit :
                return ;
       }
       init();
       running();
       if(winMain.showIfAgain(score_.retcur(),score_.retMax())){
           clear();
       }
       else{
           return ;
       }
    }
}

void runner::running(){
    char ch;
    while(1){
    winMain.showBlank(snake_.body.back().first,snake_.body.back().second);
    if(_kbhit()){
        ch=getch();
        switch (ch){
            case 'A':
            case 'a':
            if(snake_.headDirect==GreedySnake::direction::right){
                if(!snake_.mov()){
                    return;
                }
            }
            else{
                if(!snake_.turnL()){
                    return;
                }
            }
            break;
            case 'w':
            case 'W':
            if(snake_.headDirect==GreedySnake::direction::down){
                if(!snake_.mov()){
                    return;
                }
            }
            else {
                if(!snake_.turnU()){
                    return;
                }
            }
            break;
            case 'd':
            case 'D':
            if(snake_.headDirect==GreedySnake::direction::left){
                if(!snake_.mov()){
                    return;
                }   
            }
            else {
                if(!snake_.turnR()){
                    return;
                }
            }
                break;
            case 's':
            case 'S':
            if(snake_.headDirect==GreedySnake::direction::up){
                if(!snake_.mov()){
                    return;
                }
            }
            else {
                if(!snake_.turnD()){
                    return;
                }
            }
                break;
            case '\x20':
                system("pause");
                break;
            default:
                if(!snake_.mov()){
                    return;
                }
                break;
        }
    }
    else {
        if(!snake_.mov()){
            return;
        };
    }
    winMain.showsnake(snake_.retHeadPos().first,snake_.retHeadPos().second);
    if(isDied()){
        return;
    }
    if(willEat()){
        auto pt=eat();
        snake_.grow();
        winMain.showsnake(snake_.retHeadPos().first,snake_.retHeadPos().second);
        generateFood();
        winMain.showfood(food_.RetPos().first,food_.RetPos().second);
    }  
    if(superfood_.isExited()){
        if(willSuperEat()){
            auto pt=superEat();
            snake_.grow();
            winMain.showsnake(snake_.retHeadPos().first,snake_.retHeadPos().second);
        }
        else if(superfood_.Timeover()){
            winMain.showBlank(superfood_.RetPos().first,superfood_.RetPos().second);
        }
    }            
    else {
        generateSupFood();
        if(superfood_.isExited()){
            winMain.showSuperf(superfood_.RetPos().first,superfood_.RetPos().second);
        }
    }
    winMain.showMaxScore(score_.retMax());
    winMain.showCurScore(score_.retcur());
    Sleep((int)inter);
    }
}

void runner::clear(){
    snake_.clear();
    score_.clear();
    superfood_.clear();
}

        }//namespace run
    }//namespace snake