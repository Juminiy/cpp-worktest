#include "_i_lib_.hpp"
#include "_stream_.hpp"

#include <cassert>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <unistd.h>

#include <fstream>
#include <iostream>
#include <iomanip>
#include <memory>
#include <map>
#include <string>

#define INPUT_FILE "../test/static-file/input.txt"
#define OUTPUT_FILE "../test/static-file/output.txt"    
#define WORLD_CAPITALS "../test/static-file/world-capital.txt"

int main(int argc, char *argv[], char *envp[])
{

    cout << "Main Started" << endl;

    bool rwFile UNUSED = false;
    if ( argc >= 2)
    {   
        if (!strcmp(argv[1], "-rw"))
        {
            string fileContent;
            ReadFile(INPUT_FILE, fileContent);
            RewriteFile(OUTPUT_FILE, fileContent);
        } else if (!strcmp(argv[1], "-no"))
        {
            cout << true << ", " << false << "," << boolalpha << true << ", " << false << endl;
            fprintf(stdout, "%0d\n", true);
        } else if (!strcmp(argv[1], "-rw1"))
        {   
            ReadForStdout(INPUT_FILE);
        } else if (!strcmp(argv[1], "-rw2"))
        {   
            string str3;
            cin >> str3;
            cout << str3 << endl;
            getline(cin, str3);
            cout << str3 << endl;
        } else if (!strcmp(argv[1], "-cap"))
        {   
            if (argc >= 3)
            {   
                auto capitalsPtr = unique_ptr<map<string,string>>( new map<string, string> );
                auto capitals = *(capitalsPtr.get());
                GetWorldCapitals(WORLD_CAPITALS, capitals);

                if (!strcmp(argv[2], "-wchar")){
                    fprintf(stdout, "%ld\n", sizeof('-'));
                    goto ret0;
                } else if (!strcmp(argv[2], "-all"))
                {
                    PrintWorldCapitals(capitals, 5);
                } else if (!strcmp(argv[2], "-get"))
                {
                    string country;
                    while(getline(cin, country))
                    {   
                        if (!country.compare("q") ||
                            !country.compare("quit") ||
                            !country.compare("exit") )
                            goto ret0;
                        country = replaceAllWhiteSpace(country);
                        cout << "Country: " << RED_STR(country) 
                                << "'s Capital: " << RED_STR(capitals[country]) << endl;
                    }
                }
            }      
        } else if (!strcmp(argv[1], "-oss"))
        {
            string _str_;
            getline(cin, _str_);
            PrintOSS(_str_);
        } else 
        {
            fprintf(stdout, "Nothing args is matched\n");
        }
    }
ret0:
    return 0;
}