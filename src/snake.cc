#include"../include/snake.hpp"
    namespace snake{

void GreedySnake::init(int x,int y){
    body.push_front(std::make_pair(x,y-2));
    posSet.insert(body.front());
    body.push_front(std::make_pair(x,y-1));
    posSet.insert(body.front());
    body.push_front(std::make_pair(x,y));
    posSet.insert(body.front());
}
bool GreedySnake::mov(){
    if(headDirect==direction::down){
       return turnD();
    }
    else if(headDirect==direction::up){
       return  turnU();
    }
    else if(headDirect==direction::right){
        return turnR();
    }
    else if(headDirect==direction::left){
        return turnL();
    }
    else {
        std::cerr<<"havn't set mov direction well"<<std::endl;
        exit(-1);
    }
}
bool GreedySnake::turnL(){
    headDirect=direction::left;
    auto h=body.front();
    h.first-=2;
    auto t=body.back();
    body.pop_back();
    posSet.erase(t);
    if(posSet.find(h)!=posSet.end()){
        return 0;
    }
    body.push_front(h);
    posSet.insert(h);
    return 1;
}
bool GreedySnake::turnR(){
    headDirect=direction::right;
    auto h=body.front();
    h.first+=2;
    auto t=body.back();
    body.pop_back();
    posSet.erase(t);
    if(posSet.find(h)!=posSet.end()){
        return 0;
    }
    body.push_front(h);
    posSet.insert(h);
    return 1;
}
bool GreedySnake::turnU(){
    headDirect=direction::up;
    auto h=body.front();
    --h.second;
    auto t=body.back();
    body.pop_back();
    posSet.erase(t);
    if(posSet.find(h)!=posSet.end()){
        return 0;
    }
    body.push_front(h);
    posSet.insert(h);
    return 1;
}
bool GreedySnake::turnD(){
    headDirect=direction::down;
    auto h=body.front();
    ++h.second;
    auto t=body.back();
    body.pop_back();
    posSet.erase(t);
    if(posSet.find(h)!=posSet.end()){
        return 0;
    }
    body.push_front(h);
    posSet.insert(h);
    return 1;
}
bool GreedySnake::grow(){
    auto p=body.front();
    if(headDirect==direction::down){
        p.second++;
    }
    else if(headDirect==direction::left){
        p.first-=2;
    }
    else if(headDirect==direction::right){
        p.first+=2;
    }
    else if(headDirect==direction::up){
        p.second--;
    }
    else{
        std::cerr<<"direction havn't been inited"<<std::endl;
        exit(-1);
    }
    body.push_front(p);
    posSet.insert(p);
    ++len;
    return 1;
}
bool GreedySnake::superGrow(){
    grow();
    return 1;
}


    }//namespace snake