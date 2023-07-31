/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:18:12 by taewanki          #+#    #+#             */
/*   Updated: 2023/02/15 17:40:03 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_findnewline(t_buflist *node, int *flag)
{
	size_t		i;

	if (!node)
		return (0);
	if ((node->buf)[0] == 0)
	{
		*flag = 1;
		return (1);
	}
	while (node->next)
		node = node->next;
	if ((node->buf)[0] == 0)
		return (1);
	i = 0;
	while ((node->buf)[i])
	{
		if ((node->buf)[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_fillstr(t_buflist *node, char **str)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (node)
	{
		j = 0;
		while ((node->buf)[j])
		{
			(*str)[i] = (node->buf)[j];
			if ((node->buf)[j] == '\n')
			{
				i++;
				j++;
				break ;
			}
			i++;
			j++;
		}
		node = node->next;
	}
	(*str)[i] = 0;
	return (j);
}

void	ft_update_buffer(t_buflist **node, size_t idx)
{
	size_t		i;
	size_t		j;

	ft_buflstclear_flag(node, 1);
	i = 0;
	while (((*node)->buf)[i])
		i++;
	if (i == idx)
	{
		ft_buflstclear_flag(node, 0);
		return ;
	}
	j = 0;
	while (j < i - idx)
	{
		((*node)->buf)[j] = ((*node)->buf)[j + idx];
		j++;
	}
	((*node)->buf)[j] = 0;
}

char	*ft_returnline(t_buflist **node)
{
	size_t		lst_len;
	size_t		idx;
	t_buflist	*ptr;
	char		*str;

	ptr = *node;
	lst_len = 0;
	while (ptr)
	{
		ptr = ptr->next;
		lst_len++;
	}
	str = (char *)malloc(lst_len * BUFFER_SIZE + 1);
	if (!str)
		return (0);
	idx = ft_fillstr(*node, &str);
	ft_update_buffer(node, idx);
	return (str);
}

char	*get_next_line(int fd)
{
	static t_buflist	*head;
	t_buflist			*temp;
	int					flag;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	flag = 0;
	while (!ft_findnewline(head, &flag))
	{
		temp = ft_buflstnew(fd);
		if (!temp)
		{
			if (head && head->fd == fd)
				ft_buflstclear_flag(&head, 0);
			return (0);
		}
		ft_buflstadd_back(&head, temp);
	}
	if (flag)
	{
		ft_buflstclear_flag(&head, 0);
		return (0);
	}
	return (ft_returnline(&head));
}
