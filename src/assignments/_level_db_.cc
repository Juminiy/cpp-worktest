#include "../../include/_level_db_.hpp"

#ifdef _LDB_
#include "leveldb/db.h"
#endif

#if defined(LEVELDB_EXPORT)

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
            PRINTLN(_val);
        _COLOR_RECOVER;
    } else if (_lstat.IsNotFound())
    {
        _COLOR_START(_COLOR_YELLOW);
            PRINTLN(_lstat.ToString() << _ldb_key);
        _COLOR_RECOVER;
    } else 
    {
        _COLOR_START(_COLOR_RED);
            PRINTLN(_lstat.ToString() 
                    << " when Get key: " 
                    << _ldb_key);
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

    auto _lstat = 
        _ldb->Put(leveldb::WriteOptions(), _ldb_key, _ldb_val);
    if(_lstat.ok())
    {
        _COLOR_START(_COLOR_GREEN);
            PRINTLN("put <" 
                    << _ldb_key 
                    << ", "
                    << _ldb_val 
                    << "> ok");
        _COLOR_RECOVER;
    } else 
    {
        _COLOR_START(_COLOR_RED);
            PRINTLN(_lstat.ToString() 
                    << " when Put key: " 
                    << _ldb_key);
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
            PRINTLN("delete " << _ldb_key << " ok");
        _COLOR_RECOVER;
    } else 
    {
        _COLOR_START(_COLOR_RED);
            PRINTLN(_lstat.ToString() 
                    << " when Del key: " 
                    << _ldb_key);
        _COLOR_RECOVER;
    }

    __LDB_CLOS__(_ldb);
}

// leveldb argopt
// char * const ldb_get = "get";
// char * const ldb_put = "put";
// char * const ldb_del = "del";
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
#define LUB -1
        NULL
};
char *ldb_opts, *ldb_vals;

// usage:
// ./main -l get,key=foo
// ./main -l put,key=foo,val=bar
// ./main -l del,key=foo
void leveldb_cmd()
{
    ldb_opts = optarg;
    int         _lmod;
    std::string _lkey;
    std::string _lval;
    while(*ldb_opts)
    {
        switch (getsubopt(&ldb_opts, ldb_case, &ldb_vals))
        {
        case GET:
            _lmod = GET;
            break;
        case PUT:
            _lmod = PUT;
            break;
        case DEL:
            _lmod = DEL;
            break;
        case KEY:
            _lkey = ldb_vals;
            break;
        case VAL:
            _lval = ldb_vals;
            break;
        case LUB:
        default:
            break;
        }
    }
    switch (_lmod)
    {
    case GET:
        _LDB_GET(std::string(_lkey));
        break;
    case PUT:
        _LDB_PUT(std::string(_lkey),
                    std::string(_lval));
        break;
    case DEL:
        _LDB_DEL(std::string(_lkey));
        break;
    default:
        break;
    }
}

#endif 