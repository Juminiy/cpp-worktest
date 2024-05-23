omp_args 	= $(omp_include) $(omp_lib) -lomp
omp_include = -I/opt/homebrew/opt/libomp/include
omp_lib 	= -L/opt/homebrew/opt/libomp/lib
comp_args = -std=c++17 -O3 $(omp_args) -static 
main: main.cc
	g++ -std=c++17 -o $@ $<
