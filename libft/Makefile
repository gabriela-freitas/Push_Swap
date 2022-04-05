NAME = libft.a

SRCS_ALL =	$(wildcard *.c)


OBJS_ALL =	$(SRCS_ALL:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

.c.o:
	$(CC) -c $(CFLAGS) $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS_ALL)
	@ar rcs $(NAME) $(OBJS_ALL)
	# @mkdir -p obj
	# @mv $(OBJS_ALL) obj


clean:
	@rm -f $(OBJS_ALL)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
