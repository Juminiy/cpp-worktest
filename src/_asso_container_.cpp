#include "_i_lib_.hpp"
#include "_asso_container_.hpp"


#include <string>
#include <iostream>

#include <queue>
#include <vector>
#include <functional>
#include <map>
#include <unordered_map>

typedef pair<int, string> i32_str;

void TestUMap()
{   
    priority_queue<int, vector<int>, greater<int>> bh;
    bh.push(1);
    // cout << bh.size() << endl;
    unordered_map<int,string > umis ;
    umis.insert(i32_str(1, "w"));
    map<int, string> mis;
    mis.insert(i32_str(1, "s"));
    multimap<int, string> mm;
    mm.insert(i32_str(1, "ss"));
    mm.insert(i32_str(1, "bb"));
    mm.insert(i32_str(1, "ss"));
    mm.insert(i32_str(1, "kk"));
    for(auto &_e_ : mm)
        cout << "[" << _e_.first << ", " << _e_.second << "]" << endl;
}