CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
HEADER = libft.h
ARFLAGS = crus
SRCS = ft_strlen.c\
       ft_strncmp.c\
	   ft_printf_conv.c\
	   ft_printf_utils.c\
	   ft_printf.c\
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
