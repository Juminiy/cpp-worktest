#include "../../include/_stl_lib_.hpp"

#include "../../include/_keno_game_.hpp"
#include "../../include/_stream_.hpp"

#include <iterator>
#include <iostream>

__USE_NS__(Alan::Demos);

void TestFMRadio()
{
    PRINTLN("FMRadio");
}

void KenoGame::AddNumber(int const &_val){
    this->user_guessed.insert(_val);
}

size_t KenoGame::NumChosen(){
    return this->user_guessed.size();
}

size_t KenoGame::NumMaxChs(){
    return this->user_max_chs;
}

size_t KenoGame::NumWinner(std::vector<int > const &_chsd){
    size_t _cnt = 0;
    for (auto &_val : _chsd)
        if(Alan::AssoFind<>(this->user_guessed, _val))
            ++ _cnt;
    return _cnt;
}

// need console input 
void TestKenoGame()
{
    auto _kgame = 
        KenoGame();
    _COLOR_START(_COLOR_RED);
        PRINT("current game, you can choose up to ");
        PRINT(std::to_string(_kgame.NumMaxChs()));
        PRINTLN(" numbers");
    _COLOR_RECOVER;

    auto _it = 
        std::istream_iterator<int >(std::cin);
    while(_kgame.NumChosen() <
            _kgame.NumMaxChs()-1)
    {
        if (I32_IN_RANGE(*_it, KenoRange1, KenoRange2))
            _kgame.AddNumber(*_it);
        else{
            _COLOR_START(_COLOR_RED);
                OUTPUTLN(std::cerr, "illegal number repeat");
            _COLOR_RECOVER;
        }
        _it++;
    }

    auto _vi = 
        std::vector<int >();
    Alan::_Seq_Con_Ins_Gen_Num<>(_vi, KenoCountMax,
                            KenoRange1, KenoRange2);

    Alan::ConsoleIterOutput<int >(_vi);

    std::cout << "same count < " 
                << _kgame.NumWinner(_vi)
                << " >" << __LN__;
    PRINTLN("game over");
}