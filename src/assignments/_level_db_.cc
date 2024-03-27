#include "../../include/_level_db_.hpp"

#include "leveldb/db.h"

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
            PRINTLN(_lstat.ToString() << " with key" << _ldb_key);
        _COLOR_RECOVER;
    }

    delete _ldb;
}

void _LDB_PUT
(const std::string &_ldb_key, 
const std::string &_ldb_val,
const std::string &_db_file_path)
{
    
}

void _LDB_DEL
(const std::string &_ldb_key,
const std::string &_db_file_path)
{

}