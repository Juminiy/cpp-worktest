CC = g++
COMP_ARGS= -pedantic -std=c++17 -g 
DEBUG_PROM= echo "gdb -q -tui main" && echo "b main" && echo "run -n"

main: main.cpp _stream_.o
	$(CC) $(COMP_ARGS) -o $@ $^
	$(DEBUG_PROM)

_stream_.o: _stream_.cpp _stream_.hpp _i_lib_.hpp
	$(CC) -c $(COMP_ARGS) -o $@ $<


clean:
	rm -f *.o *.out
	rm -f main 