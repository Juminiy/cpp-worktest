#include "../include/_i_lib_.hpp"

#include "../include/_stream_.hpp"
#include "../include/_test_func_.hpp"
#include "../include/_seq_container_.hpp"
#include "../include/_ai_snake_game_.hpp"
#include "../include/_asso_container_.hpp"
#include "../include/_dfa_.hpp"
#include "../include/_nfa_.hpp"
#include "../include/_set_theory_.hpp"
#include "../include/_algo_.hpp"
#include "../include/_rand_lib_.hpp"
#include "../include/_func_.hpp"
#include "../include/_keno_game_.hpp"
#include "../include/_level_db_.hpp"


#include <getopt.h>
#include <unistd.h>
#include <cstdlib>



int main(int argc, char *argv[], char *envp[])
{
    int case_num = 0;

    while( (case_num = 
            getopt_long(argc, 
                        argv, 
                        short_opts.c_str(), 
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
        Alan::Test_Palindrome();
        break;

            case 'l':
            #include <leveldb/export.h>
            #if defined(LEVELDB_EXPORT)
                leveldb_cmd();
                // __LDB_CMD__
            #else 
                _COLOR_START(_COLOR_RED);
                    ERRLN("leveldb has not found in /usr/local");
                    ERRLN("or change option 'leveldb_prefix' in Makefile");
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



CONSTRUCT
static void inline call_main()
{   
    char *print_des = (char*)(malloc(37));
    snprintf(print_des, 
                39, 
                "Hi, Worktest, Compile time: %s\n\n", 
                __TIME__);

    PRINT(_WHITE(print_des));
}

DESTRUCT
static void inline exit_main()
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