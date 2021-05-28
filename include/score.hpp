#ifndef _SCORE_HPP_
#define _SCORE_HPP_
#include<string>
#include<fstream>
#include"utility.hpp"
    namespace snake{
        namespace score{

class score{
public:
    int retcur(){
        return curScore;
    }
    int retMax(){
        return maxScore;
    }
    bool save();
    void init(mode m);
    void setLevel(mode m);
    void update();
    void updatasup();
    void clear(){
        save();
        curScore=0;
    }
    score():curScore(0){}
private:
    enum class acceleration{
        easy=25,
        mid=30,
        hard=35,
        crazy=40,
        super=50
    };
    acceleration a_score;
    std::string scoreDir;
    int curScore;
    int maxScore;
};
        }//namespace score
    }//namespace snake
#endif