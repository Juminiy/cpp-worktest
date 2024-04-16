#include "../../include/_i_lib_.hpp"
#include "../../include/_stl_lib_.hpp"

#include "../../include/_sim_printer_.hpp"

#include <cstring>

// impl in Alan::Demos0 namespace, other namespace
// (1). can not modify the source file
// (2). can not modify the Alan::Demos0::_Printer impl

__USE_NS__(Alan::Demos0);

void _Printer::setFont(const std::string & fontName, size_t _sz)
{
    this->__font_nm = __tstrdup_(fontName.c_str());
    this->__font_sz = _sz;
}


void _Printer::setColor(const std::string & _color)
{
    auto _col_i = std::stoi(_color);
    if (I32_IN_RANGE(_col_i, _COLOR_BLACK, _COLOR_WHITE))
        this->__color__ = _col_i;
}

void _Printer::printDocument(const std::string & _document) const 
{
    PRINTLN(_COLOR_CL_VAR(std::to_string(this->__color__), _document));
}