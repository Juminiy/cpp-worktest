#pragma once
#ifndef _FUNC_HPP
#define _FUNC_HPP

#include "_i_lib_.hpp"
#include "_stl_lib_.hpp"

#include <functional>

__DEF_NS__(Alan::Demos)

    typedef 
    std::function<int (const int &, const int &)> 
    calBinOpt;

    typedef std::pair<std::string, calBinOpt> 
    calBinPair;

    typedef int (*subFunc) (const int &, const int &);

    template <size_t _Sz = (1<<2)>
    bool _std_string_sz_less
    (std::string const & _str)
    noexcept
    {
        return _str.size() < _Sz;
    }

    class _comp_str_sz 
    {
    public:
        explicit _comp_str_sz
        (const size_t __sz = (1<<2))
            : _sz(__sz) { }
        bool operator() 
        (const std::string & _str) 
        const noexcept 
        {
            return _str.size() < _sz;
        }
    private:
        const size_t _sz;
    };

    typedef double (*_fn_d2d)(double); 

    
    // class _unray_fn0 
    //     : public std::unary_function<std::string, bool >
    // {
    // public:
    //     bool operator() 
    //     (std::string const & _str)
    //     noexcept const 
    //     {
    //         return false;
    //     }
    // };

__END_NS__


__DEF_NS__(Alan::Demos::Test::Func)

void TestFunc();
void TestTask2();
void TestTask3();
void TestTask4();

void TestLambda2();

__END_NS__

#endif