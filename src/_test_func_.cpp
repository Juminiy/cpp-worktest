#include "_test_func_.hpp"
#include "_i_lib_.hpp"
#include "_stream_.hpp"

#include <iostream>
#include <memory>
#include <map>
#include <string>
#include <sstream>

string testLocalLayout();

void TestReadWriteFile()
{
    string fileContent;
    ReadFile(INPUT_FILE, fileContent);
    RewriteFile(OUTPUT_FILE, fileContent);
}

void TestBoolAlpha()
{   
    ostringstream oss;

    #if defined(_WIN64) || defined(WIN64) || defined(__amd64__) || \
	defined(__x86_64) || defined(__x86_64__) || defined(_M_IA64) || \
	defined(_M_AMD64)
    oss << "x86/x86_64/amd64" << " : " << "Win64" << endl;
    #elif defined(_WIN32) || defined(WIN32) || defined(__i386__) || \
    	defined(__i386) || defined(_M_X86)
    oss << "x86/x86_64/amd64" << " : " << "Win32" << endl;
    #elif defined(__MACOS__)
	oss << "x64/arm64" << " : " << "MacOS" << endl;
    #elif defined(__APPLE__) && defined(__MACH__)
	#include <sys/types.h>
	oss << "none-arch" << " : " << "Apple" << endl;
    #elif defined(__BEOS__)
	#include <sys/inttypes.h>
	oss << "none-arch" << " : " << "BEOS" << endl;
    #elif (defined(_MSC_VER) || defined(__BORLANDC__)) && (!defined(__MSDOS__))
	oss << "none-arch" << " : " << "MSDOS" << endl;
    #elif defined(__GNUC__)
	#include <stdint.h>
	oss << "none-arch" << " : " << "GNU" << endl;
    #else 
    oss << "none-arch" << " : " << "none-os" << endl;
    #endif

    oss << "sizeof builtin type: " << endl;
    oss << "sizeof(bool) = " << sizeof(bool) << endl;
    oss << "sizeof(char) = " << sizeof(char) << endl;
    oss << "sizeof(short) = " << sizeof(short) << endl;
    oss << "sizeof(int) = " << sizeof(int) << endl;
    oss << "sizeof(long) = " << sizeof(long) << endl;
    oss << "sizeof(long long) = " << sizeof(long long) << endl;
    oss << "sizeof(float) = " << sizeof(float) << endl;
    oss << "sizeof(double) = " << sizeof(double) << endl;
    oss << "sizeof(long double) = " << sizeof(long double) << endl;
    oss << "sizeof(nullptr_t) = " << sizeof(nullptr_t) << endl;

    oss << "sizeof some value: " << endl;
    oss << "sizeof(NULL) = " << sizeof(NULL) << endl;
    oss << "sizeof(true) = " << sizeof(true) << endl;
    oss << "sizeof(false) = " << sizeof(false) << endl;
    
    oss << "sizeof(char16_t) = " << sizeof(char16_t) << endl;
    oss << "sizeof(char32_t) = " << sizeof(char32_t) << endl;
    oss << "sizeof(wchar_t) = " << sizeof(wchar_t) << endl;
    oss << "sizeof(int8_t) = " << sizeof(int8_t) << endl;
    oss << "sizeof(int16_t) = " << sizeof(int16_t) << endl;
    oss << "sizeof(int32_t) = " << sizeof(int32_t) << endl;
    oss << "sizeof(int64_t) = " << sizeof(int64_t) << endl;
    oss << "sizeof(uint8_t) = " << sizeof(uint8_t) << endl;
    oss << "sizeof(uint16_t) = " << sizeof(uint16_t) << endl;
    oss << "sizeof(uint32_t) = " << sizeof(uint32_t) << endl;
    oss << "sizeof(uint64_t) = " << sizeof(uint64_t) << endl;
    oss << "sizeof(size_t) = " << sizeof(size_t) << endl;
    oss << "sizeof(ssize_t) = " << sizeof(ssize_t) << endl;
    oss << "sizeof(off_t) = " << sizeof(off_t) << endl;
    oss << "sizeof(ptrdiff_t) = " << sizeof(ptrdiff_t) << endl;
    oss << "sizeof(intptr_t) = " << sizeof(intptr_t) << endl;
    oss << "sizeof(uintptr_t) = " << sizeof(uintptr_t) << endl;
    oss << "sizeof(intmax_t) = " << sizeof(intmax_t) << endl;
    oss << "sizeof(uintmax_t) = " << sizeof(uintmax_t) << endl;
    oss << "local machine layout :" << testLocalLayout() << endl;
    string oss_str = oss.str();
    AppendFile(SIZE_OF_TYPE, oss_str);
}

void TestReadLines()
{
    ReadForStdout(INPUT_FILE);
}

void TestCinAteN()
{
    string str3;
    cin >> str3;
    cout << str3 << endl;
    getline(cin, str3);
    cout << str3 << endl;
}

void TestOSS()
{
    string _str_;
    getline(cin, _str_);
    PrintOSS(_str_);
}

int Capitals(int const &case_num)
{
    auto capitalsPtr = unique_ptr<map<string,string>>( new map<string, string> );
    auto capitals = *(capitalsPtr.get());
    GetWorldCapitals(WORLD_CAPITALS, capitals);
    string country;

    switch( case_num )
    {
        case 'w':
    fprintf(stdout, "%ld\n", sizeof('-'));
    break;
        case 'p':
    PrintWorldCapitals(capitals, 1 << 3);
    break;
        case 'g':
    
    while(getline(cin, country))
    {   
        if (!country.compare("q") ||
            !country.compare("quit") ||
            !country.compare("exit") )
            break;
        country = replaceAllWhiteSpace(country);
        cout << "Country: " << RED_STR(country) 
                << "'s Capital: " << RED_STR(capitals[country]) << endl;
    }
    break;
        default:
    return 1;
    }
    return 0;
}


/*
Model 	Layout	int	    long	pointer	    arch:OS
LP32	2/4/4	2B	    4B	    4B	        Win16
ILP32	4/4/4	4B	    4B	    4B	        Win32 API/Unix/Linux/MacOS
LLP64	4/4/8	4B	    4B	    8B	        x86_64/arm64:Win32 API
LP64	4/8/8	4B	    8B	    8B	        Unix/Linux/MacOS
ILP64	8/8/8	8B	    8B	    8B	        very rare(:UNICOS on Cray)
*/
string testLocalLayout()
{
    size_t _int_ = sizeof(int);
    size_t _long_ = sizeof(long);
    size_t _pointer_ = sizeof(NULL);

    if (_int_ == 2 && _long_ == 4 && _pointer_ == 4)
    {
        return "Model[LP32], arch:OS[Win16]";
    }
    else if (_int_ == 4 && _long_ == 4 && _pointer_ == 4)
    {
        return "Model[ILP32], arch:OS[Win32 API/Unix/Linux/MacOS]";
    }
    else if (_int_ == 4 && _long_ == 4 && _pointer_ == 8)
    {
        return "Model[LLP64], arch:OS[x86_64/arm64:Win32 API]";
    }
    else if (_int_ == 4 && _long_ == 8 && _pointer_ == 8)
    {
        return "Model[LP64], arch:OS[Unix/Linux/MacOS]";
    }
    else if (_int_ == 8 && _long_ == 8 && _pointer_ == 8)
    {
        return "Model[ILP64], arch:OS[very rare(:UNICOS on Cray)]";
    }
    else
    {
        return "Model[unknown], arch:OS[unknown]";
    }
    
}


