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
    __USE_NS__(Alan::LDB);
    __USE_NS__(Alan::Demos::Test::Func);

    int case_num = 0;
    while( (case_num = 
                getopt_long(argc, argv, short_opts, long_opts, NULL)
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
        TestAllHasArgv();
        break;

            case 'l':
        #if defined(LEVELDB_EXPORT)
            leveldb_cmd(); 
            // __LDB_CMD__
        #else 
            LDB_ERR_DETAIL;
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