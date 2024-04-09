#include "../../include/_polym_.hpp"

#include <memory>

void TestPolym0()
{
    std::shared_ptr<Alan::Demos::Base> _base_ptr = 
        std::make_shared<Alan::Demos::Derived0>();
    
    std::shared_ptr<Alan::Demos::Derived0> _derived0_ptr
        (_base_ptr, static_cast<Alan::Demos::Derived0*>(_base_ptr.get()));
    
    _derived0_ptr->print();
}