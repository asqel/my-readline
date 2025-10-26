SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)

CC = gcc
LD = gcc

CFLAGS = -Wall -Wextra -Iinclude -fPIC -g
LDFLAGS = -shared

NAME = libreadline
NAME_SO = $(NAME).so
NAME_A = $(NAME).a

all: $(NAME_SO) $(NAME_A)

$(NAME_SO): $(OBJ)
	$(LD) $(LDFLAGS) $^ -o $@

$(NAME_A): $(OBJ)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME_A) $(NAME_SO)

re: fclean all

test: all
	make -C test re
	valgrind ./test/test_exe 2> f

.PHONY: re fclean clean all test
