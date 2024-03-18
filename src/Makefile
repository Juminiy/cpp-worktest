cxxc = g++
cxx_args= -Wall -pedantic -O0 -std=c++20 -g
c_args = -Wall -pedantic -O0 -std=gnu99 -g
objects += _stream_.o
objects += _test_func_.o
objects += _seq_container_.o
objects += _ai_snake_game_.o
objects += _asso_container_.o
objects += _dfa_.o
objects += _nfa_.o
objects += _set_theory_.o
objects += _algo_.o
objects += _rand_lib_.o

# chara dir
chara_dir = chara
chara_objects += $(chara_dir)/_chara_.o

# build 
build_dir = build
# install
install_dir = bin


debug_mode_print = -DDEBUG_MODE=1 
debug_gdb = echo "gdb -q -tui main"
debug_lldb = echo "lldb main" && echo "gui"


install: main build
	mv *.o ../$(build_dir)
	mv $(chara_dir)/*.o ../$(build_dir)
	mv $< ../$(install_dir)/$<

build: main
	rm -rf ../$(build_dir) && mkdir -p ../$(build_dir)
	rm -rf ../$(install_dir) && mkdir -p ../$(install_dir)

run: ../$(install_dir)/main
	./$< -7
	
# 1. link all object files to generate exe file
main: main.o $(objects) $(chara_objects)
	$(cxxc) $(cxx_args) -o $@ $^


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

# compile by pattern matching
%.o: %.cpp
	$(cxxc) -c $(cxx_args) $(debug_mode_print) -o $@ $<

%.o: %.cc
	$(cxxc) -c $(cxx_args) $(debug_mode_print) -o $@ $<

%.o: %.c
	$(CC) -c $(c_args) -o $@ $<

clean:
	rm -rf ../$(build_dir) ../$(install_dir)
	rm -f *.o *.out *.a *.so 
	rm -rf *.dSYM/
	rm -f main main-static main-dynamic