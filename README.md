# Basic C/C++
1. GNU C99.
2. Modern CXX11~CXX20.
3. Makefile.
   1. M1 (aarch64 Darwin)
      ```bash
      time make -j8
      # make -j8  9.05s user 0.91s system 623% cpu 1.598 total
      ```
   2. Win64 (x86_64 Windows10)
      ```bash
      time make -j8
      # stats
      # real    0m6.834s
      # user    0m36.400s
      # sys     0m5.808s
      ```