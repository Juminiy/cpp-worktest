#include "_nfa_.hpp"
#include "_i_lib_.hpp"
#include "_stream_.hpp"
#include "_dfa_.hpp"
#include "_stl_lib_.hpp"

#include <cstdlib>
#include <cstring>
#include <cassert>

#include <fstream>
#include <iostream>

#include <functional>
#include <algorithm>
#include <iterator>
#include <set>
#include <map>
#include <vector>
#include <utility>

NFA::NFA()
{

}

bool is_nfa_trans(const std::string &_transition)
{
    auto _is_tran = [](const char &_ch) -> bool {
        return _ch == '0' ||
                _ch == '1' ||
                _ch == '*';
    };
    return _transition.size() == 1 &&
            _is_tran(_transition[0]);
}

bool is_nfa_state(const std::string &_state)
{
    return find_if_not(_state.cbegin(),
                        _state.cend(),
                        [](const char &_ch)->bool{
                            return isdigit(_ch) ||
                                    _ch == '/' ||
                                    _ch == '-';
                        }) 
            == _state.cend();
}

// 0/1/2/3
std::vector<int> break_up_states(const std::string &_states)
{
    int cur_state = 0;
    std::vector<int> states_vi;
    for(auto &_ch : _states)
    {
        if(isdigit(_ch))
        {
            I32_CHARIN(cur_state, _ch);
        } else if (_ch == '/')
        {
            states_vi.push_back(cur_state);
            cur_state = 0;
        } else 
        {   
            std:: cerr << "end up states is INVALID " 
                        << "_states< " 
                        << _RED(_states)   
                        << " >" 
                        << endl;
            exit(INPUT_ERROR);
        }
    }
    if (cur_state)
        states_vi.push_back(cur_state);
    return states_vi;
}

// Test Pass
NFA::NFA(const std::string &_file_name)
{
    ASSERT_FILE(PatFilePath(_file_name));

    is_trans = is_nfa_trans;
    is_state = is_nfa_state;

    auto is_invalid_state = [](const std::string &_state){
        return !_state.compare("-1");
    };
    auto is_trans_end = [](const std::string &_tran){
        return !_tran.compare("*");
    };
    bool trans_end = false;

    #define BREAK_WHEN_SHARP \
            if (!nextToken.compare("#"))    \
                    break;  
                    
    std::string nextToken;
    while(*inputFile >> nextToken)
    {
        if (!nextToken.compare("trans"))
        {
            int state_Arrow       = -1;
            int trans_Const_Cnt UNUSED  =  0;
            int trans_Current_Cnt =  0;

            while(*inputFile >> nextToken)
            {
                BREAK_WHEN_SHARP
                else if (!trans_end && is_trans(nextToken))
                {   
                    trans_set.push_back(nextToken[0]);
                    trans_Const_Cnt =  
                        ++ trans_Current_Cnt;
                    if (is_trans_end(nextToken))
                        trans_end = true;
                } else if (is_state(nextToken))
                {   
                    trans_Current_Cnt = 
                        (trans_Current_Cnt+1) % 
                        (trans_Const_Cnt+1);
                        
                    if (!trans_Current_Cnt)
                    {
                        state_Arrow = atoi(nextToken.c_str());
                    }
                    else {
                        if (is_invalid_state(nextToken));
                        else if (state_Arrow != -1 &&
                                    trans_Current_Cnt)
                        { 
                            auto _states_vi = break_up_states(nextToken);
                            for ( auto &_state : _states_vi)
                                if (_state != -1 &&
                                    trans_set[trans_Current_Cnt-1] != '*')
                                    trans.insert(std::make_pair(
                                                std::make_pair(state_Arrow, 
                                                                trans_set[trans_Current_Cnt-1]),
                                                _state));
                        } 
                    }
                }
            }
        } else if (!nextToken.compare("accps"))
        {
            while(*inputFile >> nextToken)
            {   
                BREAK_WHEN_SHARP
                else if(is_state(nextToken))
                    accps.insert(atoi(nextToken.c_str()));
            }
        } else if (!nextToken.compare("start"))
        {
            while(*inputFile >> nextToken)
            {
                BREAK_WHEN_SHARP
                else if(is_state(nextToken))
                    start = atoi(nextToken.c_str());
            }
        } 
    }
}

// Test Pass
bool NFA::simu(const std::string &_input)
{
    std::set<int > _states;
    _states.insert(start);
    // 0011
    for(auto &_is : _input)
    {
        std::set<int > _next_states;
        // 0
        for(auto &_state : _states)
        {
            trans_const_it_rg tran_it_rg = 
                trans.equal_range(std::make_pair(_state, _is));
            if (tran_it_rg.first != trans.cend())
            {   
                for(trans_it _it_rg = tran_it_rg.first;
                            _it_rg != tran_it_rg.second;
                            ++ _it_rg)
                    _next_states.insert(_it_rg->second);
            }
        }
        _states = _next_states;
    }

    for(auto _state : _states)
        if(AssoFind<>(accps, _state))
            return true;
    return false; 
}

void TestNFA()
{
    PSEUDORANDOM_DECL;
    auto _gen_01_bits = [](const int &_bits) 
                            -> std::string{
        std::string _s;
        _s.reserve(_bits);
        for(int _i = 0;
                _i < _bits;
                ++ _i)
            _s += (rand() % 2) ? "1" : "0";
        return _s;
    };
    auto _nfa = NFA("_nfa_.txt");
    std::map<std::string, bool> res_map;
    for(unsigned int _tm = 0;
            _tm < opt_uint(optarg);
            ++ _tm)
    {
        auto _gen_bits = _gen_01_bits((rand()% (1<<8)) + 2);
        res_map.insert(std::make_pair(
                        _gen_bits.substr(_gen_bits.size()-2, 2), 
                        _nfa.simu(_gen_bits)));
    }

    for( auto &_it : res_map)
        std::cout << _RED(_it.first)
                    << " = " 
                    << boolalpha 
                    << _it.second << std::endl;
}