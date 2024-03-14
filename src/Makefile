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

debug_mode_print = -DDEBUG_MODE=1 
debug_gdb = echo "gdb -q -tui main"
debug_lldb = echo "lldb main" && echo "gui"

# 1. link all object files to generate exe file
main: main.o $(objects)
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

%.c.o: %.c
	$(CC) -c $(c_args) -o $@ $<

clean:
	rm -f $(objects) 
	rm -f *.o *.out *.a *.so 
	rm -rf *.dSYM/
	rm -f main main-static main-dynamic