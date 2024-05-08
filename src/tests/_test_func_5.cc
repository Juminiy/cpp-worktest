#include "../../include/_i_lib_.hpp"
#include "../../include/_stl_lib_.hpp"

#include "../../include/_test_func_2.hpp"
#include "../../include/_test_func_3.hpp"
#include "../../include/_self_list_.hpp"
#include "../../include/_self_algo_.hpp"

__DEF_NS__(Alan::Demos::Test::Func)

void TestNoArgs()
{
    PUT_TASK("lc72", Alan::SelfAlgo::Inst::Test::TestLC72);
    PUT_TASK("lc150", Alan::LC::TestLC150);
    PUT_TASK("rpn_opt_less", Alan::SelfAlgo::Inst::Test::TestCOptLess);
    PUT_TASK("rpn_int_token", Alan::SelfAlgo::Inst::Test::TestIntToken);
    PUT_TASK("rpn", Alan::SelfAlgo::Inst::Test::TestMidExpr2RPN);
    PUT_TASK("stkio", Alan::Demos::Test::Func::TestConsoleIOStackQueue);
    PUT_TASK("lc234", Alan::Inst::LC::TestLC234);
    PUT_TASK("lc328", Alan::Inst::LC::TestLC328);
    
    CAL_TASK("lc328");
}

void TestVaArgs()
{
    
}

void TestNoArgsV0()
{
    PUSH_TASK(__init_test_fn_);
    PUSH_TASK(TestPaSort);  POP_TASK();
    PUSH_TASK(Alan::SysInfo::LOGSysInfo); POP_TASK();
    PUSH_TASK(Alan::SelfList::Inst::Test::TestLC23); POP_TASK();
    PUSH_TASK(Alan::SelfList::Inst::Test::TestLC1143); POP_TASK();
    PUSH_TASK(Alan::SelfList::Inst::Test::TestLC2); POP_TASK();
    PUSH_TASK(Alan::SelfList::Inst::Test::TestLC19); POP_TASK();
    PUSH_TASK(Alan::SelfList::Inst::Test::TestLC206); POP_TASK();
    PUSH_TASK(Alan::SelfList::Inst::Test::TestLC24); POP_TASK();
    PUSH_TASK(Alan::SelfList::Test::TestPostOrderTravV3); 
    PUSH_TASK(Alan::SelfList::Test::TestPostOrderTravV2);
    PUSH_TASK(Alan::SelfList::Test::TestPostOrderTrav); POP_TASKS(3);
    PUSH_TASK(Alan::SelfList::Inst::Test::TestLC25); POP_TASK(); 
    PUSH_TASK(Alan::SelfList::Inst::Test::TestLC61); POP_TASK();
    PUSH_TASK(Alan::SelfList::Inst::Test::TestLC83); POP_TASK();
    PUSH_TASK(Alan::SelfList::Inst::Test::TestLC82); POP_TASK();
    PUSH_TASK(Alan::SelfList::Inst::Test::TestLC86); POP_TASK();
    PUSH_TASK(Alan::SelfList::Inst::Test::TestLC92); POP_TASK();
    PUSH_TASK(Alan::SelfList::Inst::Test::TestSwapLN); POP_TASK();
    PUSH_TASK(Alan::Inst::LC::TestRunLC); POP_TASK();
    PUSH_TASK(Alan::SelfAlgo::Inst::Test::TestLC72); POP_TASK();
    PUSH_TASK(Alan::SelfAlgo::Inst::p1257); POP_TASK();
    RUN_TASKS();
}

__END_NS__