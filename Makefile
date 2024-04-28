export

# compile options
cxxc = g++
cxx_args= -Wall -pedantic -O0 $(ignore_warn) -std=c++20 -g
c_args = -Wall -pedantic -O0 -std=gnu99 -g

# TODO:
# if else judge compiler and os in makefile

# ignore some warnings
ignore_warn += -Wno-unused-command-line-argument
ignore_warn += -Wno-mismatched-tags
ignore_warn += -Wno-unused-local-typedef

# compie options - args
# comment -D_LDB_=1 when env not installed leveldb
debug_mode = -DDEBUG_MODE=1 #-D_LDB_=1
# debug_gdb = echo "gdb -q -tui main"
# debug_lldb = echo "lldb main" && echo "gui"

# target command
build_dir = build
install_dir = bin
src_dir = src
include_dir = include

_exe = $(install_dir)/main

# conflict
# all: build main install

build_only: _ass _oop _stl _tes _sim _sel
	rm -rf $(build_dir) && mkdir -p $(build_dir)
	cp $(_obj_list) $(build_dir)

build: $(build_only)
	mv $(_obj_list) $(build_dir)

install: main
	rm -rf $(install_dir) && mkdir -p $(install_dir)
	mv -f $< $(_exe)

uninstall: $(_exe)
	mv $< main

# 1. link all object files to generate exe file
main: $(src_dir)/main.o $(build_dir)/*.o
	$(cxxc) $(cxx_args) -o $@ $^ #$(il_ldb)
# comment $(il_ldb) when env not installed leveldb

# 2. link main object file with static linked library to generate exe file
main-static: main.o libstatic.a
	$(cxxc) $(cxx_args) -o $@ $< -L. -lstatic 

libstatic.a: $(objects)
	ar rcs $@ $^

# has not been avliable, donot know how to manage dylib
# 3. link main object file with dynamic linked library to generate exe file
main-dynamic: main.o libdynamic.so
	$(cxxc) $(cxx_args) -L. -ldynamic -o $@ $<

libdynamic.so: $(objects)
	$(cxxc) $(cxx_args) -shared -fPIC -o $@ $^

clean:
	rm -rf $(install_dir)
	rm -rf $(build_dir)
	rm -f main $(src_dir)/*.o
	rm -f main-dynamic libdynamic.so
	rm -f main-static libstatic.a
	rm -rf *.dSYM/

clear: clean
	clear

.PHONY: build_only build install uninstall clean clear #all

# target *.o dirs
_ass_dir= $(src_dir)/assignments
_oop_dir= $(src_dir)/oop_templates
_stl_dir= $(src_dir)/stl_components
_tes_dir= $(src_dir)/tests
_sim_dir= $(src_dir)/simds
_sel_dir= $(src_dir)/self_lists

_obj_list += $(_ass_dir)/*.o
_obj_list += $(_oop_dir)/*.o
_obj_list += $(_stl_dir)/*.o
_obj_list += $(_tes_dir)/*.o
_obj_list += $(_sim_dir)/*.o
_obj_list += $(_sel_dir)/*.o

# target *.o dirs
_ass: 
	$(MAKE) -C $(_ass_dir)
_oop:
	$(MAKE) -C $(_oop_dir)
_stl: 
	$(MAKE) -C $(_stl_dir)
_tes:
	$(MAKE) -C $(_tes_dir)
_sim:
	$(MAKE) -C $(_sim_dir)
_sel:
	$(MAKE) -C $(_sel_dir)

# search path
VPATH = $(src_dir):$(include_dir):$(build_dir):$(install_dir)
vpath main $(install_dir):$(build_dir)
vpath %.o $(build_dir)
vpath %.c $(src_dir)
vpath %.cc $(src_dir)
vpath %.cpp $(src_dir)
vpath %.h $(include_dir)
vpath %.hpp $(include_dir)

# compile template
# compile in local dir
objs: $(patsubst %.cc,%.o,$(wildcard *.cc))

# compile by pattern matching in local dir
%.o: %.cpp
	$(cxxc) -c $(cxx_args) $(debug_mode) -o $@ $<

%.o: %.cc
	$(cxxc) -c $(cxx_args) $(debug_mode) -o $@ $<

%.o: %.c
	$(CC) -c $(c_args) $(debug_mode) -o $@ $<

# compile args not in arm
# if else judge CPU info
avx_args = # -mavx

# compile when global lib: leveldb snappy are installed
leveldb_prefix= /usr/local
include_leveldb= -I$(leveldb_prefix)/include/leveldb
link_leveldb= -L$(leveldb_prefix)/lib -lleveldb
link_snappy= -L$(leveldb_prefix)/lib -lsnappy -lpthread
il_ldb= $(include_leveldb) $(link_leveldb) $(link_snappy)