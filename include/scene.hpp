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
}
    void init(mode);//show border and tips
    void showborder();
    void showsnake(int x,int y);
    void showfood(int x,int y);
    void showtips();
    void showBlank(int x,int y);
   // void showProBar();
    void showSuperf(int x,int y);
    void showCurScore(int v);
    void showMaxScore(int v);
    bool showIfAgain(int,int);
private:
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

