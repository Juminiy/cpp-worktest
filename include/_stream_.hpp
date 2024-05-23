#pragma once 
#ifndef _STREAM_HPP
#define _STREAM_HPP

#include "_i_lib_.hpp"

#include <string>
#include <list>
#include <map>
#include <memory>

#define StaticFilePrefix "test/static-file/"
#define ConFilePath(_file_name_) StaticFilePrefix#_file_name_
#define PatFilePath(_file_name_) StaticFilePrefix + std::string(_file_name_)

#define ASSERT_FILE(f_name) \
    auto inputFilePtr = readFile(f_name); \
    assert(inputFilePtr); \
    auto inputFile = inputFilePtr.get(); \
    assert(inputFile && inputFile->is_open()); \

__DEF_NS__(Alan::Demos::Test::Func)

enum writeMode{
    readOnly,
    appendOnly,
    rewriteOnly
};

void ReadFile(std::string const &, std::string &);
void AppendFile(std::string const &, std::string &);
void RewriteFile(std::string const &, std::string &);
void writeFile(std::string const &, std::string &, writeMode const);
void DeferCloseFile(std::list<std::fstream> &);
void ReadForStdout(std::string const &);
void GetlineForStdout();
void GetWorldCapitals(std::string const &, std::map<std::string, std::string> &);
void parseCountryAndCapital(std::string const &, std::string &, std::string &);
void PrintWorldCapitals(std::map<std::string, std::string> const &, int const &);
std::string replaceAllWhiteSpace(std::string &);
void PrintOSS(std::string const &);
void MultiTypesOSS(std::string const &);

template <typename RetType>
RetType GetTypeValue();

template <typename SrcType>
std::string Type2String(SrcType const &);

bool HasHexLetters(long long const &);
bool HasHexLetters_bits_version(int const &);
bool HasHexLetters_loop_version(int const &);
bool HasHexLetters_ss_functor_version(long long const &);

std::string GetLine();
std::unique_ptr<std::fstream> readFile(std::string const &);

__END_NS__

#endif 