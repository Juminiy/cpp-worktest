#pragma once
#ifndef _FUNC_HPP
#define _FUNC_HPP

#include "_i_lib_.hpp"
#include "_stl_lib_.hpp"

#include <functional>

USE_NAMESPACE_ALAN

typedef 
std::function<int (const int &, const int &)> 
calBinOpt;

typedef std::pair<std::string, calBinOpt> 
calBinPair;

void TestFunc();
void TestTask2();

END_NAMESPACE_ALAN

#endif