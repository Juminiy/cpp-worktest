#pragma once 
#ifndef _AI_SNAKE_GAME_HPP
#define _AI_SNAKE_GAME_HPP

#include "_i_lib_.hpp"

#include <vector>
#include <string>
#include <deque>
#include <fstream>
#include <map>

#include <cstdarg>

#define kMaxFood 1<<3
#define kMinFood 5
#define kEmptyTile ' '
#define kWallTile '#'
#define kFoodTile '$'
#define kSnakeTile '*'

#define kSleepTime 1

#define CROSS_MACOS_WINDOWS 
#if defined(__APPLE__) || defined(__MACH__) || defined(__MACOS__)
#include <unistd.h>
#elif defined(_WIN64) || defined(WIN64) || \
        defined(_WIN32) || defined(WIN32) 
#include <windows.h>
#endif 

#define GameTip(_tip_) std::cout << _tip_ ;
#define GameTips(_tip_, _extras_) \
            std::cout << _tip_ << endl; \
            std::cout << _extras_ << endl; 

#define GameFileNamePrefix StaticFilePrefix
#define GameFileNameSuffix ".txt"
#define GenFileName(baseName) GameFileNamePrefix+baseName+GameFileNameSuffix 

static void inline GamePause(unsigned int micro_secs)
{
    #if defined(__APPLE__) || \
        defined(__MACH__) || \
        defined(__MACOS__)
    #include <unistd.h>
    usleep(micro_secs);
    #elif defined(_WIN64) || \
            defined(WIN64) || \
            defined(_WIN32) || \
            defined(WIN32) 
    #include <windows.h>
    Sleep(micro_secs * 1000);
    #endif 
}

static void inline GameClearConsole()
{
    #if defined(__APPLE__) || \
        defined(__MACH__) || \
        defined(__MACOS__)
    #include <unistd.h>
    system("clear");
    #elif defined(_WIN64) || \
            defined(WIN64) || \
            defined(_WIN32) || \
            defined(WIN32) 
    #include <windows.h>
    system("CLS");
    #endif 
}

// 1,0 -> 0,1 / 0,-1
// 0,1 -> 1,0 / -1,0
// -1,0 -> 0,1 / 0,-1
// 0,-1 -> 1,0 / -1,0
// static int GameDirect[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};


typedef struct pointT
{
    int row, col;
    
    pointT(int _row, int _col): row(_row), col(_col){}
    void operator= (pointT const &);
    bool operator== (pointT const &) const;
    bool operator< (pointT const &) const;
    bool operator> (pointT const &) const;
    void walk(int, int);
    void print();

} pointT;
std::ostream& operator<<(std::ostream&, pointT const &);


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

void TestAISnakeGame();

#endif 