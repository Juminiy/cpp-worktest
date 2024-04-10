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

__DEF_NS__(Alan)

__DEF_NS__(Demos)

class AutoMata
{
public:
    virtual bool 
    simu(const std::string &) const = 0;
};

bool is_num_state(const std::string &);

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
    bool (*is_trans) (const std::string &);
    bool (*is_state) (const std::string &);

};

__END_NS__

__END_NS__

bool ValidateEmail(std::string const &);
void TestEmail();



#endif 