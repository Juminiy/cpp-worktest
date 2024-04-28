#include "../../include/_i_lib_.hpp"
#include "../../include/_stl_lib_.hpp"

#include "../../include/_test_func_2.hpp"

__DEF_NS__(Alan::Demos::Test::Func)

void TestNoArgs()
{
    PUSH_TASK(__init_test_fn_);
    PUSH_TASK(TestPaSort);
    RUN_TASKS();
}

void TestVaArgs()
{
    
}

__END_NS__