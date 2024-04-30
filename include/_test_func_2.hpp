#pragma once
#ifndef _TEST_FUNC_2_HPP
#define _TEST_FUNC_2_HPP

#include "_i_lib_.hpp"
#include "_stl_lib_.hpp"

#include "_self_list_.hpp"

__DEF_NS__(Alan::Demos::Test::Func)

typedef void (*TestFuncDeclType) ();

__VAR_GLB__
std::deque<TestFuncDeclType> __test_fn_queue_;

GEN_FUNC_COPY
void __init_test_fn_()
{
    __test_fn_queue_.shrink_to_fit();
}

void TestNoArgs();

void TestVaArgs();

#define PUSH_TASK(__fn_) __test_fn_queue_.push_back(__fn_)
#define POP_TASK() __test_fn_queue_.pop_back()
#define POP_TASKN(__n_) \
        while(__n_ -- && !__test_fn_queue_.empty()) { \
            POP_TASK() \
        }
#define RUN_TASKS() \
        while(!__test_fn_queue_.empty()) \
        { \
        __test_fn_queue_.front()(); \
        __test_fn_queue_.pop_front(); \
        }

__END_NS__

__DEF_NS__(Alan::Demos::Test::Func)

void TestPaSort();

__END_NS__

#endif