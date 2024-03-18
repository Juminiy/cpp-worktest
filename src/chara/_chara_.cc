#include <string>
#include <chrono>
#include <ctime>
#include <memory>
#include <iostream>

using namespace std::literals;

void TestLiterals()
{
    auto ss = "ri"s;
    auto oneDay = 24h;
    auto s_ptr = std::make_unique<std::string >(ss);

    std::cout << *s_ptr << std::endl;
}

