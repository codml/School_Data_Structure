CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
HEADER = libft.h
ARFLAGS = crus
SRCS = ft_memset.c\
	   ft_split.c\
	   ft_strcmp.c\
	   get_next_line_utils.c\
	   get_next_line.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(NAME)($(OBJS))

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE) all

$(OBJS) : $(HEADER)

.PHONY : all clean fclean bonus re
.INTERMEDIATE : $(OBJS)
.NOTPARALLEL : 