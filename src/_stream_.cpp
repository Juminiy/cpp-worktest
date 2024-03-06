#include "_i_lib_.hpp"
#include "_stream_.hpp"

#include <fstream>
#include <iostream>
#include <iomanip>
#include <memory>
#include <sstream>
#include <algorithm>
#include <functional>
#include <iterator>

#include <cassert>
#include <cctype>

unique_ptr<fstream> readFile(string const &);

void ReadFile(string const &fileName, string &fileDesc)
{
    ASSERT_FILE(fileName);

    string fileDescPart;
    while((*inputFile) >> fileDescPart)
    {
        fileDesc += fileDescPart + "";
    }

    inputFile->close();
}

void AppendFile(string const &fileName, string &fileDesc)
{
    writeFile(fileName, fileDesc, appendOnly);
}

void RewriteFile(string const &fileName, string &fileDesc)
{
    writeFile(fileName, fileDesc, rewriteOnly);
}

void writeFile(string const &fileName, string &fileDesc, writeMode const mode)
{
    fstream::openmode fOpenMode = ofstream::out;
    if (mode == appendOnly)
    {
        fOpenMode |= ofstream::app;
    } else if (mode == rewriteOnly)
    {
    
    } else 
    {
        cerr << "OpenModeError: fileName" << "<" << fileName << ">" << ", " << "mode" << "<" << mode << ">" << endl;
        return; 
    }

    ofstream outputFile(fileName, fOpenMode);
    if (!outputFile.is_open())
    {
        cerr << "WriteError: fileName" << "<" << fileName << ">" << " was not opened" << endl;
        return ;
    }
    
    outputFile << fileDesc << endl;

    outputFile.close();
}

void DeferCloseFile(list<fstream> &fileStreams)
{
    for ( auto &fileStream : fileStreams)
    {
        if (fileStream.is_open())
        {
            fileStream.close();
        }
    }
}

void ReadForStdout(string const &fileName)
{
    ASSERT_FILE(fileName);

    int i32;
    double f64;
    string str5;
    while((*inputFile) >> i32 >> f64 >> str5)
    {
        cout << "[" << setfill(' ') << right << setw(1<<3)  << i32 << " | "
                    << setfill(' ') << right << setw(1<<3)  << f64 << " | "
                    << setfill(' ') << right << setw(1<<3)  << str5 << " ] " << endl;
    }

    inputFile->close();
}


unique_ptr<fstream> readFile(string const &fileName)
{
    unique_ptr<fstream> inputFile(new fstream(fileName, ifstream::in));
    if (!inputFile.get()->is_open())
    {
        cerr << "ReadError: fileName" << "<" << fileName << ">" << " was not opened" << endl;
        return nullptr;
    }

    return inputFile;
}

void GetlineForStdout()
{   
    fprintf(stdout, " input: ");
    string one_line;
    getline(std::cin, one_line);
    fprintf(stdout, "output: %s\n", one_line.c_str());
}

// Country - Capital(s)
// Afghanistan - Kabul
void GetWorldCapitals(string const &fileName, map<string,string> &capitals)
{
    // ignore first line 
    // split Country and Capital by "-" | '-'
    
    ASSERT_FILE(fileName);

    typedef pair<string,string> country_capital;
    string one_line;
    int cal_line = 0;

    printf("%s\n%d\n",__FILE__, __LINE__);

    while(getline(*inputFile, one_line))
    {   
        assert(!inputFile->fail());
        cal_line++;
        if (cal_line == 1){
            continue;
        }
        string country, capital;
        parseCountryAndCapital(one_line, country, capital);
        capitals.insert(country_capital(country, capital));
    }

    inputFile->close();
}

void parseCountryAndCapital(string const &src, string &country, string &capital)
{
    char splitChar = '-';
    auto str_it = src.find(splitChar);
    if (str_it == string::npos)
    {
        cerr << "src" << "<" << src << ">" << " do not contain any '-'" << endl;
        return ;
    }

    country = src.substr(0, str_it);
    country = replaceAllWhiteSpace(country);
    capital = src.substr(str_it+sizeof(splitChar), src.size());
    capital = replaceAllWhiteSpace(capital);
}

string replaceAllWhiteSpace(string &src)
{
    string dest;

    for( auto &ch : src)
        if(ch != ' ')
            dest += ch;

    return dest;
}

void PrintWorldCapitals(map<string,string> const &capitals, int const &cnt)
{   
    int _cnt = cnt;
    for (auto &pr : capitals)
    {
        if(_cnt > 0){
            _cnt --;
            cout << "<" << RED_STR(pr.first) << ", " << RED_STR(pr.second) << ">" << endl;
        }
    }
}

void PrintOSS(string const &_string_)
{
    ostringstream oss;
    oss << "OSS: _string_<" << _string_ << ">" ;
    cout << oss.str() << endl;
}

void MultiTypesOSS(string const &_v)
{
    ostringstream oss;
    oss << "OSS: string<" << "string" << ">, int<" << 1 << ">, double<" << 1.0 << ">, char<" << 'c' << ">";
    cout << oss.str() << endl;
    oss.clear();

    unique_ptr<stringstream> oss_ptr(new stringstream);
    *(oss_ptr.get()) << _v ;
    int ast_i32;
    double ast_f64;
    string ast_str5, ast_str8;
    char ast_ch1;
    *(oss_ptr.get()) >> ast_i32 >> ast_f64 >> ast_str5 >> ast_str8 >> ast_ch1;
    cout << "ast_i32<" << ast_i32 
            << ">, ast_f64<" << ast_f64 
            << ">, ast_str5<" << ast_str5 
            << ">, ast_str8<" << ast_str8 
            << ">, ast_ch1<" << ast_ch1 
            << ">" << endl;
}

string GetLine()
{
    string _str;
    getline(cin, _str);
    return _str;
}

template <typename RetType>
RetType GetTypeValue()
{
    while(true)
    {
        stringstream ss;
        ss << GetLine();

        RetType _ret;
        if (ss >> boolalpha >> _ret)
        {
            char _rem;
            if (ss >> _rem)
                cerr << "input remained: _rem< "<< _rem << " >" << endl;
            else 
                return _ret;
        } else
        {
            cerr << "input error: _str< "<< ss.str() << " >" << endl;
        }
    }
}

template int GetTypeValue();
template double GetTypeValue();
template bool GetTypeValue();

template <typename SrcType>
string Type2String(SrcType const &_val)
{
    stringstream ss;
    ss << boolalpha << _val;
    return ss.str();
}

template string Type2String(int const &);
template string Type2String(double const &);
template string Type2String(bool const &);



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
    stringstream ss;
    ss << hex << _i32;
    string hex_str = ss.str();
    for ( auto &_x : hex_str)
        if (isalpha(_x))
            return true;
    return false; 
}


// 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000
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
    stringstream ss;
    ss << hex << _i64;
    istreambuf_iterator<char> ssit(ss);
    return any_of(ssit, istreambuf_iterator<char>(), char_bits_is_letter);
}   