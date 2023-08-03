/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_setting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 21:37:14 by taewanki          #+#    #+#             */
/*   Updated: 2023/06/22 03:04:49 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_map.h"

int	check_dup(t_list *head, int matrix[])
{
	matrix[0] = 0;
	while (head)
	{
		if (!matrix[0])
			matrix[1] = ft_strlen(head->str);
		else
		{
			if ((int)ft_strlen(head->str) != matrix[1])
				return (0);
		}
		head = head->next;
		matrix[0] += 1;
	}
	return (1);
}

char	**alloc_map(t_list *head, int cnt)
{
	int		i;
	char	**pptr;

	pptr = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!pptr)
		return (0);
	i = 0;
	while (i < cnt)
	{
		pptr[i++] = head->str;
		head = head->next;
	}
	pptr[cnt] = 0;
	return (pptr);
}

int	check_line(char **pptr, int matrix[])
{
	int	i;
	int	j;

	i = 0;
	while (pptr[i])
	{
		j = 0;
		while (pptr[i][j])
		{
			if (((i == 0 || i == matrix[0] - 1 || j == 0 || j == matrix[1] - 1)
					&& pptr[i][j] != '1')
					|| (pptr[i][j] != '1' && pptr[i][j] != '0'
				&& pptr[i][j] != 'C' && pptr[i][j] != 'E' && pptr[i][j] != 'P'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_etc(char **pptr)
{
	int	idx[2];
	int	arr_cep[3];

	idx[0] = 0;
	arr_cep[0] = 0;
	arr_cep[1] = 0;
	arr_cep[2] = 0;
	while (pptr[idx[0]])
	{
		idx[1] = 0;
		while (pptr[idx[0]][idx[1]])
		{
			if (pptr[idx[0]][idx[1]] == 'C')
				arr_cep[0] += 1;
			else if (pptr[idx[0]][idx[1]] == 'E')
				arr_cep[1] += 1;
			else if (pptr[idx[0]][idx[1]] == 'P')
				arr_cep[2] += 1;
			idx[1] += 1;
		}
		idx[0] += 1;
	}
	if (arr_cep[0] == 0 || arr_cep[1] != 1 || arr_cep[2] != 1)
		return (0);
	return (1);
}
