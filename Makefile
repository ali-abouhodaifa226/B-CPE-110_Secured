##
## EPITECH PROJECT, 2023
## Default Makefile
## File description:
## Makefile
##

SRC =	hash.c \
		hashtable.c \
		insert.c \
		search.c \
		delete.c \
		dump.c \
		replace.c \

OBJ =	$(SRC:.c=.o)

NAME =  libhashtable.a

CFLAGS = -Wall -Wextra

all: 	$(NAME)

$(NAME): 	$(OBJ)
	ar rc $(NAME) $(OBJ)

test:
	gcc $(NAME) main.c -o test -L. -lhashtable

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: 	fclean all

auteur:
	echo $(USER) > auteur
