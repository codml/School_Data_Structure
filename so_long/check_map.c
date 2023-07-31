/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:54:51 by taewanki          #+#    #+#             */
/*   Updated: 2023/07/18 21:35:40 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_map.h"

static char	**check_elements(t_list *head, int matrix[])
{
	char	**pptr;

	if (!check_dup(head, matrix))
		ft_error_list(head);
	pptr = alloc_map(head, matrix[0]);
	if (!pptr)
		ft_error_list(head);
	ft_free_list(head);
	if (!(check_line(pptr, matrix) && check_etc(pptr)))
		ft_error_pptr(pptr);
	return (pptr);
}

static void	set_visit(char **pptr, int row, int col, int **visit)
{
	int	i;

	*visit = (int *)malloc(sizeof(int) * row * col);
	if (*visit == 0)
		ft_error_pptr(pptr);
	i = 0;
	while (i < row * col)
		(*visit)[i++] = 0;
}

static int	check_right_path(char **pptr, int *visit)
{
	int	i;
	int	j;
	int	len;

	len = ft_strlen(pptr[0]);
	i = 0;
	while (pptr[i])
	{
		j = 0;
		while (pptr[i][j])
		{
			if ((pptr[i][j] == 'E'
				&& visit[i * len + j] == 0)
				|| (pptr[i][j] == 'C'
				&& visit[i * len + j] == 0))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	return_spot(char **pptr, int spot[], char ch)
{
	int	i;
	int	j;

	i = 0;
	while (pptr[i])
	{
		j = 0;
		while (pptr[i][j])
		{
			if (pptr[i][j] == ch)
			{
				spot[0] = i;
				spot[1] = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

char	**check_map(t_list *head)
{
	int		*visit;
	t_stack	*stack;
	int		p_spot[2];
	int		matrix[2];
	char	**pptr;

	pptr = check_elements(head, matrix);
	return_spot(pptr, p_spot, 'P');
	set_visit(pptr, matrix[0], matrix[1], &visit);
	set_stack(pptr, matrix[0], matrix[1], &stack);
	push(stack, p_spot[0] * ft_strlen(pptr[0]) + p_spot[1]);
	visit[p_spot[0] * ft_strlen(pptr[0]) + p_spot[1]] = 1;
	dfs_map(pptr, visit, ft_strlen(pptr[0]), stack);
	free(stack->stack);
	free(stack);
	if (!check_right_path(pptr, visit))
	{
		free(visit);
		ft_error_pptr(pptr);
	}
	free(visit);
	return (pptr);
}
