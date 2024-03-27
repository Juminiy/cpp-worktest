export

cxxc = g++
cxx_args= -Wall -pedantic -O0 -std=c++20 -g
c_args = -Wall -pedantic -O0 -std=gnu99 -g

debug_mode_print = -DDEBUG_MODE=1 
debug_gdb = echo "gdb -q -tui main"
debug_lldb = echo "lldb main" && echo "gui"

# leveldb
leveldb_prefix= /usr/local
include_leveldb= -I$(leveldb_prefix)/include/leveldb
link_leveldb= -L$(leveldb_prefix)/lib -lleveldb
il_ldb= $(include_leveldb) $(link_leveldb)

# search 
VPATH = $(src_dir):$(include_dir):$(build_dir):$(install_dir)
vpath main $(install_dir):$(build_dir)
vpath %.o $(build_dir)
vpath %.cc $(src_dir)
vpath %.h $(include_dir)
vpath %.hpp $(include_dir)

build_dir = build
install_dir = bin
src_dir = src
include_dir = include

_ass_dir= $(src_dir)/assignments
_oop_dir= $(src_dir)/oop_templates
_stl_dir= $(src_dir)/stl_components
_tes_dir= $(src_dir)/tests

_exe = $(install_dir)/main

# conflict
# all: build main install

build: _ass _oop _stl _tes
	rm -rf $(build_dir) && mkdir -p $(build_dir)
	mv $(_ass_dir)/*.o $(build_dir)
	mv $(_oop_dir)/*.o $(build_dir)
	mv $(_stl_dir)/*.o $(build_dir)
	mv $(_tes_dir)/*.o $(build_dir)

install: main
	rm -rf $(install_dir) && mkdir -p $(install_dir)
	mv -f $< $(_exe)

_ass: 
	$(MAKE) -C $(_ass_dir)
_oop:
	$(MAKE) -C $(_oop_dir)
_stl: 
	$(MAKE) -C $(_stl_dir)
_tes:
	$(MAKE) -C $(_tes_dir)


# 1. link all object files to generate exe file
main: $(src_dir)/main.o $(build_dir)/*.o
	$(cxxc) $(cxx_args) $(il_ldb) -o $@ $^

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

# compile in local dir
objs: $(patsubst %.cc,%.o,$(wildcard *.cc))

# compile by pattern matching
%.o: %.cpp
	$(cxxc) -c $(cxx_args) $(debug_mode_print) -o $@ $<

%.o: %.cc
	$(cxxc) -c $(cxx_args) $(debug_mode_print) -o $@ $<

%.o: %.c
	$(CC) -c $(c_args) $(debug_mode_print) -o $@ $<


clean:
	rm -rf $(install_dir)
	rm -rf $(build_dir)
	rm -f main $(src_dir)/*.o
	rm -f main-dynamic libdynamic.so
	rm -f main-static libstatic.a
	rm -rf *.dSYM/

clear: clean
	clear

.PHONY: all build install clean clear
