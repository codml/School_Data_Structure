/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:06:04 by taewanki          #+#    #+#             */
/*   Updated: 2023/07/14 16:09:29 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_map.h"

int	return_height(char **pptr)
{
	int	i;

	i = 0;
	while (pptr[i])
		i++;
	return (i);
}

int	return_width(char **pptr)
{
	return (ft_strlen(pptr[0]));
}

int	check_movable(char **pptr, int row, int col, int *visit)
{
	int	len;

	len = ft_strlen(pptr[0]);
	if (pptr[row - 1][col] != '1'
		&& visit[(row - 1) * len + col] == 0)
		return (1);
	else if (pptr[row][col - 1] != '1'
		&& visit[row * len + col - 1] == 0)
		return (1);
	else if (pptr[row + 1][col] != '1'
		&& visit[(row + 1) * len + col] == 0)
		return (1);
	else if (pptr[row][col + 1] != '1'
		&& visit[row * len + col + 1] == 0)
		return (1);
	return (0);
}

void	dfs_map(char **pptr, int *visit, int len, t_stack *stack)
{
	int	cur;
	int	next;

	while (!is_empty(stack))
	{
		cur = pop(stack);
		if (check_movable(pptr, cur / len, cur % len, visit))
		{
			push(stack, cur);
			if (pptr[cur / len - 1][cur % len] != '1'
				&& visit[(cur / len - 1) * len + cur % len] == 0)
				next = (cur / len - 1) * len + cur % len;
			else if (pptr[cur / len][cur % len - 1] != '1'
				&& visit[(cur / len) * len + cur % len - 1] == 0)
				next = (cur / len) * len + cur % len - 1;
			else if (pptr[cur / len + 1][cur % len] != '1'
				&& visit[(cur / len + 1) * len + cur % len] == 0)
				next = (cur / len + 1) * len + cur % len;
			else
				next = (cur / len) * len + cur % len + 1;
			visit[next] = 1;
			push(stack, next);
		}
	}
}
