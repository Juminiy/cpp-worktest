#pragma once 
#ifndef _AI_SNAKE_GAME_HPP
#define _AI_SNAKE_GAME_HPP


#include "_i_lib_.hpp"

#include <vector>
#include <string>
#include <deque>
#include <fstream>

#include <cstdarg>

#define kMaxFood 1<<5
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

#define GameTip(_tip_) cout << _tip_ ;
#define GameTips(_tip_, ...) \ 
    va_list _list; \ 
    double _list_n; \
    va_start(_list); \
    va_end(_list);  \
    cout << _tip_ << _list <<endl

#define GameFileNamePrefix "../test/static-file/"
#define GameFileNameSuffix ".txt"
#define GenFileName(baseName) GameFileNamePrefix+baseName+GameFileNameSuffix 

static void inline GamePause(unsigned int micro_secs)
{
    #if defined(__APPLE__) || defined(__MACH__) || defined(__MACOS__)
    #include <unistd.h>
    usleep(micro_secs);
    #elif defined(_WIN64) || defined(WIN64) || \
        defined(_WIN32) || defined(WIN32) 
    #include <windows.h>
    sleep(micro_sec / 1000000);
    #endif 
}

typedef struct pointT
{
    int row, col;
    pointT(int _row, int _col): row(_row), col(_col){}
} pointT;

typedef struct gameT 
{
    vector<string> world;
    int numRows, numsCols;
    
    deque<pointT> snake;
    int dx, dy;

    int numEaten;

    void load(fstream &);
    void init();
    bool SnakeInBound();
    bool _mov();
    void mapl();
    void aipl();
    void SyncSnake();
    void disp();
    void resp();
    void paus();
    void simu();
} gameT;


#endif 