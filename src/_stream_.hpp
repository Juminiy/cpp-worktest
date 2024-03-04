#pragma once 
#ifndef _STREAM_HPP
#define _STREAM_HPP

#include "_i_lib_.hpp"

#include <string>
#include <list>
#include <map>


#define ASSERT_FILE(f_name) \
    auto inputFilePtr = readFile(f_name); \
    assert(inputFilePtr); \
    auto inputFile = inputFilePtr.get(); \
    assert(inputFile && inputFile->is_open()); \



enum writeMode{
    readOnly,
    appendOnly,
    rewriteOnly
};

void ReadFile(string const &, string &);
void AppendFile(string const &, string &);
void RewriteFile(string const &, string &);
void writeFile(string const &, string &, writeMode const);
void DeferCloseFile(list<fstream> &);
void ReadForStdout(string const &);
void GetlineForStdout();
void GetWorldCapitals(string const &, map<string, string> &);
void parseCountryAndCapital(string const &, string &, string &);
void PrintWorldCapitals(map<string,string> const &, int const &);
string replaceAllWhiteSpace(string &);
void PrintOSS(string const &);
void MultiTypesOSS(string const &);

template <typename RetType>
RetType GetTypeValue();

template <typename SrcType>
string Type2String(SrcType const &);

bool HasHexLetters(long long const &);
bool HasHexLetters_bits_version(int const &);
bool HasHexLetters_loop_version(int const &);
bool HasHexLetters_ss_functor_version(long long const &);

string GetLine();
unique_ptr<fstream> readFile(string const &);

#endif 