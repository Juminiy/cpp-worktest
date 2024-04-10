#include "../../include/_i_lib_.hpp"
#include "../../include/_stl_lib_.hpp"

#include "../../include/_dfa_.hpp"
#include "../../include/_stream_.hpp"



#include <cassert>
#include <cctype>
#include <cstdlib>

#include <string>

#include <iostream>
#include <iomanip>
#include <fstream>

#include <map>
#include <unordered_map>

#include <set>
#include <unordered_set>

#include <utility>
#include <iterator>
#include <algorithm>
#include <functional>

__USE_NS__(Alan::Demos);

DFA::DFA()
{

}

bool Alan::Demos::is_num_state(const std::string &_state)
{
    return find_if_not(_state.cbegin(),
                        _state.cend(),
                        [](const char &_ch) -> bool{
                            return isdigit(_ch);
                        }) 
            == _state.cend();
}

bool is_email_trans(const std::string & _transition)
{
    auto _is_tran = [](const char &_ch) 
                        -> bool {
        return _ch == 'a' ||
                _ch == '.' ||
                _ch == '@' ||
                _ch == '*';
    };
    return  (_transition.size() == 1 &&
                _is_tran(_transition[0]));   
}

bool is_email_state(const std::string & _state)
{
    return Alan::Demos::is_num_state(_state);
}

DFA::DFA(const std::string &_file_name)
{
    ASSERT_FILE(PatFilePath(_file_name));

    is_state = is_email_state;
    is_trans = is_email_trans;

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
                else if (is_trans(nextToken))
                {
                    trans_set.push_back(nextToken[0]);
                    trans_Const_Cnt =  
                        ++ trans_Current_Cnt;
                } else if (is_state(nextToken))
                {   
                    trans_Current_Cnt = 
                        (trans_Current_Cnt+1) % 
                        (trans_Const_Cnt+1);

                    int cur_state_i32 = 
                        atoi(nextToken.c_str());
                    if (!trans_Current_Cnt)
                    {
                        state_Arrow = cur_state_i32;
                    } else {
                        if (state_Arrow != -1 &&
                            trans_Current_Cnt &&
                            cur_state_i32 != -1)
                        {   
                            trans[std::make_pair(state_Arrow, 
                                            trans_set[trans_Current_Cnt-1])]
                                = cur_state_i32;
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

bool DFA::simu(std::string const & _input) 
{
    int _state = start;
    for(auto &_is : _input)
    {
        _state = trans[std::make_pair(_state, _is)];
    }
    return Alan::AssoFind<>(accps, _state);
}

// Test Pass
bool ValidateEmail(std::string const & _email)
{
    std::string _email_dup(_email);
    DFA _email_dfa = DFA("_email_dfa.txt");
    for(auto _it = _email_dup.begin();
            _it != _email_dup.cend();
            ++_it)
    {
        if(isalnum(*_it))
            *_it = 'a';
        else if(*_it != '.' &&
                *_it != '@')
            return false;
    }
    return _email_dfa.simu(_email_dup);
}

// example:
// optarg <_Tp = std::string > = lanasula.ss@loq.euc
void TestEmail()
{   
    _COLOR_START(_COLOR_CYAN);
    std:: cout << std::boolalpha 
                << ValidateEmail(std::string(optarg)) 
                << __LN__;
    _COLOR_RECOVER;
}

