# compile in local dir
objs: $(patsubst %.cc,%.o,$(wildcard *.cc))

# compile by pattern matching
%.o: %.cpp
	$(cxxc) -c $(cxx_args) $(avx_args) $(debug_mode_print) -o $@ $<

%.o: %.cc
	$(cxxc) -c $(cxx_args) $(avx_args) $(debug_mode_print) -o $@ $<

%.o: %.c
	$(CC) -c $(c_args) $(avx_args) $(debug_mode_print) -o $@ $<