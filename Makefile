export

# compile options
cxxc 	 = g++
cxx_args = -Wall -pedantic -O0 -std=c++20
c_args 	 = -Wall -pedantic -O0 -std=gnu99

# compie options - args
debug_mode = -g -DDEBUG_MODE=1
# debug_gdb = echo "gdb -q -tui main"
# debug_lldb = echo "lldb main" && echo "gui"
cxx_args += $(debug_mode)

# target command
build_dir 	= build
install_dir = bin
src_dir 	= src
include_dir = include

_exe = $(install_dir)/main

# conflict
# all: build main install

build_only: _ass _oop _stl _tes _sim _sel
	rm -rf $(build_dir) && mkdir -p $(build_dir)
	cp $(_obj_list) $(build_dir)

build: $(build_only)
	rm -rf $(build_dir) && mkdir -p $(build_dir)
	mv $(_obj_list) $(build_dir)

install: main
	rm -rf $(install_dir) && mkdir -p $(install_dir)
	mv -f $< $(_exe)

uninstall: $(_exe)
	mv $< main

# 1. link all object files to generate exe file
main: $(src_dir)/main.o $(build_dir)/*.o
	$(cxxc) $(cxx_args) -o $@ $^ $(leveldb_args)

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

# arch, os, cc
_ARCH = $(shell uname -m)
_OS   = $(shell uname -s)
_CC   = $(shell $(cxxc) --version | head -n 1)

_OSVER := $(_OS)
ifeq ($(findstring NT,$(_OS)),NT)
_OSVER = WinNT
endif

_CCVER := $(cxxc)
ifeq ($(findstring clang,$(_CC)),clang)
_CCVER = clang
endif
ifeq ($(findstring gcc,$(_CC)),gcc)
_CCVER = gcc
endif

cxx_args += -D_ARCH=$(_ARCH)
cxx_args += -D_OSVER=$(_OSVER)
cxx_args += -D_CCVER=$(_CCVER)

# info env
$(info cpu_arch: $(_ARCH) os_cat: $(_OSVER) cc_ver: $(_CCVER))

# ignore some warnings
ignore_warns :=
ifeq ($(findstring clang,$(_CCVER)),clang)
ignore_warns += -Wno-unused-command-line-argument
ignore_warns += -Wno-mismatched-tags
ignore_warns += -Wno-unused-local-typedef
endif
ifeq ($(findstring g++,$(_CCVER)),g++)
ignore_warns += -Wno-unused-local-typedef
endif
cxx_args += $(ignore_warns)

# target *.o dirs
_ass_dir = $(src_dir)/assignments
_oop_dir = $(src_dir)/oop_templates
_stl_dir = $(src_dir)/stl_components
_tes_dir = $(src_dir)/tests
_sim_dir = $(src_dir)/simds
_sel_dir = $(src_dir)/self_lists

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
	$(cxxc) -c $(cxx_args) -o $@ $<

%.o: %.cc
	$(cxxc) -c $(cxx_args) -o $@ $<

%.o: %.c
	$(CC) -c $(c_args) -o $@ $<

# compile args not in arm
ifeq ($(_ARCH),x86_64)
avx_args = -mavx
else
avx_args = # -mavx
$(info cpu_arch $(_ARCH) donot support avx)
endif

# compile when global lib: leveldb snappy are installed
leveldb_prefix		= /usr/local
leveldb_include_dir = $(leveldb_prefix)/include/leveldb
leveldb_lib_dir		= $(leveldb_prefix)/lib
include_leveldb		= -I$(leveldb_include_dir)
link_leveldb		= -L$(leveldb_lib_dir) -lleveldb
link_snappy			= -L$(leveldb_prefix)/lib -lsnappy -lpthread
leveldb_args		=
# if include_dir, if libleveldb.a, if libsnappy.a
ifneq ($(wildcard $(leveldb_include_dir)),)
leveldb_args 		+= $(include_leveldb)
endif
ifneq ($(wildcard $(leveldb_lib_dir)/libleveldb.a),)
leveldb_args 		+= $(link_leveldb)
endif
ifneq ($(wildcard $(leveldb_lib_dir)/libsnappy.a),)
leveldb_args 		+= $(link_snappy)
endif
ifneq ($(leveldb_args),)
cxx_args += -D_LDB_=1
else
$(info leveldb was not installed)
cxx_args += -D_LDB_=0
endif

# heat fast build & run
heat: 
	cd src/tests/heat_module && MAKE && ./main