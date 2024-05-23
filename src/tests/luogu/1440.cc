#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
#include <string>

// 
using ll = long long;
typedef int (*sfn) (int, int);
int _sum(int a, int b){ return a+b; }
int _max(int a, int b){ return std::max(a, b); }
int _min(int a, int b){ return std::min(a, b); }

using bfn = std::function<int(int, int)>;

std::vector<int> lexicalOrder(int n) {
    
}

std::vector<int> lp(int n)
{
    auto vi = std::vector<int>(n);
    int i =0;
    std::generate(vi.begin(), vi.end(), [&i](){ ++i; return i; });
    std::sort(vi.begin(), vi.end(), [](int a, int b) -> bool { return std::to_string(a) < std::to_string(b); });
    return vi;
}

int main()
{   
    {
        auto vi = lexicalOrder(111);
        for(auto i:vi)
            std::cout << i << ", ";
    }

    {
        auto vi = lp(125);
        for(auto i:vi)
            std::cout << i << ", ";
    }

    return 0;
}