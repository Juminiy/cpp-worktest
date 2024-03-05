#include "_ai_snake_game_.hpp"
#include "_stream_.hpp"


#include <fstream>
#include <algorithm>
#include <iostream>
#include <iterator>

#include <cassert>
#include <ctime>

#include <pthread.h>


void gameT::setDirect(int _dx, int _dy)
{
    dx = _dx;
    dy = _dy;
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

void gameT::load(fstream &fileInput)
{
    fileInput >> numRows >> numCols;
    world.resize(numRows);
    fileInput >> dx >> dy;
    for(int row = 0, col = 0; row < numRows; row++)
    {
        getline(fileInput, world[row]);
        if ((col = world[row].find(kSnakeTile)) != string::npos)
        {
            snake.push_back(pointT(row, col));
        }        
    }
    numEaten = 0;
}

void gameT::init()
{      
    GameTip("File name:");
    string fileName = GetLine();
    ASSERT_FILE(GenFileName(fileName));
    load(*inputFile);
}

bool gameT::SnakeInBound()
{
    return legal(snake.front());
}

bool gameT::_mov()
{   
    pointT nextP(snake.front());
    pointT tmpP = nextP;
loopWalk:
    tmpP.walk(dx, dy);
    // ilegal
    if (!legal(tmpP))
    {   
        auto [_dx, _dy] = nextDirect(tmpP.row, tmpP.col);
        setDirect(_dx, _dy);
        goto loopWalk;
    } 
    // ate $
    else 
    {
        nextP = tmpP;
        snake.push_front(nextP);
        if(food(nextP))
        {   
            numEaten ++;
        } else
        {   
            snake.pop_back();
        }
    }
    // 
    return SnakeInBound();
}

void gameT::mapl()
{

}

void gameT::SyncSnake()
{
    for(auto &p : snake)
    {
        world[p.row][p.col] = kSnakeTile;
    }
}

void gameT::aipl()
{   
    if (!SnakeInBound())
        return;

    _mov();
    SyncSnake();
    GamePause(500000);
}

void gameT::disp()
{   
    GameClearConsole();
    for( auto &s : world)
    {
        cout << s << endl;
    }
}

void gameT::resp()
{
    cout << "You ate " << numEaten << " pieces of food" << endl;
    if (numEaten == kMaxFood)
    {
        cout << "Game Wins" << endl;
    } else 
    {
        cout << "Game Over" << endl;
    }
}

void gameT::paus()
{
    GamePause(10000000);
}

void gameT::simu()
{   
    while(numEaten < kMaxFood)
    {
        disp();
        aipl();
        if (!_mov())
            break;
        paus();
    }
    resp();
}


void pointT::walk(int _dx, int _dy)
{
    row += _dx;
    col += _dy;
}

void pointT::operator= (pointT &_p)
{
    row = _p.row;
    col = _p.col;
}