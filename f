src/readline.c: In function ‘readline’:
src/readline.c:32:41: warning: comparison of integer expressions of different signedness: ‘int’ and ‘size_t’ {aka ‘long unsigned int’} [-Wsign-compare]
   32 |                                 if (pos < buffer.len) {
      |                                         ^
src/readline.c:45:55: warning: format ‘%d’ expects argument of type ‘int’, but argument 3 has type ‘size_t’ {aka ‘long unsigned int’} [-Wformat=]
   45 |                                 fprintf(stderr, "len %d pos %d\n", buffer.len, pos);
      |                                                      ~^            ~~~~~~~~~~
      |                                                       |                  |
      |                                                       int                size_t {aka long unsigned int}
      |                                                      %ld
src/readline.c:49:63: warning: format ‘%d’ expects argument of type ‘int’, but argument 4 has type ‘size_t’ {aka ‘long unsigned int’} [-Wformat=]
   49 |                                 fprintf(stderr, "pos %d, len %d\n", pos, buffer.len);
      |                                                              ~^          ~~~~~~~~~~
      |                                                               |                |
      |                                                               int              size_t {aka long unsigned int}
      |                                                              %ld
src/readline.c:52:51: warning: comparison of integer expressions of different signedness: ‘int’ and ‘size_t’ {aka ‘long unsigned int’} [-Wsign-compare]
   52 |                                 for (int i = 0; i < buffer.len - pos + 1; i++)
      |                                                   ^
src/readline.c:58:40: warning: comparison of integer expressions of different signedness: ‘size_t’ {aka ‘long unsigned int’} and ‘int’ [-Wsign-compare]
   58 |                         if (buffer.len > pos)
      |                                        ^
src/readline.c:59:51: warning: comparison of integer expressions of different signedness: ‘int’ and ‘size_t’ {aka ‘long unsigned int’} [-Wsign-compare]
   59 |                                 for (int i = 0; i < buffer.len - pos; i++)
      |                                                   ^
src/readline.c:11:15: warning: unused variable ‘input’ [-Wunused-variable]
   11 |         char *input = NULL;
      |               ^~~~~
src/readline.c:10:16: warning: unused variable ‘input_len’ [-Wunused-variable]
   10 |         size_t input_len = 0;
      |                ^~~~~~~~~
src/readline.c:9:16: warning: unused variable ‘input_alloc_len’ [-Wunused-variable]
    9 |         size_t input_alloc_len = 0;
      |                ^~~~~~~~~~~~~~~
src/readline.c:8:22: warning: unused parameter ‘prompt’ [-Wunused-parameter]
    8 | char *readline(char *prompt) {
      |                ~~~~~~^~~~~~
len 0 pos 0
len 1 pos 1
len 2 pos 2
len 3 pos 3
len 4 pos 4
pos 5, len 5
make[1]: *** [Makefile:29: test] Interrupt
make: *** [Makefile:34: test] Interrupt
