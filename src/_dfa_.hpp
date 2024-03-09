#pragma once 
#ifndef _DFA_HPP
#define _DFA_HPP

#include <string>

#include <map>
#include <unordered_map>

#include <set>
#include <unordered_set>

#include <utility>
#include <functional>


class DFA 
{
public:
    
    std::map<std::pair<int, char>, int> trans;
    // std::set<char>                      trans_set;
    std::vector<char>                   trans_set;

    std::set<int>                       accps;

    int                                 start;
    
    explicit DFA();
    explicit DFA(const std::string &);
    bool simu(std::string const &);
    
};

bool ValidateEmail(std::string const &);

void TestEmail();

#endif 