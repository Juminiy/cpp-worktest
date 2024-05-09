# Basic C/C++
1. How to run
   ```bash
   make all -j10
   ./main -v
   ```
2. Content 
   1. GNU C99.
   2. Modern CXX11~CXX20.
   3. Trails.
3. Makefile.
   1. M1 (Darwin Chisato-MacBook-Pro.local 23.4.0 Darwin Kernel Version 23.4.0: Fri Mar 15 00:10:42 PDT 2024; root:xnu-10063.101.17~1/RELEASE_ARM64_T6000 arm64, Apple clang version 15.0.0 (clang-1500.3.9.4))
      ```bash
      time make -j8
      # make -j8  10.06s user 1.21s system 567% cpu 1.985 total
      # 2024.4.28
      # make -j10  21.30s user 2.19s system 799% cpu 2.938 total
      # make main  0.63s user 0.10s system 91% cpu 0.795 total
      ```
      ```bash
      # CPU loops per second 
      # clang -O0
      Alan::__loops_per_sec_(1) = 24434032
      Alan::__loops_per_sec_(2) = 49660779
      Alan::__loops_per_sec_(3) = 74456481
      # clang -O3
      Alan::__loops_per_sec_(1) = 60274124
      Alan::__loops_per_sec_(2) = 122208869
      Alan::__loops_per_sec_(3) = 183411630
      ```
   1. Win64 (MINGW64_NT-10.0-19045 DESKTOP-QRS5IC2 3.4.10.x86_64 2024-03-24 15:09 UTC x86_64 Msys, clang version 11.0.0)
      ```bash
      time make -j8
      # real    0m8.094s
      # user    0m42.116s
      # sys     0m8.360s
      ```
      ```bash
      # CPU loops per second
      # gcc -O0
      Alan::__loops_per_sec_(1) = 14481591
      Alan::__loops_per_sec_(2) = 28735669
      Alan::__loops_per_sec_(3) = 44418881
      # gcc -O2
      Alan::__loops_per_sec_(1) = 17001525
      Alan::__loops_per_sec_(2) = 39107601
      Alan::__loops_per_sec_(3) = 58595730
      ```
   2. Server (Linux VM-0-16-ubuntu 5.15.0-72-generic #79-Ubuntu SMP Wed Apr 19 08:22:18 UTC 2023     x86_64 x86_64 x86_64 GNU/Linux, Ubuntu clang version 14.0.0-1ubuntu1.1)
      ```bash
      time make -j8
      # real    0m9.438s
      # user    0m30.923s
      # sys     0m2.909s
      ```
      ```bash
      # CPU loops per second
      # gcc -O0
      Alan::__loops_per_sec_(1) = 18292420
      Alan::__loops_per_sec_(2) = 36579376
      Alan::__loops_per_sec_(3) = 52902849
      # gcc -O2
      Alan::__loops_per_sec_(1) = 35623114
      Alan::__loops_per_sec_(2) = 70066823
      Alan::__loops_per_sec_(3) = 10802244
      ```