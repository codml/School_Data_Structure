/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:11:56 by taewanki          #+#    #+#             */
/*   Updated: 2023/07/23 14:37:05 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_buflist
{
	int					fd;
	char				*buf;
	struct s_buflist	*next;
}				t_buflist;

size_t		ft_strlen(const char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*get_next_line(int fd);
t_buflist	*ft_buflstnew(int fd);
void		ft_buflstadd_back(t_buflist **lst, t_buflist *node);
void		ft_buflstclear_flag(t_buflist **lst, int flag);
int			ft_putnbr_base(long long nb, char *base, long long len);
char		*ft_strchr(const char *s, int c);
int			ft_cntlen(long long nb, long long len);
int			ft_print_p(va_list ap, int *num);
int			ft_print_d(va_list ap, int *num);
int			ft_print_i(va_list ap, int *num);
int			ft_print_u(va_list ap, int *num);
int			ft_print_x(va_list ap, int *num, char ch);
int			ft_conv(va_list ap, char ch, int *sum);
int			ft_conv2(va_list ap, char ch, int *sum);
int			ft_printf(const char *str, ...);
#endif
