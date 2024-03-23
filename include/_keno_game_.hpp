#pragma once
#ifndef _FM_RADIO_HPP
#define _FM_RADIO_HPP

#include "_i_lib_.hpp"
#include "_rand_lib_.hpp"


#include <vector>
#include <set>

void TestFMRadio();

#define KenoCount1 4
#define KenoCount2 8
#define KenoCountMax 20
#define KenoRange1 0
#define KenoRange2 80

class KenoGame
{
public:
    explicit KenoGame() noexcept{
        this->user_max_chs = 
            Alan::_Gen_Num<size_t >(KenoCount1, KenoCount2);
    }

    void   AddNumber(int const &);
    size_t NumChosen();
    size_t NumMaxChs();
    size_t NumWinner(std::vector<int > const &);

private:
    std::set<int > user_guessed;
    size_t         user_max_chs;
};

void TestKenoGame();

#endif 