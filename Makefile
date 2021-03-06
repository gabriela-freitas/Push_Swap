# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gafreita <gafreita@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/19 22:23:09 by gafreita          #+#    #+#              #
#    Updated: 2022/07/23 17:28:56 by gafreita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	push_swap

# SRCS =	big_sort.c \
# 		new_lists.c \
# 		print_stuff.c \
# 		push.c \
# 		push_swap.c \
# 		reverse_rotate.c \
# 		rotate.c \
# 		small_sort.c \
# 		swap.c \
# 		utils_lists.c \
# 		utils_sort.c

SRCS =  utils/new_lists.c \
		sorting/big_sort.c \
		print_stuff.c \
		moves/push.c \
		push_swap.c \
		moves/reverse_rotate.c \
		moves/rotate.c \
		moves/swap.c \
		utils/utils_lists.c \
		utils/utils_sort.c \
		sorting/small_sort.c

OBJS =	$(SRCS:%.c=%.o)

CC = gcc -Wall -Wextra -Werror

INCLUDES = -Ilibft/ -I../Push_Swap

COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_GREEN=\033[0;32m
COLOUR_END=\033[0m

# ^ primeira dependencia
# @ nome da regra

$(NAME): $(OBJS) | libft
	@$(CC) $(^) -Llibft -lft -o $(@)
	@echo "$(COLOUR_GREEN)push_swap OK$(COLOUR_END)"

all: $(NAME)

%.o: %.c
	@$(CC) -g $(INCLUDES) -c $(^) -o $(@)

libft:
	@make -C libft/

clean:
	@make clean -C libft/
	@rm -f $(OBJS)

fclean: clean
	@make fclean -C libft/
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft
