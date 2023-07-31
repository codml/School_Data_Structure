/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:11:56 by taewanki          #+#    #+#             */
/*   Updated: 2023/02/15 17:39:32 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_buflist
{
	int					fd;
	char				*buf;
	struct s_buflist	*next;
}				t_buflist;

int			ft_strcmp(const char *s1, const char *s2);
char		**ft_split(char const *str);
void		*ft_memset(void *b, int c, size_t len);
int			ft_findnewline(t_buflist *node, int *flag);
size_t		ft_fillstr(t_buflist *node, char **str);
void		ft_update_buffer(t_buflist **node, size_t idx);
char		*ft_returnline(t_buflist **node);
char		*get_next_line(int fd);
t_buflist	*ft_buflstnew(int fd);
void		ft_buflstadd_back(t_buflist **lst, t_buflist *node);
void		ft_buflstclear_flag(t_buflist **lst, int flag);

#endif
