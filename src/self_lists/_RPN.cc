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

typedef bool (*__token_fn_) (const std::string &);
typedef int (*__char_fn_) (int );

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

// reference: 
// num much, prio much
/*
 in_stack ( | ) | *,/ | +,-
 true:    1 | 6 |  5  |  3
 false:   6 | 1 |  4  |  2
*/

// 1. deal with ( and ) seperated
// 2. whether in stack or not, different piro operator *,/ > +,-, others conform rules
// 3. same prio operator, in_stack > out_stack


/// @brief is _opt1 < _opt2 
/// @param _opt1 must in_stack
/// @param _opt2 must out_stack
/// @param _opt2_in_stack 
/// @return 
bool __c_opt_less
(const std::string & _opt1,
const std::string & _opt2)
{
    if(_opt1 == "#" || _opt1 == "(" || _opt2 == ")")
        return true;
    else if (_opt1 == ")" || _opt2 == "(")
        return false;
    
    assert(__priority_c.find(_opt1) != __priority_c.end());
    assert(__priority_c.find(_opt2) != __priority_c.end());

    auto _prio1 = __priority_c[_opt1];
    auto _prio2 = __priority_c[_opt2];
    
    if (_prio1 == _prio2)
        return false;
    return _prio1 > _prio2;

}

int __is_unary_op(int ch)
{
    // &*-+!~
    return ch == '&' || ch == '*' || 
        ch == '-' || ch == '+' || 
        ch == '!' || ch == '~';
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
    { 
        ++__num_it_; __reach_end_(); 
    }

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

bool __is_parentheses(const std::string & __token_)
{
    return __token_ == "(" || __token_ == ")";
}

void __collect_midexpr_tokens
(const std::string & __expr_, 
std::vector<std::string> & __tokens_)
{
    size_t __expr_sz = __expr_.size();
    for(size_t i = 0; i < __expr_sz; )
    {
        auto __conv_2_token = std::string(1, __expr_[i]);
        if(::isdigit(__expr_[i]) || __is_unary_op(__expr_[i]))
        {// scan for a token
            std::string __token_;
            do{
                __token_ += __expr_[i];
                ++i;
            }while(i< __expr_sz && ::isxdigit(__expr_[i]));
            if(__is_int_(__token_) || __is_c_opt_(__token_))
                __tokens_.push_back(__token_);
        }

        else if(__is_c_opt_(__conv_2_token) ||
            __is_parentheses(__conv_2_token))
            __tokens_.push_back(__conv_2_token), ++i;
        
        else // error ignore
            ++i;
    }
}

// middlefix expression to reverse pollish notation
// C version
// do not deal with illegal 
void __midexpr_2_rpn
(const std::vector<std::string> & mTokens, 
std::vector<std::string> &rpnTokens)
{
    std::stack<std::string> __tmp_op; // tmp opt
    std::deque<std::string> __dest_op; // opt and opd

    __tmp_op.push("#");
    for(auto token : mTokens)
    {
        if(__is_int_(token))
            __dest_op.push_back(token);
        else if (__is_c_opt_(token))
        {
            while(!__tmp_op.empty() && 
                    !__c_opt_less(__tmp_op.top(), token))
            {
                __dest_op.push_back(__tmp_op.top());
                __tmp_op.pop();
            }
            // if (__c_opt_less(__tmp_op.top(), token))
            // make sure of #
            __tmp_op.push(token);

        } 
        else if (token == "(")
            __tmp_op.push("(");
        else if (token == ")")
        {
            while(!__tmp_op.empty() && __tmp_op.top()!= "(")
            {
                __dest_op.push_back(__tmp_op.top());
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
        // Alan::ConsoleBeautyOutput(rpnTokens);
        // Alan::ConsoleBeautyOutput(__dest_op);
    }

    while(__tmp_op.size() > 1) // # 
    {
        __dest_op.push_back(__tmp_op.top());
        __tmp_op.pop();
    }

    rpnTokens.reserve(rpnTokens.size() + __dest_op.size());
    while(!__dest_op.empty())
    {
        rpnTokens.push_back(__dest_op.front());
        __dest_op.pop_front();
    }

}

void __rpn_2_midexpr
(const std::vector<std::string> & rpnTokens,
std::vector<std::string> &mTokens)
{

}

__END_NS__

__USE_NS__(Alan::SelfAlgo::Inst);
__DEF_NS__(Alan::SelfAlgo::Inst::Test)

void TestCOptLess()
{
    _COLOR_START(_COLOR_BLUE);
    __init_priority_c();
    PRINTLN_DETAIL(__c_opt_less("(", ")"));
    PRINTLN_DETAIL(__c_opt_less("(", "*"));
    PRINTLN_DETAIL(__c_opt_less("(", "+"));
    PRINTLN_DETAIL(__c_opt_less(")", "("));
    PRINTLN_DETAIL(__c_opt_less(")", "*"));
    PRINTLN_DETAIL(__c_opt_less(")", "+"));
    PRINTLN_DETAIL(__c_opt_less(")", "%"));

    PRINTLN("normal:");
    PRINTLN_DETAIL(__c_opt_less("*", ")"));
    PRINTLN_DETAIL(__c_opt_less("*", "*"));
    PRINTLN_DETAIL(__c_opt_less("*", "/"));
    PRINTLN_DETAIL(__c_opt_less("/", "+"));
    PRINTLN_DETAIL(__c_opt_less("/", "("));
    PRINTLN_DETAIL(__c_opt_less("+", "*"));
    PRINTLN_DETAIL(__c_opt_less("+", "-"));
    PRINTLN_DETAIL(__c_opt_less("-", "%"));
    _COLOR_RECOVER;
}

void TestIntToken()
{
    _COLOR_START(_COLOR_CYAN);
    PRINTLN_DETAIL(__is_int_("11"));
    PRINTLN_DETAIL(__is_int_("011"));
    PRINTLN_DETAIL(__is_int_("0x11"));
    PRINTLN_DETAIL(__is_int_("0b11"));
    PRINTLN_DETAIL(__is_int_("0B11"));
    PRINTLN_DETAIL(__is_int_("0X11"));
    PRINTLN_DETAIL(__is_int_("-11"));
    PRINTLN_DETAIL(__is_int_("-011"));
    PRINTLN_DETAIL(__is_int_("-0x11"));
    PRINTLN_DETAIL(__is_int_("-0b11"));
    PRINTLN_DETAIL(__is_int_("-0B11"));
    PRINTLN_DETAIL(__is_int_("-0X11"));
    PRINTLN_DETAIL(__is_int_("+11"));
    PRINTLN_DETAIL(__is_int_("+011"));
    PRINTLN_DETAIL(__is_int_("+0x11"));
    PRINTLN_DETAIL(__is_int_("+0b11"));
    PRINTLN_DETAIL(__is_int_("+0B11"));
    PRINTLN_DETAIL(__is_int_("+0X11"));
    _COLOR_RECOVER;

    _COLOR_START(_COLOR_RED);
    PRINTLN_DETAIL(__is_int_("A11"));
    PRINTLN_DETAIL(__is_int_("M011"));
    PRINTLN_DETAIL(__is_int_("qq11"));
    PRINTLN_DETAIL(__is_int_("0bbaa11"));
    PRINTLN_DETAIL(__is_int_("0Bca11"));
    PRINTLN_DETAIL(__is_int_("0Xasww11"));
    PRINTLN_DETAIL(__is_int_("+A11"));
    PRINTLN_DETAIL(__is_int_("+M011"));
    PRINTLN_DETAIL(__is_int_("+qq11"));
    PRINTLN_DETAIL(__is_int_("+0bbaa11"));
    PRINTLN_DETAIL(__is_int_("+0Bca11"));
    PRINTLN_DETAIL(__is_int_("+0Xasww11"));
    PRINTLN_DETAIL(__is_int_("-A11"));
    PRINTLN_DETAIL(__is_int_("-M011"));
    PRINTLN_DETAIL(__is_int_("-qq11"));
    PRINTLN_DETAIL(__is_int_("-0bbaa11"));
    PRINTLN_DETAIL(__is_int_("-0Bca11"));
    PRINTLN_DETAIL(__is_int_("-0Xasww11"));
    _COLOR_RECOVER;
}

void TestMidExpr2RPN()
{
__init_priority_c();
// 1.
// ((2 + 1) * 3) -> 
// ["2","1","+","3","*"]
{
    auto mTokens = std::vector<std::string>();
    auto rpnTokens = std::vector<std::string>();
    __collect_midexpr_tokens("((2 + 1) * 3)", mTokens);
    // Alan::ConsoleBeautyOutput(mTokens);
    __midexpr_2_rpn(mTokens, rpnTokens);
    // Alan::ConsoleBeautyOutput(rpnTokens);
    PRINTLN_DETAIL(Alan::LC::evalRPN(rpnTokens));
// [(, (, 2, +, 1, ), *, 3, )]
// [2, 1, +, 3, *]
}

// 2.
// (4 + (13 / 5)) -> 
// ["4","13","5","/","+"]
{
    auto mTokens = std::vector<std::string>();
    auto rpnTokens = std::vector<std::string>();
    __collect_midexpr_tokens("(4 + (13 / 5))", mTokens);
    // Alan::ConsoleBeautyOutput(mTokens);
    __midexpr_2_rpn(mTokens, rpnTokens);
    // Alan::ConsoleBeautyOutput(rpnTokens);
    PRINTLN_DETAIL(Alan::LC::evalRPN(rpnTokens));
// [(, 4, +, (, 13, /, 5, ), )]
// [4, 13, 5, /, +]
}

// 3.
// ((10 * (6 / ((9 + 3) * -11))) + 17) + 5 -> 
// ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
{
    auto mTokens = std::vector<std::string>();
    auto rpnTokens = std::vector<std::string>();
    __collect_midexpr_tokens("((10 * (6 / ((9 + 3) * -11))) + 17) + 5", mTokens);
    // Alan::ConsoleBeautyOutput(mTokens);
    __midexpr_2_rpn(mTokens, rpnTokens);
    // Alan::ConsoleBeautyOutput(rpnTokens);
    PRINTLN_DETAIL(Alan::LC::evalRPN(rpnTokens));
// [(, (, 10, *, (, 6, /, (, (, 9, +, 3, ), *, -11, ), ), ), +, 17, ), +, 5]
// [10, 6, 9, 3, +, -11, *, /, *, 17, +, #, 5]
}

}

void TestRPN2MidExpr()
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