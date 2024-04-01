#include "../../include/_i_lib_.hpp"

#include "../../include/_stream_.hpp"



#include <cassert>
#include <cctype>

#include <fstream>
#include <iostream>
#include <iomanip>
#include <memory>
#include <sstream>
#include <algorithm>
#include <functional>
#include <iterator>

std::unique_ptr<std::fstream> readFile(std::string const &);

void ReadFile(std::string const &fileName, std::string &fileDesc)
{
    ASSERT_FILE(fileName);

    std::string fileDescPart;
    while((*inputFile) >> fileDescPart)
    {
        fileDesc += fileDescPart + "";
    }

    inputFile->close();
}

void AppendFile(std::string const &fileName, std::string &fileDesc)
{
    writeFile(fileName, fileDesc, appendOnly);
}

void RewriteFile(std::string const &fileName, std::string &fileDesc)
{
    writeFile(fileName, fileDesc, rewriteOnly);
}

void writeFile(std::string const &fileName, 
                std::string &fileDesc, 
                writeMode const mode)
{
    std::fstream::openmode fOpenMode = std::ofstream::out;
    if (mode == appendOnly)
    {
        fOpenMode |= std::ofstream::app;
    } else if (mode == rewriteOnly)
    {
    
    } else 
    {
        std::cerr << "OpenModeError: fileName" 
                << "<" << fileName << ">" 
                << ", " 
                << "mode" << "<" << mode << ">" 
                << __LN__;
        return; 
    }

    std::ofstream outputFile(fileName, fOpenMode);
    if (!outputFile.is_open())
    {
        std::cerr << "WriteError: fileName" 
                << "<" << fileName << ">" 
                << " was not opened" << __LN__;
        return ;
    }
    
    outputFile << fileDesc << __LN__;

    outputFile.close();
}

void DeferCloseFile(std::list<std::fstream> &fileStreams)
{
    for ( auto &fileStream : fileStreams)
    {
        if (fileStream.is_open())
        {
            fileStream.close();
        }
    }
}

void ReadForStdout(std::string const &fileName)
{
    ASSERT_FILE(fileName);

    int i32;
    double f64;
    std::string str5;
    while((*inputFile) >> i32 >> f64 >> str5)
    {
        std::cout << "[" << std::setfill(' ') 
                    << std::right << std::setw(1<<3) 
                    << i32 << " | "
                    << std::setfill(' ') 
                    << std::right << std::setw(1<<3)  
                    << f64 << " | "
                    << std::setfill(' ') 
                    << std::right << std::setw(1<<3)  
                    << str5 << " ] " << __LN__;
    }

    inputFile->close();
}


std::unique_ptr<std::fstream> readFile(std::string const &fileName)
{
    std::unique_ptr<std::fstream> 
        inputFile(new std::fstream(fileName, 
                                std::ifstream::in));
    if (!inputFile.get()->is_open())
    {
        std::cerr << "ReadError: fileName" 
                << "<" << fileName << ">" 
                << " was not opened" << __LN__;
        return nullptr;
    }

    return inputFile;
}

void GetlineForStdout()
{   
    fprintf(stdout, " input: ");
    std::string one_line;
    std::getline(std::cin, one_line);
    fprintf(stdout, "output: %s\n", one_line.c_str());
}

// Country - Capital(s)
// Afghanistan - Kabul
void GetWorldCapitals(std::string const &fileName, 
                        std::map<std::string, std::string> &capitals)
{
    // ignore first line 
    // split Country and Capital by "-" | '-'
    
    ASSERT_FILE(fileName);

    typedef std::pair<std::string, std::string> country_capital;
    std::string one_line;
    int cal_line = 0;

    printf("%s\n%d\n",__FILE__, __LINE__);

    while(std::getline(*inputFile, one_line))
    {   
        assert(!inputFile->fail());
        ++cal_line;
        if (cal_line == 1){
            continue;
        }
        std::string country, capital;
        parseCountryAndCapital(one_line, country, capital);
        capitals.insert(country_capital(country, capital));
    }

    inputFile->close();
}

void parseCountryAndCapital
(std::string const &src, 
std::string &country, 
std::string &capital)
{
    char splitChar = '-';
    auto str_it = src.find(splitChar);
    if (str_it == std::string::npos)
    {
        std::cerr << "src" 
                << "<" << src << ">" 
                << " do not contain any '-'" 
                << __LN__;
        return ;
    }

    country = src.substr(0, str_it);
    country = replaceAllWhiteSpace(country);
    capital = src.substr(str_it+sizeof(splitChar), src.size());
    capital = replaceAllWhiteSpace(capital);
}

std::string replaceAllWhiteSpace(std::string &src)
{
    std::string dest;

    for( auto &ch : src)
        if(ch != ' ')
            dest += ch;

    return dest;
}

void PrintWorldCapitals
(std::map<std::string, std::string> const &capitals, 
                    int const &cnt)
{   
    int _cnt = cnt;
    for (auto &pr : capitals)
    {
        if(_cnt > 0){
            --_cnt;
            std::cout << "<" 
                    << _RED(pr.first) 
                    << ", " 
                    << _RED(pr.second) 
                    << ">" << __LN__;
        }
    }
}

void PrintOSS(std::string const &_string_)
{
    std::ostringstream oss;
    oss << "OSS: _string_<" << _string_ << ">" ;
    std::cout << oss.str() << __LN__;
}

void MultiTypesOSS(std::string const &_v)
{
    std::ostringstream oss;
    oss << "OSS: string<" 
            << "string" 
            << ">, int<" 
            << 1 << ">, double<" 
            << 1.0 << ">, char<" 
            << 'c' << ">";
    std::cout << oss.str() << __LN__;
    oss.clear();

    std::unique_ptr<std::stringstream> oss_ptr(new std::stringstream);
    *(oss_ptr.get()) << _v ;
    int ast_i32;
    double ast_f64;
    std::string ast_str5, ast_str8;
    char ast_ch1;
    *(oss_ptr.get()) 
                >> ast_i32 
                >> ast_f64 
                >> ast_str5 
                >> ast_str8 
                >> ast_ch1;
                
    std::cout << "ast_i32<" << ast_i32 
            << ">, ast_f64<" << ast_f64 
            << ">, ast_str5<" << ast_str5 
            << ">, ast_str8<" << ast_str8 
            << ">, ast_ch1<" << ast_ch1 
            << ">" << __LN__;
}

std::string GetLine()
{
    std::string _str;
    std::getline(std::cin, _str);
    return _str;
}

template <typename RetType>
RetType GetTypeValue()
{
    while(true)
    {
        std::stringstream ss;
        ss << GetLine();

        RetType _ret;
        if (ss >> std::boolalpha >> _ret)
        {
            char _rem;
            if (ss >> _rem)
                std::cerr << "input remained: _rem< "
                        << _rem << " >" << __LN__;
            else 
                return _ret;
        } else
        {
            std::cerr << "input error: _str< "
                    << ss.str() << " >" << __LN__;
        }
    }
}

template int GetTypeValue();
template double GetTypeValue();
template bool GetTypeValue();

template <typename SrcType>
std::string Type2String(SrcType const &_val)
{
    std::stringstream ss;
    ss << std::boolalpha << _val;
    return ss.str();
}

template std::string Type2String(int const &);
template std::string Type2String(double const &);
template std::string Type2String(bool const &);



// ch = 0000 0000

// comp is 
// A 1010
// B 1011
// C 1100
// D 1101
// E 1110
// F 1111
bool char_bits_is_letter(char const &ch)
{
    char hi_4 = (ch & 0xf0) >> 4;
    char lo_4 = ch & 0x0f;
    return hi_4 >= 0x0a || 
            lo_4 >= 0x0a;
}

// 0000 0000 0000 0000 0000 0000 0000 0000
bool HasHexLetters_bits_version(int const &_i32)
{
    char hi_8 = (_i32 & 0xff000000) >> 24;
    char hi_16 = (_i32 & 0x00ff0000) >> 16;
    char hi_24 = (_i32 & 0x0000ff00) >> 8;
    char hi_32 = (_i32 & 0x000000ff) >> 0;
    
    return char_bits_is_letter(hi_8) || 
            char_bits_is_letter(hi_16) || 
            char_bits_is_letter(hi_24) || 
            char_bits_is_letter(hi_32);
}

bool HasHexLetters_loop_version(int const &_i32)
{
    std::stringstream ss;
    ss << std::hex << _i32;
    std::string hex_str = ss.str();
    for ( auto &_x : hex_str)
        if (isalpha(_x))
            return true;
    return false; 
}


// 0000 0000 0000 0000 0000 0000 0000 0000 
// 0000 0000 0000 0000 0000 0000 0000 0000
bool HasHexLetters(long long const &_i64)
{   
    char hi_8 = (_i64 & 0xff00000000000000) >> 56;
    char hi_16 = (_i64 & 0x00ff000000000000) >> 48;
    char hi_24 = (_i64 & 0x0000ff0000000000) >> 40;
    char hi_32 = (_i64 & 0x000000ff00000000) >> 32;
    char hi_40 = (_i64 & 0x00000000ff000000) >> 24;
    char hi_48 = (_i64 & 0x0000000000ff0000) >> 16;
    char hi_56 = (_i64 & 0x000000000000ff00) >> 8;
    char hi_64 = (_i64 & 0x00000000000000ff) >> 0;

    return char_bits_is_letter(hi_8) || 
            char_bits_is_letter(hi_16) || 
            char_bits_is_letter(hi_24) || 
            char_bits_is_letter(hi_32) || 
            char_bits_is_letter(hi_40) || 
            char_bits_is_letter(hi_48) || 
            char_bits_is_letter(hi_56) || 
            char_bits_is_letter(hi_64);
}

bool HasHexLetters_ss_functor_version(long long const &_i64)
{
    std::stringstream ss;
    ss << std::hex << _i64;
    return std::any_of(std::istream_iterator<char>(ss), 
                    std::istream_iterator<char>(), 
                    [](char const &ch){
                        return ((ch & 0xf0) >> 4) >= 0x0a || 
                                (ch & 0x0f) >= 0x0a;
                    });
}   