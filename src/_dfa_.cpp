#include "_i_lib_.hpp"
#include "_dfa_.hpp"

#include <string>

#include <map>
#include <unordered_map>

#include <set>
#include <unordered_set>

#include <utility>
#include <functional>


bool DFA::simu(std::string const & _input)
{
    int _state = start;
    for(auto &_is : _input)
    {
        _state = trans[std::make_pair(_state, _is)];
    }
    return accps.find(_state) !=
            accps.cend();
}