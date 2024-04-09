#ifndef _POLYM_HPP
#define _POLYM_HPP

#include "_i_lib_.hpp"
#include "_stl_lib_.hpp"

__DEF_NS__(Alan)

__DEF_NS__(Demos)

class Base 
{
public:
    virtual void print() 
    const noexcept
    {
        PRINTLN("Base");
    }
    virtual ~Base(){
        // PRINTLN("Base dest");
    }
};

class Derived0 
    :public Base
{
public:
    void print()
    const noexcept override
    {
        PRINTLN("Derived0");
    }
};

__END_NS__

__END_NS__

void TestPolym0();

#endif 