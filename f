==1971== Memcheck, a memory error detector
==1971== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==1971== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==1971== Command: ./test/test_exe
==1971== 
len 0 pos 0
len 1 pos 1
len 2 pos 2
len 3 pos 3
len 4 pos 4
len 5 pos 5
len 6 pos 6
len 7 pos 7
len 8 pos 8
len 9 pos 9
len 10 pos 10
len 11 pos 11
len 12 pos 12
len 13 pos 13
len 14 pos 14
len 15 pos 15
len 16 pos 16
len 17 pos 17
len 18 pos 18
len 19 pos 19
len 20 pos 20
len 21 pos 21
len 22 pos 22
len 23 pos 23
len 24 pos 24
len 25 pos 25
len 26 pos 26
len 27 pos 27
len 28 pos 28
len 29 pos 29
len 30 pos 30
==1971== 
==1971== Process terminating with default action of signal 2 (SIGINT)
==1971==    at 0x4980852: read (read.c:26)
==1971==    by 0x109583: readline (readline.c:17)
==1971==    by 0x10925A: main (in /home/asqel/Github/my-readline/test/test_exe)
==1971== 
==1971== HEAP SUMMARY:
==1971==     in use at exit: 1,024 bytes in 1 blocks
==1971==   total heap usage: 1 allocs, 0 frees, 1,024 bytes allocated
==1971== 
==1971== LEAK SUMMARY:
==1971==    definitely lost: 0 bytes in 0 blocks
==1971==    indirectly lost: 0 bytes in 0 blocks
==1971==      possibly lost: 0 bytes in 0 blocks
==1971==    still reachable: 1,024 bytes in 1 blocks
==1971==         suppressed: 0 bytes in 0 blocks
==1971== Rerun with --leak-check=full to see details of leaked memory
==1971== 
==1971== For lists of detected and suppressed errors, rerun with: -s
==1971== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
