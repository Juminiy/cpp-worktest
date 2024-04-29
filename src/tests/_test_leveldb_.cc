#include "../../include/_i_lib_.hpp"

#include "../../include/_test_func_.hpp"

#include "../../include/_level_db_.hpp"

#if _LDB_ != 0
#include "leveldb/db.h"
#endif

#if defined(LEVELDB_EXPORT)

#include <cassert>

__DEF_NS__(Alan::Demos::Test::Func)

void TestLevelDB()
{
    leveldb::DB *l_db;
    leveldb::Options l_opts;
    l_opts.create_if_missing = true;
    const std::string l_db_file(__TOSTR__(DEFAULT_DB));
    auto l_sta = 
        leveldb::DB::Open(l_opts,l_db_file, &l_db);
    assert(l_sta.ok());

    l_sta = 
        l_db->Put(leveldb::WriteOptions(), 
                "chisato_love", "lyy");
    if (l_sta.ok())
        PRINTLN(l_sta.ToString());
    else 
        ERRLN(l_sta.ToString());
    // std::string _val;
    // l_sta = l_db->Get(leveldb::ReadOptions(), "chisato_love", &_val);
    // if (l_sta.ok())
    // {
    //     if (l_sta.IsNotFound())
    //     {
    //         _COLOR_START(_COLOR_YELLOW);
    //             PRINTLN("not found key 'k1'");
    //         _COLOR_RECOVER;
    //     } else 
    //     {
    //         _COLOR_START(_COLOR_GREEN);
    //             PRINTLN("key for 'k1' = "<< _val);
    //         _COLOR_RECOVER;
    //     }
    // } else 
    // {
    //     _COLOR_START(_COLOR_YELLOW);
    //         PRINTLN(l_sta.ToString());
    //     _COLOR_RECOVER;
    // }

    delete l_db;
}

__END_NS__

#endif  