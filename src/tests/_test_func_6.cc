#include "../../include/_i_lib_.hpp"
#include "../../include/_stl_lib_.hpp"

#include "../../include/_test_func_3.hpp"

#include <queue>
#include <string>
#include <stack>

__DEF_NS__(Alan::Demos::Test::Func)

void TestConsoleIOStackQueue()
{
    auto _q1 = std::queue<int>();
    for(int i = 0; i < 10; i++)
        _q1.push(i);
    Alan::ConsoleOutputQueue(_q1);

    auto _s1 = std::stack<int>();
    for(int i = 0; i < 10; i++)
        _s1.push(i);
    Alan::ConsoleOutputStack(_s1);
}

__END_NS__