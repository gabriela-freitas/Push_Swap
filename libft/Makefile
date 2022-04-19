NAME = libft.a

SRCS_ALL =	$(wildcard *.c)

OBJS_ALL =	$(SRCS_ALL:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

COLOUR_GREEN=\033[0;32m
COLOUR_END=\033[0m

.c.o:
	@$(CC) -c $(CFLAGS) $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS_ALL)
	@ar rcs $(NAME) $(OBJS_ALL)
	@echo "$(COLOUR_GREEN)LIBFT OK$(COLOUR_END)"
# @mkdir -p obj
# @mv $(OBJS_ALL) obj


clean:
	@rm -f $(OBJS_ALL)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
