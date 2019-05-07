# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/26 12:54:22 by lvan-vlo       #+#    #+#                 #
#    Updated: 2019/05/07 14:22:09 by lvan-vlo      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = lvan-vlo.filler

SRCS = main.c ft_set_strct.c ft_set_piece.c ft_mastermind.c check_move.c output.c

INC = filler.h

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	make -C libft/ re
	gcc -c $(SRCS)
	gcc -o $(NAME) $(FLAGS) *.o -I $(INC) -L./libft -lft

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME) filler.trace

test:
	./resources/filler_vm -f resources/maps/map02 -p1 ./$(NAME) -p2 ./resources/players/superjeannot.filler

re: fclean all