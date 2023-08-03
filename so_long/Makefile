CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBDIR = ./libft
LIBFT = libft.a
MLXDIR = ./mlx
LIBMLX = libmlx.a
LDFLAGS = -lft -lmlx -L$(LIBDIR) -L$(MLXDIR)
NAME = so_long
SRCS =	check_map_free.c \
		check_map_setting.c \
		check_map_utils.c \
		check_map.c \
		draw_map.c \
		draw_map_key.c \
		draw_map_utils.c \
		so_long.c \
		stack.c
OBJS = $(SRCS:.c=.o)

all : $(LIBFT) $(LIBMLX) $(NAME)

$(NAME) : $(OBJS)

$(LIBFT) :
	make -C $(LIBDIR)

$(LIBMLX) :
	make -C $(MLXDIR)

clean:
	rm -f $(LIBDIR)/$(LIBFT) $(OBJS)
	cd $(MLXDIR) && $(MAKE) clean

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLXDIR) -c $< -o $@

.PHONY : all clean fclean re
.NOTPARALLEL :