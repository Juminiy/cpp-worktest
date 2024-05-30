_fn_c: _fn.c
	gcc -S -O0 $<
_fn_go: _fn.go
	go tool compile -S -N -l $< > $@.s