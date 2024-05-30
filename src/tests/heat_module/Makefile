# omp_args 	= $(omp_include) $(omp_lib) -lomp
# omp_include = -I/opt/homebrew/opt/libomp/include
# omp_lib 	= -L/opt/homebrew/opt/libomp/lib
# comp_args = -std=c++17 -O3 $(omp_args) -static 

fake_man: fake_man.c
	gcc -std=gnu99 -pedantic -o $@ $<
	# ./$@

seg_tree_c: seg_tree.c
	gcc -std=gnu99 -O0 -o $@ $< -g

seg_tree_cpp: seg_tree.cpp
	g++ -std=c++11 -O0 -o $@ $< -g

seg_tree_cc: seg_tree.cc
	g++ -std=c++20 -O0 -o $@ $< -g

p_dfs_map: main
	python3 gen_map.py
	./main

p_dfs: p_dfs.cc
	g++ -std=c++20 -O0 -o $@ $< -g

clean:
	rm -f *.exe