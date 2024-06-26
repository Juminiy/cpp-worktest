#include "../../include/_i_lib_.hpp"
#include "../../include/_ai_snake_game_.hpp"
#include "../../include/_stream_.hpp"

#include <fstream>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <functional>

#include <cassert>
#include <ctime>
#include <cstdlib>

#include <pthread.h>

__USE_NS__(Alan::Demos::Test::Func);
__DEF_NS__(Alan::Demos)

// random left or right 
void gameT::ndir()
{       
    PSEUDORANDOM_DECL;
    int _dd_ = rand() % 2;
    if(dx == 0)
    {   
        dy = 0;
        dx = _dd_ ? 1 : -1;
    } else 
    {
        dx = 0; 
        dy = _dd_ ? 1 : -1;
    }
}

bool gameT::legal(pointT &_p)
{
    return _p.row > 0 && 
            _p.row < numRows-1 && 
            _p.col > 0 && 
            _p.col < numCols-1 &&
            world[_p.row][_p.col] != kWallTile;
}

bool gameT::food(pointT &_p)
{
    return legal(_p) && 
            world[_p.row][_p.col] == kFoodTile;
}

void gameT::load(std::fstream &fileInput)
{
    fileInput >> numRows >> numCols;
    world.resize(numRows);
    fileInput >> dx >> dy; 
    numFood =0;
    std::string _line;
    getline(fileInput, _line);
    if (!_line.size() || 
        !_line.compare("\n") || 
        !_line.compare("\t") || 
        _line.compare(" "))
        // TODO: do something to avoid 
    for(int row = 0; row < numRows; ++row)
    {    
        getline(fileInput, world[row]);
        size_t col = 0;
        if ((col = world[row].find(kSnakeTile)) != std::string::npos)
            snake.push_back(pointT(row, col));
             
        numFood += count_if( world[row].cbegin(), 
                                world[row].cend(), 
                                []
                                (char const &_x) 
                                { return _x == kFoodTile; });
    }
    numEaten = 0;
}

void gameT::init()
{      
    GameTip("File name:");
    std::string fileName = GetLine();
    ASSERT_FILE(GenFileName(fileName));
    load(*inputFile);
}

bool gameT::SnakeInBound()
{
    return legal(snake.front());
}

void gameT::putf()
{
    if (numFood >= kMinFood)
        return ;
    PSEUDORANDOM_DECL;
    int _ex_ = (rand() % (numRows-1)) + 1;
    int _ey_ = (rand() % (numCols-1)) + 1;
    if (world[_ex_][_ey_] == kEmptyTile)
        world[_ex_][_ey_] = kFoodTile;
}

void gameT::_mov()
{   
    pointT nextP(snake.front());
    pointT tmpP = nextP;
loopWalk:
    tmpP.walk(dx, dy);
    // ilegal
    if (!legal(tmpP))
    {   
        ndir();
        goto loopWalk;
    } 
    // ate $
    else 
    {
        nextP = tmpP;
        snake.push_front(nextP);
        if(food(nextP))
        {   
            world[nextP.row][nextP.col] = kEmptyTile;
            ++numEaten;
            --numFood;
        } else
        {   
            pointT snake_tail = snake.back();
            world[snake_tail.row][snake_tail.col] = kEmptyTile;
            snake.pop_back();
        }
        world[nextP.row][nextP.col] = kSnakeTile;
    }
}

void gameT::mapl()
{

}

void gameT::aipl()
{   
    _mov();
    // GamePause(1000000);
}

void gameT::disp()
{   
    GameClearConsole();
    for( auto &s : world)
    {
        PRINTLN(s);
    }
}

void gameT::resp()
{
    std::cout << "You ate " 
        << numEaten 
        << " pieces of food" 
        << __LN__;

    if (numEaten == kMaxFood)
    {
        PRINTLN("Game Wins");
    } else 
    {
        PRINTLN("Game Over");
    }
}

void gameT::paus()
{
    GamePause(500000);
}

void gameT::simu()
{   
    while(numEaten < kMaxFood)
    {
        disp();
        aipl();
        if (!SnakeInBound())
            break;
        putf();
        paus();
    }
    resp();
}

void pointT::walk(int _dx, int _dy)
{
    row += _dx;
    col += _dy;
}

void pointT::operator= (pointT const &_p) 
{
    row = _p.row;
    col = _p.col;
}

bool pointT::operator== (pointT const &_p) const 
{
    return row == _p.row &&
            col == _p.col;
}

bool pointT::operator< (pointT const &_p) const 
{
    return (row == _p.row) ? 
            (col < _p.col) : 
            (row < _p.row);
}

bool pointT::operator> (pointT const &_p) const 
{
    return (row == _p.row) ? 
            (col > _p.col) : 
            (row > _p.row);
}

void pointT::print()
{
    std::cout << "[" 
                << row 
                << ", "
                << col 
                << "]";
}

__END_NS__

// TODO:
// 1. make a tradeoff between class-inner and class-outer decl friend functions
// 2. make a test of class-outer define functions

__USE_NS__(Alan::Demos);
__DEF_NS__(Alan::Demos::Test::Func)

void 
TestAISnakeGame()
{
    gameT gmt = gameT();
    gmt.init();
    gmt.simu();
}

__END_NS__