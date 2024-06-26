#pragma once
#ifndef _TEST_FUNC_3_HPP
#define _TEST_FUNC_3_HPP

#include "_i_lib_.hpp"
#include "_stl_lib_.hpp"

__DEF_NS__(Alan::Inst::LC)

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* );

void TestLC234();
void TestLC328();
void TestLC142();
void TestLC143();
void TestLC96();
void TestLC95();
int numTrees(int );
void TestLC222();
void TestLC5();
void TestLC264();
void TestLC39();
void TestLC902();

typedef void (*TestLCFn) ();

void TestRunLC();

__END_NS__


__DEF_NS__(Alan::Demos::Test::Func)

void TestConsoleIOStackQueue();
void TestBuiltinFns();

__END_NS__

#endif