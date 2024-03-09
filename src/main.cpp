#include "_i_lib_.hpp"
#include "_stream_.hpp"
#include "_test_func_.hpp"
#include "_seq_container_.hpp"
#include "_ai_snake_game_.hpp"
#include "_asso_container_.hpp"
#include "_dfa_.hpp"

#include <getopt.h>
#include <unistd.h>
#include <cstdlib>


int main(int argc, char *argv[], char *envp[])
{
    int case_num, prev_case_num;
    int err_code = 0;
    int test_round = 0;

    gameT gmt = gameT();
    while( (case_num = 
                getopt_long(argc, 
                            argv, 
                            short_opts.c_str(), 
                            long_opts, 
                            NULL)
            ) >= 0)
        switch (case_num)
        {
            case 'w': case 'p': case 'g':
        prev_case_num = case_num;
        break;
            case 'c':
        err_code = Capitals(prev_case_num);
        break;
            case 'o':
        TestOSS();
        break;
            case 'd':
        DrawTriangle(opt_uint(optarg));
        break; 
            case 'm':
        test_round = opt_uint(optarg);
        TestInRange(test_round);
        break;
            case 'n':
        test_round = opt_uint(optarg);
        TestInRange(test_round);
        break;
            case '0':
        TestReadWriteFile();
        break;
            case '1':
        TestBoolAlpha();
        break;
            case '2':
        TestReadLines();
        break;
            case '3':
        TestCinAteN();  
        break;
            case '4':
        fprintf(stdout, "res: %llu\n", u64_qread());
        fprintf(stdout, "res: %lld\n", i64_qread());
        break;
            case '5':
        TestHasHexLetters_3_version_pat(1 << (rand() % 30) );
        break;
            case '6':
        MultiTypesOSS("9527 8.8888888 Canada America c");
            case '7':
        // Alan::TestBirthDayParadox();
        // Alan::TestUMap();
        // Alan::TestUSet();
        // Alan::TestIterator();
        // Alan::TestMapDiffer();
        // Alan::CountKeyWordsOccurences();
        // Alan::TestMultiContainer();
        // TestVectorFunctor();
        // TestVectorFunctor2();
        break;
            case 'v':
        printf("GCC info: %s\n", __VERSION__);
        break;
            case 't':
        // Alan::TestUMap();
        // TestVectorFunc3();
        // TestRingBuffer();
        // TestAgainstVectorReverseWithNot();
        // TestVigenereEncrypt();
        TestEmail();
        break;
        case 'y':
        gmt.init();
        gmt.simu();
        break;
            case 'h': case '?': 
        err_code = 2;
        break;
            default:
        err_code = 1;
        break;
        }

    if (err_code)
    {
        OptUsage();
        exit(err_code);
    }

    return 0;
}

CONSTRUCT
static void inline call_main()
{   
    char *print_des = (char*)(malloc(37));
    snprintf(print_des, 
                39, 
                "\nHi, Worktest, Compile time: %s\n", 
                __TIME__);

    PRINTLN(_GREEN(string(print_des)));
}

DESTRUCT
static void inline exit_main()
{   
    char *print_des = (char*)(malloc(34));
    snprintf(print_des, 
                36, 
                "\niH, Worktest, Exit time: %s", 
                __TIME__);

    PRINTLN(_GREEN(string(print_des)));
}