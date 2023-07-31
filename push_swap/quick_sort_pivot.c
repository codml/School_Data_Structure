/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_pivot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:05:28 by taewanki          #+#    #+#             */
/*   Updated: 2023/02/20 20:08:14 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	bubble_sort(int *arr, size_t cnt)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < cnt - 1)
	{
		j = 0;
		while (j < cnt - 1 - i)
		{
			if (arr[j] > arr[j + 1])
				swap(arr + j, arr + j + 1);
			j++;
		}
		i++;
	}
}

void	set_pivot(t_table *table, char ch, size_t cnt, int *pivot)
{
	t_stack	*stack;
	int		*arr;
	size_t	i;

	if (ch == 'a')
		stack = table->a;
	else
		stack = table->b;
	arr = (int *)malloc(sizeof(int) * (cnt));
	if (!arr)
		print_error(table, 0);
	i = 0;
	while (i < cnt)
	{
		arr[i] = stack->arr[(stack->top - i + stack->num) % stack->num];
		i++;
	}
	bubble_sort(arr, cnt);
	pivot[0] = arr[cnt / 3];
	pivot[1] = arr[cnt * 2 / 3];
	free(arr);
}
