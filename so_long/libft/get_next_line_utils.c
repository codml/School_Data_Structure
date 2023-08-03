/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 17:02:22 by taewanki          #+#    #+#             */
/*   Updated: 2023/02/15 17:39:57 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_buflist	*ft_buflstnew(int fd)
{
	t_buflist	*ptr;
	ssize_t		num;

	ptr = (t_buflist *)malloc(sizeof(t_buflist));
	if (!ptr)
		return (0);
	ptr->buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!(ptr->buf))
	{
		free(ptr);
		return (0);
	}
	num = read(fd, ptr->buf, BUFFER_SIZE);
	if (num == -1)
	{
		free(ptr->buf);
		free(ptr);
		return (0);
	}
	(ptr->buf)[num] = 0;
	ptr->fd = fd;
	ptr->next = 0;
	return (ptr);
}

void	ft_buflstadd_back(t_buflist **lst, t_buflist *node)
{
	t_buflist	*temp;

	if (lst == 0 || node == 0)
		return ;
	else if (*lst == 0)
	{
		*lst = node;
		return ;
	}
	else if ((*lst)->fd != node->fd)
	{
		ft_buflstclear_flag(lst, 0);
		*lst = node;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = node;
}

void	ft_buflstclear_flag(t_buflist **node, int flag)
{
	t_buflist	*now;
	t_buflist	*temp;

	if (node == 0 || *node == 0)
		return ;
	now = *node;
	while (now)
	{
		if (flag && !(now->next))
			break ;
		temp = now;
		now = now->next;
		free(temp->buf);
		free(temp);
	}
	*node = now;
}
