# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfoughal <nfoughal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/28 23:50:43 by nfoughal          #+#    #+#              #
#    Updated: 2023/02/02 21:05:23 by nfoughal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC  =  before_sorting.c fill_stack.c get_index.c just_push.c \
		lis.c main.c moves_count.c operations.c utils.c re_f_moves_count.c \
		op.c opr.c

SRCBONUS =  bonus/check_sorting_bonus.c bonus/checker_bonus.c bonus/fill_stack_bonus.c \
			bonus/operations_bonus.c bonus/get_next_line/get_next_line_bonus.c \
			bonus/get_next_line/get_next_line_utils_bonus.c bonus/utils_bonus.c \
			bonus/op_bonus.c bonus/opr_bonus.c

OBJ = $(SRC:.c=.o)
OBJBONUS = $(SRCBONUS:.c=.o)

all: $(NAME)

${NAME} : ${OBJ} 
	@${MAKE} -C ./libft
	@${CC} ${CFLAGS} ${OBJ} ./libft/libft.a -o ${NAME}
	
bonus: $(OBJBONUS)
	@${MAKE} -C bonus/libft
	@${CC} ${CFLAGS} $(OBJBONUS) ./libft/libft.a -o checker	

%.o:%.c push_swap.h bonus/checker.h
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	@rm -f $(OBJ) $(OBJBONUS)
	@rm -f checker
	${MAKE} clean -C ./libft
	${MAKE} clean -C bonus/libft

fclean: clean
	@rm -f $(NAME)
	@rm -f checker
	${MAKE} fclean -C ./libft
	${MAKE} fclean -C bonus/libft

re: fclean all

.PHONY: all clean fclean re bonus