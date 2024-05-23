#include "../../include/_i_lib_.hpp"
#include "../../include/_level_db_.hpp"
#include "../../include/_stl_str_lib_.hpp"

// DEBUG_MODE
// #ifndef _LDB_
// #define _LDB_
// #endif 

#if _LDB_ != 0
#include "leveldb/db.h"
#endif

#if defined(LEVELDB_EXPORT)

__DEF_NS__(Alan::LDB)

void _LDB_GET
(const std::string &_ldb_key, 
const std::string &_db_file_path)
{
    __LDB_DECL___(_ldb, _db_file_path);

    std::string _val;
    auto _lstat = 
        _ldb->Get(leveldb::ReadOptions(), _ldb_key, &_val);
    if (_lstat.ok())
    {
        _COLOR_START(_COLOR_GREEN);
            PRINTLN( "[" << _val << "]");
        _COLOR_RECOVER;
    } else if (_lstat.IsNotFound())
    {
        _COLOR_START(_COLOR_YELLOW);
            PRINTLN(_lstat.ToString() 
                    << " [" << _ldb_key << "]");
        _COLOR_RECOVER;
    } else 
    {
        _COLOR_START(_COLOR_RED);
            PRINTLN(_lstat.ToString() 
                    << " when Get key: [" 
                    << _ldb_key << "]");
        _COLOR_RECOVER;
    }

    __LDB_CLOS__(_ldb);
}

void _LDB_PUT
(const std::string &_ldb_key, 
const std::string &_ldb_val,
const std::string &_db_file_path)
{
    __LDB_DECL___(_ldb, _db_file_path);

    auto _ldb_key_ok =
        _ldb_key.size() && 
        !std::all_of(_ldb_key.begin(), _ldb_key.end(),
                    Alan::_is_bs);
    leveldb::Status _lstat;
    if (_ldb_key_ok)
        _lstat = 
            _ldb->Put(leveldb::WriteOptions(), _ldb_key, _ldb_val);
    if( _ldb_key_ok && 
        _lstat.ok())
    {
        _COLOR_START(_COLOR_GREEN);
            PRINTLN("put <[" 
                    << _ldb_key 
                    << "], ["
                    << _ldb_val 
                    << "]> ok");
        _COLOR_RECOVER;
    } else 
    {
        _COLOR_START(_COLOR_RED);
            PRINTLN(_lstat.ToString() 
                    << " when Put key: [" 
                    << _ldb_key << "], size = "
                    << _ldb_key.size());
        _COLOR_RECOVER;
    }

    __LDB_CLOS__(_ldb);
}

void _LDB_DEL
(const std::string &_ldb_key,
const std::string &_db_file_path)
{
    __LDB_DECL___(_ldb, _db_file_path);

    auto _lstat = 
        _ldb->Delete(leveldb::WriteOptions(), _ldb_key);
    if(_lstat.ok())
    {
        _COLOR_START(_COLOR_GREEN);
            PRINTLN("delete [" << _ldb_key << "] ok");
        _COLOR_RECOVER;
    } else 
    {
        _COLOR_START(_COLOR_RED);
            PRINTLN(_lstat.ToString() 
                    << " when Del key: [" 
                    << _ldb_key << "]");
        _COLOR_RECOVER;
    }

    __LDB_CLOS__(_ldb);
}

void _LDB_KEYS(const std::string &_db_file_path)
{
    __LDB_DECL___(_ldb, _db_file_path);

    auto _ldb_it = 
        _ldb->NewIterator(leveldb::ReadOptions());
    for(_ldb_it->SeekToFirst();
        _ldb_it->Valid();
        _ldb_it->Next())
        _COLOR_START(_COLOR_GREEN),
            PRINT( "[" << _ldb_it->key().ToString() << "]"),
            PRINT(" "),
        _COLOR_RECOVER;
    PRINTLN("");

    if (auto _ldb_stat = _ldb_it->status();
        !_ldb_stat.ok())
        _COLOR_START(_COLOR_RED),
            PRINTLN(_ldb_stat.ToString() 
                    << " when iterate"),
        _COLOR_RECOVER;
    
    __LDB_CLOS__(_ldb);
}

// TODO: transaction write

// leveldb argopt
char * const ldb_case[] =
{
#define GET 0
    	(char* const)"get",
#define PUT 1
        (char* const)"put",
#define DEL 2
		(char* const)"del",
#define KEY 3
        (char* const)"key",
#define VAL 4
        (char* const)"val",
#define KEYS 5
        (char* const)"keys",
#define LUB -1
        NULL
};
char *ldb_opts, *ldb_vals;

// usage:
// ./main -l get,key=foo
// ./main -l put,key=foo,val=bar
// ./main -l del,key=foo
// ./main -l keys
void leveldb_cmd()
{
    ldb_opts = optarg;
    // _lmod must assgin an initial LUB
    int         _lmod = LUB;
    std::string _lkey("");
    std::string _lval("");
    #define OPT_LMOD(__opt__) \
            case __opt__: \
                _lmod = __opt__; \
                break
    #define OPT_LVVV(__opt__, __key_, __val_) \
            case __opt__: \
                __key_ = __val_; \
                break
    while(*ldb_opts)
    {
        switch (getsubopt(&ldb_opts, ldb_case, &ldb_vals))
        {
        OPT_LVVV(KEY, _lkey, ldb_vals);
        OPT_LVVV(VAL, _lval, ldb_vals);
        OPT_LMOD(GET);
        OPT_LMOD(PUT);
        OPT_LMOD(DEL);
        OPT_LMOD(KEYS);
        case LUB: default:
            break;
        }
    }
    #define LDB_FUNC(__mode_, ...) \
            case __mode_: \
            _LDB_##__mode_(__VA_ARGS__); \
            break
    switch (_lmod)
    {
    LDB_FUNC(GET, _lkey);
    LDB_FUNC(PUT, _lkey, _lval);
    LDB_FUNC(DEL, _lkey);
    LDB_FUNC(KEYS);
    default:
        break;
    }
}

__END_NS__

#endif 