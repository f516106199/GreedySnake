#ifndef _SCENE_HPP_
#define _SCENE_HPP_
#include<string>
#include<array>
#include"utility.hpp"
#include<vector>
    namespace snake{
        namespace scene{
class scene{
public:
    scene():titileCn("̰����"),titleEn("GreedySnake"),curScoretxt("��ǰ����"),instruct("��esc�˳�,�ո���ͣ"),
                                maxScoretxt("��߷���"),guarde("ʹ��wasd�����ƶ�"),
                                maxScorePos({borderxmax+4,borderymin+12}),curScorePos({borderxmax+4,borderymin+15}){
                                    colorV[0]=color::yellow;colorV[1]=color::green;colorV[2]=color::purple;colorV[3]=color::whilte;
}
    void init(mode);//show border and tips
    void showborder();
    void showsnake(int x,int y);
    void showfood(int x,int y);
    void showtips();
    void showBlank(int x,int y);
    void showProBar();
    void showSuperf(int x,int y);
    void showCurScore(int v);
    void showMaxScore(int v);
    bool showIfAgain(int,int);
    void enShortBar();
    void eraseBar();
private:
    enum class color{
        red=31,
        green=32,
        yellow=33,
        blue=34,
        purple=35,
        whilte=97
    };
    int snkColorIndex=0;
    std::array<color,4>colorV;
    int startBarx;
    std::vector<std::pair<int,int>>posBorder;
    std::string level;
    std::pair<int,int>curScorePos;
    std::pair<int,int>maxScorePos;
    const std::string titleEn;
    const std::string titileCn;
    const std::string curScoretxt;
    const std::string maxScoretxt;
    const std::string guarde;
    const std::string instruct;
};

class choice{
public:
    enum class Kind{
        easy=0,
        mid,
        hard,
        crazy,
        exit
    };
    Kind kind;
    Kind prekind;
    choice():begX(borderxmin+(borderxmax-borderxmin)*3/5),begY(borderymin+(borderymax-borderymin)*2/3),cursorX(begX-2),
                                    kind(Kind::easy),prekind(Kind::easy){}
    void show();
    void refresh();
    Kind retChoice();
private:
    void print();
    int begX;
    int begY;
    int cursorX;
};

        }//namespace scene
    }//namespace snake
#endif

