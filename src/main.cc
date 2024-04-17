#include "../include/_i_lib_.hpp"

#include "../include/_test_func_.hpp"
#include "../include/_ai_snake_game_.hpp"
#include "../include/_level_db_.hpp"

#ifdef _LDB_
#include <leveldb/export.h>
#endif

#if (__CC_VER__ > 1)
    #include <getopt.h>
    #include <unistd.h>
#elif (__CC_VER__ == 1)
    #include <windows.h>
#endif
#include <cstdlib>



int main(int argc, char *argv[], char *envp[])
{
    int case_num = 0;

    while( (case_num = 
            getopt_long(argc, 
                        argv, 
                        short_opts, 
                        long_opts, 
                        NULL)
            ) >= 0)
        switch (case_num)
        {
            // compiler info
            case 'v':
        printf("Compiler info: %s\n", __VERSION__);
        break;

            // ai snake game
            case 'g':
        TestAISnakeGame();
        break;

            // none parameter (argv)
            case 'n':
        TestAll();
        break;

            case 'a':
        // TestAgainstVectorReverseWithNot();
        // TestVigenereEncrypt();
        // TestEmail();
        // TestNFA();
        Test_Palindrome();
        break;

            case 'l':
            
            #if defined(LEVELDB_EXPORT)
                leveldb_cmd(); 
                // __LDB_CMD__
            #else 
                _COLOR_START(_COLOR_RED);
                    ERRLN("leveldb has not found in dir: /usr/local");
                    _COLOR_START(_COLOR_PURPLE);
                    ERRLN("some step to solve: ");
                    ERRLN("1. disable this option in Makefile directly");
                    ERRLN("2. enable this option in Makefile");
                    ERRLN("(1). install leveldb from source code");
                    ERRLN("(2). change option 'leveldb_prefix' in Makefile");
                    ERRLN("(3). recompile with: make build && make clean && make -j8");
                _COLOR_RECOVER;
            #endif 
        break;

            default:
        OptUsageV2();
        exit(ARGUS_ERROR);
        break;

        }

    return 0;
}



CONSTRUCT GEN_FUNC_COPY
void call_main()
{   
    char *print_des = (char*)(malloc(37));
    snprintf(print_des, 
                39, 
                "Hi, Worktest, Compile time: %s\n\n", 
                __TIME__);

    PRINT(_WHITE(print_des));
}

DESTRUCT GEN_FUNC_COPY
void exit_main()
{   
    char *print_des = (char*)(malloc(34));
    snprintf(print_des, 
                37, 
                "\niH, Worktest, Exit time: %s\n", 
                __TIME__);
    // bug report: compile time also, 
    // wiil build a global variable to add 
    //          or other way to solve 

    PRINT(_WHITE(print_des));
}