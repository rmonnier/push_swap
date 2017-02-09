# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 10:17:46 by rmonnier          #+#    #+#              #
#    Updated: 2016/12/05 15:22:47 by rmonnier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_NAME		=		ft_printf.c\
SRCS_PATH		=		srcs/
SRCS			=		$(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJ_NAME		=		$(SRCS_NAME:.c=.o)
OBJ_PATH		=		obj/
OBJ				=		$(addprefix $(OBJ_PATH), $(OBJ_NAME))
NAME_1			=		checker
NAME_2			=		push_swap
FLAG			=		-Wall -Werror -Wextra
INC				=		./includes/


all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	gcc $(FLAGS) -I $(INC) $< -o $@

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p obj
	gcc -c $(FLAGS) -I $(INC) $< -o $@

clean:
	make -C libft/ fclean
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
