#pragma once
#ifndef _NFA_HPP
#define _NFA_HPP

#include "_i_lib_.hpp"

#include <set>
#include <map>
#include <utility>

class NFA
{
public:
    typedef std::multimap<std::pair<int, char >, int >  trans_type;
    typedef trans_type::iterator                        trans_it; 
    typedef const trans_it                              trans_const_it;
    typedef std::pair< trans_it, trans_it >             trans_it_rg;
    typedef std::pair< trans_const_it, trans_const_it > trans_const_it_rg;
    
    trans_type                                  trans;
    std::vector<char>                           trans_set;

    std::set<int>                               accps;

    int                                         start;

    explicit NFA();
    explicit NFA(const std::string &);
    bool simu(std::string const &);
    bool (*is_trans) (const std::string &);
    bool (*is_state) (const std::string &);

};

void TestNFA();

#endif 