cxxc = g++
cxx_args= -Wall -pedantic -O0 -std=c++17 -g
c_args = -Wall -pedantic -O0 -std=gnu99 -g
objects += _stream_.o
objects += _test_func_.o
objects += _seq_container_.o
objects += _ai_snake_game_.o
objects += _asso_container_.o
objects += _dfa_.o
objects += _nfa_.o

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

# not finished
# 3. link main object file with dynamic linked library to generate exe file
main-dynamic: main.o libdynamic.so
	$(cxxc) $(cxx_args) -L. -ldynamic -o $@ $<

libdynamic.so: $(objects)
	$(cxxc) $(cxx_args) -shared -fPIC -o $@ $^

# compile by pattern matching
%.o: %.cpp
	$(cxxc) -c $(cxx_args) -o $@ $<

%.c.o: %.c
	$(CC) -c $(c_args) -o $@ $<

clean:
	rm -f $(objects) 
	rm -f *.o *.out *.a *.so 
	rm -rf *.dSYM/
	rm -f main main-static main-dynamic