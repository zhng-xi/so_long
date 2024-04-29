NAME	= so_long
CFLAGS	= -Wall -Wextra -Werror -g -lmlx -lX11 -lXext
LIBFT	= cd libft
PRINTF	= cd ft_printf
SRCS	= so_long.c

OBJS		= $(SRCS:.c=.o)

$(NAME): $(OBJS)
			@$(LIBFT) && make all
			@$(PRINTF) && make all
			cc $(CFLAGS) $(SRCS) -o $(NAME) ft_printf/libftprintf.a libft/libft.a
			@echo "Have fun testing!"

all:	$(NAME)

clean:
			@$(LIBFT) && make clean
			@$(PRINTF) && make clean
			rm -f $(OBJS)
			@echo "Objectfiles were removed."

fclean:	clean
			@$(LIBFT) && make fclean
			@$(PRINTF) && make fclean
			rm -f $(NAME)
			@echo "Everything is clean now!"

re:		fclean all

.PHONY: all clean fclean re ft_printf libft
