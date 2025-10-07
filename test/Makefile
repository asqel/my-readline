SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

CC = gcc
LD = gcc

CFLAGS = -Wall -Wextra -I../include
LDFLAGS = 

NAME = test

all: $(NAME)

$(NAME): $(OBJ) ../libreadline.a
	$(LD) $(LDFLAGS) $^ ../libreadline.a -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

../libreadline.a:
	make -C ../

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean clean

.PHONY: re fclean clean all

