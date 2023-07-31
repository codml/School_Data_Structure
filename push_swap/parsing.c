/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:36:05 by taewanki          #+#    #+#             */
/*   Updated: 2023/02/22 19:52:03 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "parsing.h"

static void	ft_freenode(t_data *node)
{
	t_data	*now;
	t_data	*prev;

	if (!node)
		return ;
	now = node;
	while (now)
	{
		prev = now;
		now = now->next;
		free(prev);
	}
}

static int	ft_mkdatalist(t_data **head, int data)
{
	t_data	*tmp;
	t_data	*node;

	tmp = *head;
	while (tmp)
	{
		if (tmp->num == data)
			return (0);
		tmp = tmp->next;
	}
	node = (t_data *)malloc(sizeof(t_data));
	if (!node)
		return (0);
	node->num = data;
	node->next = 0;
	if (!(*head))
		*head = node;
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
	return (1);
}

static int	*ft_mkstack(t_data *node)
{
	t_data	*tmp;
	int		*ptr;
	int		cnt;
	int		i;

	cnt = 0;
	tmp = node;
	while (tmp)
	{
		tmp = tmp->next;
		cnt++;
	}
	ptr = (int *)malloc(sizeof(int) * (cnt + 1));
	if (!ptr)
		return (0);
	i = cnt;
	tmp = node;
	while (tmp)
	{
		ptr[i--] = tmp->num;
		tmp = tmp->next;
	}
	ptr[i] = cnt + 1;
	ft_freenode(node);
	return (ptr);
}

static void	ft_checkdata(char **pptr, t_data **head)
{
	int		j;
	int		tmp;

	j = 0;
	while (pptr[j])
	{
		tmp = ft_atoi_error(pptr, j);
		if (!ft_mkdatalist(head, tmp))
		{
			ft_freenode(*head);
			j = 0;
			while (pptr[j])
				free(pptr[j++]);
			free(pptr);
			write(2, "Error\n", 6);
			exit(1);
		}
		j++;
	}
	j = 0;
	while (pptr[j])
		free(pptr[j++]);
	free(pptr);
}

int	*parsing(int argc, char **argv)
{
	int		i;
	char	**pptr;
	t_data	*head;

	head = 0;
	i = 1;
	while (i < argc)
	{
		pptr = ft_split(argv[i]);
		if (!pptr)
		{
			ft_freenode(head);
			write(2, "Error\n", 6);
			exit(1);
		}
		ft_checkdata(pptr, &head);
		i++;
	}
	return (ft_mkstack(head));
}
