##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##

NAME	=	main

$(NAME):
		@make -s re -C asm
		@make -s re -C corewar
		@make -s clean

all:	$(NAME)

clean:
		@make -s clean -C asm
		@make -s clean -C corewar

fclean:	clean
		@make -s fclean -C asm
		@make -s fclean -C corewar

re:    fclean all
