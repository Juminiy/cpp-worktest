# omp_args 	= $(omp_include) $(omp_lib) -lomp
# omp_include = -I/opt/homebrew/opt/libomp/include
# omp_lib 	= -L/opt/homebrew/opt/libomp/lib
# comp_args = -std=c++17 -O3 $(omp_args) -static 
test: main
	python3 gen_map.py
	./main

main: p_dfs.cc
	g++ -std=c++20 -O0 -o $@ $< -g

seg: seg_tree.cc
	g++ -std=c++20 -O0 -o $@ $< -g