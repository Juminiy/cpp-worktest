#include "../../include/_i_lib_.hpp"
#include "../../include/_stl_lib_.hpp"

#include "../../include/_self_algo_.hpp"

#include <vector>
#include <string>
#include <stack>

#include <cctype>

__DEF_NS__(Alan::SelfAlgo::Inst)

__VAR_GLB__
std::map<std::string, int>
__priority_c;

using ss_pair = std::pair<std::string, std::string>;

// num less, priority greater
void __init_priority_c()
{
    __priority_c["#"] = 1<<31,

    __priority_c[","] =  1<<15,

    __priority_c["|="] = 1<<14, 
    __priority_c["^="] = 1<<14, 
    __priority_c["&="] = 1<<14, 
    __priority_c[">>="] = 1<<14, 
    __priority_c["<<="] = 1<<14, 
    __priority_c["-="] = 1<<14, 
    __priority_c["+="] = 1<<14, 
    __priority_c["%="] = 1<<14, 
    __priority_c["*="] = 1<<14, 
    __priority_c["/="] = 1<<14, 
    __priority_c["="] = 1<<14, 

    __priority_c["?:"] = 1<<13,

    __priority_c["||"] = 1<<12,

    __priority_c["&&"] = 1<<11,
    
    __priority_c["|"] = 1<<10, 
    
    __priority_c["^"] = 1<<9, 
    
    __priority_c["&"] = 1<<8, // bitAnd

    __priority_c["=="] = 1<<7, 
    __priority_c["!="] = 1<<7, 

    __priority_c["<="] = 1<<6, 
    __priority_c["<"] = 1<<6,
    __priority_c[">="] = 1<<6, 
    __priority_c[">"] = 1<<6, 

    __priority_c[">>"] = 1<<5, 
    __priority_c["<<"] = 1<<5,

    __priority_c["-"] = 1<<4, 
    __priority_c["+"] = 1<<4,

    __priority_c["%"] = 1<<3, 
    __priority_c["*"] = 1<<3, 
    __priority_c["/"] = 1<<3, 

    __priority_c["sizeof"] = 1<<2, 
    __priority_c["~"] = 1<<2, 
    __priority_c["!"] = 1<<2,
    __priority_c["&"] = 1<<2, // getAddress
    __priority_c["*"] = 1<<2, // deAddress/getValue
    __priority_c["--"] = 1<<2, // preVal -> --val
    __priority_c["--"] = 1<<2, //postVal -> val--
    __priority_c["++"] = 1<<2, // preVal -> ++val
    __priority_c["++"] = 1<<2, //postVal -> val++
    __priority_c["(T)"] = 1<<2, // (T)typecast
    __priority_c["-"] = 1<<2, // unary

    __priority_c["."] = 1<<1,
    __priority_c["->"] = 1<<1, 
    __priority_c["()"] = 1<<1, 
    __priority_c["[]"] = 1<<1;

    __priority_c["$"] = 1<<0;
}

bool __c_opt_greater
(const std::string & _opt1, bool _opt1_in_stack,
const std::string & _opt2, bool _opt2_in_stack)
{
    return __priority_c[_opt1] < 
            __priority_c[_opt2];
}

bool __c_opt_less
(const std::string & _opt1, bool _opt1_in_stack,
const std::string & _opt2, bool _opt2_in_stack)
{
    return __priority_c[_opt1] > 
            __priority_c[_opt2];
}

// 1. +, - ; other: error 
// 2. decimal, hex, oct, bin
//  (1). dec
//  (2). hex: 0x
//  (3). oct: 0
//  (4). bin: 0b
// 3. boundary, bits
// 4. ignore invalid and illegal
bool __is_int_(const std::string & __number_)
{
    // int dec11 = 11; -11
    // int hex11 = 0x11; 0X11 -0x11
    // int oct11 = 011; -011
    // int bin11 = 0b11; 0B11 -0b11
    auto __isbdigit = [](int __ch) -> int { return __ch == '0' || __ch == '1'; };
    auto __isodigit = [] (int __ch) -> int { return __ch >= '0' && __ch <= '7'; };
    #define __reach_end_() \
            if(__num_it_ == __num_end_) return false

    typedef int (*__pred) (int);
    __pred __pred_fn;

    auto __num_it_ = __number_.begin();
    auto __num_end_ = __number_.end();
    if(*__num_it_ == '-' || *__num_it_ == '+')
        ++__num_it_; __reach_end_();

    if(*__num_it_ == '0')
    {
        ++__num_it_; __reach_end_();
        if(*__num_it_ == 'x' || *__num_it_ == 'X')
        {   
        ++__num_it_; __reach_end_();
        __pred_fn = ::isxdigit;
        } else if (*__num_it_ == 'b' || *__num_it_ == 'B')
        {
        ++__num_it_; __reach_end_();
        __pred_fn = __isbdigit;
        } else if (__isodigit(*__num_it_))
        {
        __pred_fn = __isodigit;
        } else 
        {
        return false;
        }
    } else 
    {
        __pred_fn = ::isdigit;
    }

    return __num_it_ != __num_end_ && 
        std::all_of(__num_it_, __num_end_, __pred_fn);
}

// 1. float, double .
// 2. exp
bool __is_float_(const std::string & __number_)
{
return false;
}

bool __is_c_opt_(const std::string & __operator_)
{
    return __priority_c.find(__operator_) !=
            __priority_c.end();
}

// middlefix expression to reverse pollish notation
// C version
// do not deal with illegal 
void __midexpr_2_rpn
(const std::vector<std::string> & mTokens, 
std::vector<std::string> &rpnTokens)
{
    __init_priority_c();
    std::stack<std::string> __tmp_op; // tmp opt
    std::stack<std::string> __dest_op; // opt and opd

    __tmp_op.push("#");
    for(auto token : mTokens)
    {
        if(__is_int_(token))
            __dest_op.push(token);
        else if (__is_c_opt_(token))
        {// TODO: unfinished
            // if (__c_opt_greater(token, __tmp_op.top()))
            // {
            //     __tmp_op.push(token);
            // } else 
            // {
            //     while(!__tmp_op.empty() && 
            //         __c_opt_greater(__tmp_op.top(), token))
            //     {

            //     }
            // }
        } 
        else if (token == "(")
            __tmp_op.push("(");
        else if (token == ")")
        {
            while(!__tmp_op.empty() && __tmp_op.top()!= "(")
            {
                __dest_op.push(__tmp_op.top());
                __tmp_op.pop();
            }
            if(!__tmp_op.empty() && __tmp_op.top() == "(")
                __tmp_op.pop();
        }
        else // error
        {
            ERRLN("mTokens is illegal");
            std::terminate();
        }
    }

}

void __rpn_2_midexpr
(const std::vector<std::string> & rpnTokens,
std::vector<std::string> &mTokens)
{

}

__END_NS__

__DEF_NS__(Alan::LC)

int evalRPN(std::vector<std::string>& tokens) {
    std::stack<int> opd; // -200 ~ 200
    // std::stack<char> opt; // + - * /
    // int eval = 0;
    auto optOpd = [](int lexpr, int rexpr, char opt) -> int {
        switch (opt)
        {
        case '+':
            return lexpr+rexpr;
        case '-':
            return lexpr-rexpr;
        case '*':
            return lexpr*rexpr;
        case '/':
            return lexpr/rexpr;        
        default:
            return 0;
        }
    };
    for(auto str : tokens)
    {
        if(str == "+" || 
            str == "-" ||
            str == "*" || 
            str == "/")
        {
            auto rexpr = opd.top(); opd.pop();
            auto lexpr = opd.top(); opd.pop();
            opd.push(optOpd(lexpr, rexpr, str[0]));
        }
        else 
        {
            opd.push(std::strtol(str.c_str(), nullptr, 10));
        }
    }
    // while(!opt.empty())
    // {

    // }

    return opd.top();
}

void TestLC150()
{
    auto strv1 = std::vector<std::string>{"2","1","+","3","*"};
    PRINTLN_DETAIL(evalRPN(strv1));

    auto strv2 = std::vector<std::string>{"4","13","5","/","+"};
    PRINTLN_DETAIL(evalRPN(strv2));

    auto strv3 = std::vector<std::string>{"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    PRINTLN_DETAIL(evalRPN(strv3));
}

__END_NS__