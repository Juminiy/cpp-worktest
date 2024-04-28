#pragma once 
#ifndef _AI_SNAKE_GAME_HPP
#define _AI_SNAKE_GAME_HPP

#include "_i_lib_.hpp"

#include <cstdarg>

#include <vector>
#include <string>
#include <deque>
#include <fstream>
#include <map>

#if (__CC_VER__ > 1)
    #include <unistd.h>
#elif (__CC_VER__ == 1)
    #include <windows.h>
#endif

#define kMaxFood 1<<3
#define kMinFood 5
#define kEmptyTile ' '
#define kWallTile '#'
#define kFoodTile '$'
#define kSnakeTile '*'
#define kSleepTime 1

#define GameTip(_tip_) PRINT(_tip_)
#define GameTips(_tip_, ...) PRINTLN_VA(_tip_, ...)

#define GameFileNamePrefix StaticFilePrefix
#define GameFileNameSuffix ".txt"
#define GenFileName(baseName) \
        GameFileNamePrefix+baseName+GameFileNameSuffix 

// 1,0 -> 0,1 / 0,-1
// 0,1 -> 1,0 / -1,0
// -1,0 -> 0,1 / 0,-1
// 0,-1 -> 1,0 / -1,0
// static int 
// GameDirect[4][2] = 
// {{1,0},{0,1},{-1,0},{0,-1}};

__DEF_NS__(Alan::Demos)

GEN_FUNC_COPY
void GamePause(unsigned int micro_secs)
{   
    #if (__CC_VER__ == 8 || \
            __CC_VER__ ==4)
        usleep(micro_secs);
    #elif (__CC_VER__ == 2)
        sleep(micro_secs / 1000000);
    #elif (__CC_VER__ == 1)
        Sleep(micro_secs * 1000);
    #endif
}

GEN_FUNC_COPY
void GameClearConsole()
{
    #if (__CC_VER__ > 1)
        system("clear");
    #elif (__CC_VER__ == 1)
        system("CLS");
    #endif
}

class pointT
{
public:
    int row, col;
    
    pointT(): row(0), col(0) {}
    pointT(int _row, int _col): 
            row(_row), col(_col){}
    void operator= (pointT const &);
    bool operator== (pointT const &) const;
    bool operator< (pointT const &) const;
    bool operator> (pointT const &) const;
    void walk(int, int);
    void print();

    friend 
    std::ostream& operator << 
    (std::ostream& _os, pointT const & _p)
    {
        _os << "[" 
            << _p.row 
            << ", "
            << _p.col 
            << "]";
        return _os;
    }


    friend 
    std::istream& operator >> 
    (std::istream& _is, pointT & _p)
    {
        _is >> _p.row >> _p.col;
        return _is;
    }
};

typedef struct gameT 
{
    std::vector<std::string> world;
    int numRows, numCols;
    
    std::deque<pointT> snake;
    int dx, dy;

    int numEaten;
    int numFood;

    void ndir();
    bool legal(pointT &);
    bool food(pointT &);

    void load(std::fstream &);
    void init();
    void _mov();
    void mapl();
    void aipl();
    bool SnakeInBound();
    void putf();
    void disp();
    void resp();
    void paus();
    void simu();
} gameT;

__END_NS__


__DEF_NS__(Alan::Demos::Test::Func)

void TestAISnakeGame();

__END_NS__

#endif 