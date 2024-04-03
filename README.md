# Basic C/C++
1. GNU C99.
2. Modern CXX11~CXX20.
3. Makefile.
   1. M1 (aarch64 Darwin MacOS clang15.0.0)
      ```bash
      time make -j8
      # make -j8  9.05s user 0.91s system 623% cpu 1.598 total
      ```
   2. Win64 (x86_64 Windows10, MINGW64_NT-10.0-19045 DESKTOP-QRS5IC2 3.4.10.x86_64 2024-03-24 15:09 UTC x86_64 Msys, clang version 11.0.0)
      ```bash
      time make -j8
      # real    0m8.094s
      # user    0m42.116s
      # sys     0m8.360s
      ```
   3. Server (Linux VM-0-16-ubuntu 5.15.0-72-generic #79-Ubuntu SMP Wed Apr 19 08:22:18 UTC 2023     x86_64 x86_64 x86_64 GNU/Linux, Ubuntu clang version 14.0.0-1ubuntu1.1)
      ```bash
      time make -j8
      # real    0m9.438s
      # user    0m30.923s
      # sys     0m2.909s
      ```