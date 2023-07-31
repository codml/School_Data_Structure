CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lft -L./libft
NAME = push_swap
BONUS = checker
LIBFT = libft/libft.a
SRCS =	ft_atoi_error.c \
		parsing.c \
		cmd_push.c \
		cmd_rotate.c \
		cmd_rrotate.c \
		cmd_swap.c \
		cmd_tool.c \
		set_table.c
SRCS_MANDATORY = cmd_print.c \
				 quick_sort_pivot.c \
				 quick_sort_sort.c \
				 quick_sort.c \
				 mandatory.c
SRCS_BONUS = checker_bonus.c
OBJS = $(SRCS:.c=.o)
OBJS_MANDATORY = $(SRCS_MANDATORY:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS) $(OBJS_MANDATORY)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME) $(OBJS) $(OBJS_MANDATORY)

$(LIBFT) : 
	cd libft && $(MAKE)

bonus : all make_bonus

make_bonus : $(BONUS)

$(BONUS) : $(LIBFT) $(OBJS) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(BONUS) $(OBJS) $(OBJS_BONUS)

clean:
	rm -f $(OBJS) $(OBJS_MANDATORY) $(OBJS_BONUS) $(LIBFT)

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS)

re: fclean
	$(MAKE) all

.PHONY : all bonus make_bonus clean fclean re
.NOTPARARREL : all bonus clean fclean re