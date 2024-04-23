#pragma once
#ifndef _SIM_PRINTER_HPP
#define _SIM_PRINTER_HPP

#include "_i_lib_.hpp"
#include "_stl_lib_.hpp"

#include <string>

__DEF_NS__(Alan::Demos0)

// only to print document synchronized
class _Printer 
{
public:
    void setFont(const std::string &, size_t);
    void setColor(const std::string &);
    void printDocument(const std::string &) const;
private:
    // details
    char * __font_nm;
    size_t __font_sz;
    int    __color__;
};

__END_NS__

#endif 