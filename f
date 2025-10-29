==195277== Memcheck, a memory error detector
==195277== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==195277== Using Valgrind-3.25.1 and LibVEX; rerun with -h for copyright info
==195277== Command: ./test/test_exe
==195277== 
len 0 pos 0
len 1 pos 1
len 2 pos 2
len 3 pos 3
len 4 pos 4
erasing at 3 len 5
len 4 pos 2
erasing at 3 len 5
erasing at 2 len 4
erasing at 1 len 3
len 2 pos 0
len 3 pos 1
len 4 pos 2
len 5 pos 3
==195277== 
==195277== Process terminating with default action of signal 2 (SIGINT)
==195277==    at 0x49241CE: __internal_syscall_cancel (cancellation.c:64)
==195277==    by 0x49241F3: __syscall_cancel (cancellation.c:75)
==195277==    by 0x499EA6D: read (read.c:26)
==195277==    by 0x4001586: readline (readline.c:17)
==195277==    by 0x400126C: main (in /home/asqel/GitHub/my-readline/test/test_exe)
==195277== 
==195277== HEAP SUMMARY:
==195277==     in use at exit: 1,024 bytes in 1 blocks
==195277==   total heap usage: 1 allocs, 0 frees, 1,024 bytes allocated
==195277== 
==195277== LEAK SUMMARY:
==195277==    definitely lost: 0 bytes in 0 blocks
==195277==    indirectly lost: 0 bytes in 0 blocks
==195277==      possibly lost: 0 bytes in 0 blocks
==195277==    still reachable: 1,024 bytes in 1 blocks
==195277==         suppressed: 0 bytes in 0 blocks
==195277== Rerun with --leak-check=full to see details of leaked memory
==195277== 
==195277== For lists of detected and suppressed errors, rerun with: -s
==195277== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
