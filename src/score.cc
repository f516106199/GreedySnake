#include"../include/score.hpp"
#include<iostream>
    namespace snake{
        namespace score{
bool score::save(){
    std::ofstream os;
    os.open(scoreDir,std::ios::ate|std::ios::out);
    if(!os.is_open()){
        std::cerr<<"failt to open file to write"<<std::endl;
        exit(-1);
    }
    os<<maxScore<<std::ends;
    os.close();
    return 1;
}
void score::init(mode m){
    scoreDir="./data/score.txt";
    std::ifstream is;
    is.open(scoreDir,std::ios::in);
    if(!is.is_open()){
        std::cerr<<"fail to open file to read"<<std::endl;
        exit(-1);
    }
    curScore=maxScore=0;
    while(is>>curScore){
        maxScore=(curScore>maxScore)?curScore:maxScore;
    }
    curScore=0;
    is.close();
    if(m==mode::easy){
        a_score=acceleration::easy;
    }
    else if(m==mode::hard){
        a_score=acceleration::hard;
    }
    else if(m==mode::crazy){
        a_score=acceleration::crazy;
    }
    else{
        a_score=acceleration::mid;
    }
}
void score::update(){
   curScore+=(int)a_score;
   if(curScore>maxScore){
       maxScore=curScore;
   }
}
void score::updatasup(){
    curScore+=(int)acceleration::super;
    if(curScore>maxScore){
        maxScore=curScore;
    }
}
void score::setLevel(mode m){
    switch (m){
        case mode::crazy:
            a_score=acceleration::crazy;
            break;
        case mode::hard:
            a_score=acceleration::hard;
            break;
        case mode::mid:
            a_score=acceleration::mid;
            break;
        case mode::easy:
            a_score=acceleration::easy;
            break;
        default:
            break;
    }
}

        }//namespace score
    }//namespace snake