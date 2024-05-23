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