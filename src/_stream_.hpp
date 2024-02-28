#pragma once 
#ifndef _STREAM_HPP
#define _STREAM_HPP

#include "_i_lib_.hpp"
#include <string>
#include <list>
#include <memory>
#include <map>


#define ASSERT_FILE(f_name) \
    auto inputFilePtr = readFile(f_name); \
    assert(inputFilePtr); \
    auto inputFile = inputFilePtr.get(); \
    assert(inputFile && inputFile->is_open()); \


void ReadFile(string const &, string &);
void AppendFile(string const &, string &);
void RewriteFile(string const &, string &);
void DeferCloseFile(list<fstream> &);
void ReadForStdout(string const &);
void GetlineForStdout();
void GetWorldCapitals(string const &, map<string, string> &);
void PrintWorldCapitals(map<string,string> const &, int const &);
string replaceAllWhiteSpace(string &);

#endif 