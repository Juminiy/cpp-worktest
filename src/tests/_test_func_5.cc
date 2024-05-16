#include "../../include/_i_lib_.hpp"
#include "../../include/_stl_lib_.hpp"

#include "../../include/_test_func_2.hpp"
#include "../../include/_test_func_3.hpp"
#include "../../include/_test_func_4.hpp"
#include "../../include/_self_list_.hpp"
#include "../../include/_self_algo_.hpp"

__DEF_NS__(Alan::Demos::Test::Func)

void TestNoArgs()
{
    // PUT_TASK("kOfN", Alan::SelfAlgo::Inst::TestKOfN); 
    // PUT_TASK("xxx", Alan::SelfAlgo::Inst::TestXXX); 
    // PUT_TASK("eq", Alan::SelfAlgo::Inst::TestEightQueens); 
    // PUT_TASK("dl", Alan::SelfAlgo::Copy::TestDL);
    PUT_TASK("lc5", Alan::Inst::LC::TestLC5);
    PUT_TASK("lc264", Alan::Inst::LC::TestLC264);
    PUT_TASK("expr", Alan::SelfAlgo::Inst::TestExpr);

    CAL_TASK("expr");
}

void TestVaArgs()
{
    
}

void TestLCRace357()
{
    PUT_TASK("p1", Alan::Inst::LC::Race::TestProblem1);
    PUT_TASK("p2", Alan::Inst::LC::Race::TestProblem2);
    PUT_TASK("p3", Alan::Inst::LC::Race::TestProblem3);
    PUT_TASK("p4", Alan::Inst::LC::Race::TestProblem4);
    PUT_TASK("p5", Alan::Inst::LC::Race::TestProblem5);

    CAL_TASK("p2");
}

void TestNoArgsV1()
{
    PUT_TASK("lc72", Alan::SelfAlgo::Inst::Test::TestLC72);
    PUT_TASK("lc150", Alan::LC::TestLC150);
    PUT_TASK("rpn_opt_less", Alan::SelfAlgo::Inst::Test::TestCOptLess);
    PUT_TASK("rpn_int_token", Alan::SelfAlgo::Inst::Test::TestIntToken);
    PUT_TASK("rpn", Alan::SelfAlgo::Inst::Test::TestMidExpr2RPN);
    PUT_TASK("stkio", Alan::Demos::Test::Func::TestConsoleIOStackQueue);
    PUT_TASK("lc234", Alan::Inst::LC::TestLC234);
    PUT_TASK("lc328", Alan::Inst::LC::TestLC328);
    PUT_TASK("lc142", Alan::Inst::LC::TestLC142);
    PUT_TASK("lc143", Alan::Inst::LC::TestLC143);
    PUT_TASK("runcpu", Alan::Demos::Test::Func::TestRunCPU);
    PUT_TASK("treebase", Alan::SelfList::Inst::TestTreeNodeBase);
    PUT_TASK("treebuild", Alan::SelfList::Inst::TestTreeNodeBuild);
    PUT_TASK("lc96", Alan::Inst::LC::TestLC96);
    PUT_TASK("lc95", Alan::Inst::LC::TestLC95);
    PUT_TASK("lc222", Alan::Inst::LC::TestLC222);
    PUT_TASK("bitset", Alan::Demos::Test::Func::TestBitMani);
    PUT_TASK("lc116", Alan::SelfList::Inst::LikeOf::TestLC116); 
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