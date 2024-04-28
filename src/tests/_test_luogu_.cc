#include "../../include/_i_lib_.hpp"
#include "../../include/_stl_io_.hpp"
#include "../../include/_i_sort_.hpp"
#include "../../include/_test_func_.hpp"

#include <iostream>
#include <vector>

__DEF_NS__(Alan::Demos::Test::Luogu)

// input
void Alan_Driver()
{   
    size_t _n;
    std::cin >> _n;
    auto i32v = std::vector<int>();
    i32v.reserve(_n);
    Alan::SeqIterInput(i32v, std::cin); // *nix Ctrl+D; Windows Ctrl+Z
    Alan::Sort::MergeSort(i32v);
    Alan::IterOutput(i32v, std::cout, " ");
    
}

__END_NS__