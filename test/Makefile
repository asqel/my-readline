SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

CC = gcc
LD = gcc

CFLAGS = -Wall -Wextra -I../include
LDFLAGS = 

NAME = test_exe

all: $(NAME)

$(NAME): $(OBJ)
	$(LD) $(LDFLAGS) $^ ../libreadline.a -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

test: all
	./$(NAME)
	reset

.PHONY: re fclean clean all test

