#pragma once 
#ifndef _ASSO_CONTAINER_HPP
#define _ASSO_CONTAINER_HPP

#include "_i_lib_.hpp"

__DEF_NS__(Alan::Demos::Test::Func)

typedef std::unordered_map<int, std::string > um_i32_str;
typedef um_i32_str::value_type _i32_str_pr ;

typedef std::map<std::string, std::string > _SS_Map;
typedef std::map<std::string, std::string > & _SS_Map_reference;
typedef const std::map<std::string, std::string > & _SS_Map_const_reference;

typedef std::multimap<std::string, std::string> _SS_MMap;
typedef std::multimap<std::string, std::string> & _SS_MMap_reference;
typedef const std::multimap<std::string, std::string> & _SS_MMap_const_reference;

typedef std::map<std::string, int > _SI_Map;
typedef std::map<std::string, int > & _SI_Map_referecne;
typedef const std::map<std::string, int > & _SI_Map_const_reference;

void TestUMap();
void TestBirthDayParadox();
void TestUSet();
void TestIterator();
void TestMapDiffer();
void CountKeyWordsOccurences();
void TestMultiContainer();
void TestRangeFind();
void TestMatchingPrefix();

__END_NS__

#endif 