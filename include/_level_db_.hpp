#pragma once
#ifndef _LEVEL_DB_HPP
#define _LEVEL_DB_HPP

#include "_i_lib_.hpp"

#if _LDB_ != 0
#include "leveldb/db.h"
#endif

#include <string>

// donot forget to delete _db_ptr
#define __LDB_DECL___(_db_ptr, _file_name) \
        leveldb::DB * _db_ptr; \
        do { \
        leveldb::Options _db_opts; \
        _db_opts.create_if_missing = true; \
        const std::string _db_fname(_file_name); \
        auto _db_stat = \
            leveldb::DB::Open(_db_opts, _db_fname, &_db_ptr); \
        assert(_db_stat.ok());\
        } while(0)

#define __LDB_CLOS__(_db_ptr) \
        delete _db_ptr

#define DEFAULT_DB /tmp/chisato_db

#define __LDB_CMD__ \
        ldb_opts = optarg; \
    while(*ldb_opts) \
    { \
        switch (getsubopt(&ldb_opts, ldb_case, &ldb_vals)) \
        { \
        case GET: \
            _LDB_GET(std::string(ldb_vals)); \
            break; \
        case PUT: \
            _LDB_PUT(std::string(ldb_vals), \
                    std::string(ldb_vals)); \
            break; \
        case DEL: \
            _LDB_DEL(std::string(ldb_vals)); \
            break; \
        default: \
            break; \
        } \
    }

__DEF_NS__(Alan::LDB)

void _LDB_GET
(const std::string &_ldb_key, 
const std::string &_db_file_path = __TOSTR__(DEFAULT_DB));

void _LDB_PUT
(const std::string &_ldb_key, 
const std::string &_ldb_val,
const std::string &_db_file_path = __TOSTR__(DEFAULT_DB));

void _LDB_DEL
(const std::string &_ldb_key,
const std::string &_db_file_path = __TOSTR__(DEFAULT_DB));

void _LDB_KEYS
(const std::string &_db_file_path = __TOSTR__(DEFAULT_DB));


// usage:
// ./main -l get key='key'
// ./main -l put key='key' val='val'
// ./main -l del key='key'
void leveldb_cmd();

#define LDB_ERR_DETAIL \
        _COLOR_START(_COLOR_RED); \
            ERRLN("leveldb has not found in dir: /usr/local"); \
            _COLOR_START(_COLOR_PURPLE); \
            ERRLN("some step to solve: "); \
            ERRLN("1. disable this option in Makefile directly"); \
            ERRLN("2. enable this option in Makefile"); \
            ERRLN("(1). install leveldb from source code"); \
            ERRLN("(2). change option 'leveldb_prefix' in Makefile"); \
            ERRLN("(3). recompile with: make build && make clean && make -j8"); \
        _COLOR_RECOVER

__END_NS__

#endif