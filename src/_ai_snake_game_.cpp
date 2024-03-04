#include "_ai_snake_game_.hpp"
#include "_stream_.hpp"


#include <fstream>
#include <algorithm>
#include <iostream>
#include <iterator>

#include <cassert>
#include <ctime>

void gameT::load(fstream &fileInput)
{
    fileInput >> numRows >> numsCols;
    world.resize(numRows);
    fileInput >> dx >> dy;
    for(int row = 0, col = 0; row < numRows; row++)
    {
        getline(fileInput, world[row]);
        if ((col = world[row].find(kSnakeTile)) != string::npos)
        {
            snake.push_back(pointT{row, col});
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
    pointT snake_head = snake.front();
    return snake_head.row >= 0 && 
            snake_head.row < numRows &&
            snake_head.col >= 0 && 
            snake_head.col < numsCols;
}

bool gameT::_mov()
{
    return true;
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
    while(SnakeInBound())
    {
        pointT snake_head = snake.front();
        snake.push_front(pointT{snake_head.row-1, snake_head.col});
        SyncSnake();
        GamePause(500000);
    }
}

void gameT::disp()
{   
    #if defined(__APPLE__) || defined(__MACH__) || defined(__MACOS__)
    #include <unistd.h>
    system("clear");
    #elif defined(_WIN64) || defined(WIN64) || \
        defined(_WIN32) || defined(WIN32) 
    #include <windows.h>
    system("CLS");
    #endif 

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
    GamePause(125000);
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