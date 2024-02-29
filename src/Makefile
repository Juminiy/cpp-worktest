CC = g++
COMP_ARGS= -Wall -pedantic -O0 -std=c++17 -g 
DEBUG_PROM= echo "gdb -q -tui main" && echo "b main" && echo "run -n"

main: main.cpp _test_func_.o _stream_.o 
	$(CC) $(COMP_ARGS) -o $@ $^
	# $(DEBUG_PROM)

_stream_.o: _stream_.cpp _stream_.hpp _i_lib_.hpp
	$(CC) -c $(COMP_ARGS) -o $@ $<

_test_func_.o: _test_func_.cpp _test_func_.hpp _i_lib_.hpp
	$(CC) -c $(COMP_ARGS) -o $@ $<


debug_info: 
	$(DEBUG_PROM)

clean:
	rm -f *.o *.out
	rm -rf *.dSYM/
	rm -f main 