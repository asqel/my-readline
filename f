==531991== Memcheck, a memory error detector
==531991== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==531991== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==531991== Command: ./test/test_exe
==531991== 
==531991== 
==531991== Process terminating with default action of signal 2 (SIGINT)
==531991==    at 0x498AA91: read (read.c:26)
==531991==    by 0x10968D: readline (readline.c:76)
==531991==    by 0x10928A: main (in /home/asqel/git/my-readline/test/test_exe)
==531991== 
==531991== HEAP SUMMARY:
==531991==     in use at exit: 0 bytes in 0 blocks
==531991==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==531991== 
==531991== All heap blocks were freed -- no leaks are possible
==531991== 
==531991== For lists of detected and suppressed errors, rerun with: -s
==531991== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
