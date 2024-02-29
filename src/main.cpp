#include "_i_lib_.hpp"
#include "_stream_.hpp"
#include "_test_func_.hpp"

#include <getopt.h>
#include <unistd.h>


int main(int argc, char *argv[], char *envp[])
{

    int case_num, prev_case_num;
    int err_code = 0;

    while( (case_num = getopt_long(argc, argv, short_opts.c_str(), long_opts, NULL)) >= 0)
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
        break;
            case '5':
        fprintf(stdout, "res: %lld\n", i64_qread());
        break;
            case '6':
        MultiTypesOSS("9527 8.8888888 Canada America c");
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