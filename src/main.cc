#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <chrono>
#include <iomanip>

#include "../include/_i_lib_.hpp"

#if (__CC_VER__ > 1)
    #include <getopt.h>
    #include <unistd.h>
#elif (__CC_VER__ == 1)
    #include <windows.h>
#endif

#if _LDB_ != 0
#include <leveldb/export.h>
#endif

#include "../include/_ai_snake_game_.hpp"
#include "../include/_level_db_.hpp"

#include "../include/_test_func_.hpp"
#include "../include/_test_func_2.hpp"

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
            // env info
            case 'v':
        printf("Compile Time: %s %s\n", __DATE__, __TIME__);
        // TODO: logmore
        break;

            // ai snake game
            case 'g':
        TestAISnakeGame();
        break;

            // leveldb command
            case 'l':
        #if defined(LEVELDB_EXPORT)
            leveldb_cmd(); 
            // __LDB_CMD__
        #else 
            LDB_ERR_DETAIL;
        #endif 
        break;

            // none parameter ((argv))
            case 'n':
        TestNoArgs();
        break;

            // has parameter ((argv))
            case 'a':
        TestVaArgs();
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
    __log_time_now__(__now_time_t_);
    PRINTLN("Call Time: " << __now_time_t_);
}

DESTRUCT GEN_FUNC_COPY
void exit_main()
{   
    __log_time_now__(__now_time_t_);
    PRINTLN("Exit Time: " << __now_time_t_);
}