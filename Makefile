##
## EPITECH PROJECT, 2017
## makefile
## File description:
## makefile
##

SRC	=	main.c		\
		algo.c		\
		fct_base.c	\
		verify_special.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I include/

NAME	=	bsq

all:	$(NAME)

$(NAME):	$(OBJ)
	 gcc -o $(NAME) $(CFLAGS) $(OBJ)
clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f *~
	rm -f libmy.a

re:	fclean all
