#include "../../include/_i_lib_.hpp"
#include "../../include/_stl_lib_.hpp"

#include "../../include/_test_func_2.hpp"
#include "../../include/_self_list_.hpp"

__DEF_NS__(Alan::Demos::Test::Func)

void TestNoArgs()
{
    PUSH_TASK(__init_test_fn_);
    PUSH_TASK(TestPaSort);  POP_TASK();
    PUSH_TASK(Alan::SysInfo::LOGSysInfo); POP_TASK();
    PUSH_TASK(Alan::SelfList::Inst::Test::TestLC23); POP_TASK();
    PUSH_TASK(Alan::SelfList::Inst::Test::TestLC1143); POP_TASK();
    PUSH_TASK(Alan::SelfList::Inst::Test::TestLC2); POP_TASK();
    PUSH_TASK(Alan::SelfList::Inst::Test::TestLC19); POP_TASK();
    PUSH_TASK(Alan::SelfList::Inst::Test::TestLC206); POP_TASK();
    PUSH_TASK(Alan::SelfList::Inst::Test::TestSwapLN); POP_TASK();
    PUSH_TASK(Alan::SelfList::Inst::Test::TestLC24); 
    
    RUN_TASKS();
}

void TestVaArgs()
{
    
}

__END_NS__