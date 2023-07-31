/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:03:47 by taewanki          #+#    #+#             */
/*   Updated: 2023/02/19 18:54:59 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static void	ft_print_error(int *arr)
{
	free(arr);
	write(2, "Error\n", 6);
	exit(1);
}

static t_table	*ft_fill_stacks(t_table *table, t_stack *stacks,
				int *arr, int *arr2)
{
	stacks->arr = arr;
	stacks->bottom = 0;
	stacks->top = arr[0] - 1;
	(stacks + 1)->arr = arr2;
	(stacks + 1)->bottom = 0;
	(stacks + 1)->top = 0;
	table->a = stacks;
	table->b = stacks + 1;
	table->num = arr[0];
	table->a->num = arr[0];
	table->b->num = arr[0];
	table->head = 0;
	table->cmd_list = 0;
	return (table);
}

void	free_table(t_table *table)
{
	free(table->a->arr);
	free(table->b->arr);
	free(table->a);
	free_cmd_list(table->head);
	free(table->cmd_list);
	free(table);
}

t_table	*set_table(int *arr)
{
	t_table		*table;
	t_stack		*stacks;
	int			*arr2;

	stacks = (t_stack *)malloc(sizeof(t_stack) * 2);
	if (!stacks)
		ft_print_error(arr);
	arr2 = (int *)malloc(sizeof(int) * arr[0]);
	if (!arr2)
	{
		free(stacks);
		ft_print_error(arr);
	}
	table = (t_table *)malloc(sizeof(t_table));
	if (!table)
	{
		free(arr2);
		free(stacks);
		ft_print_error(arr);
	}
	return (ft_fill_stacks(table, stacks, arr, arr2));
}
