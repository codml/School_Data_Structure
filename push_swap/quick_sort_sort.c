/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:28:04 by taewanki          #+#    #+#             */
/*   Updated: 2023/02/21 20:20:52 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static void	sort_only_three(t_table *table)
{
	if (check_sort(table->a, 3))
		return ;
	if (table->a->arr[table->a->top]
		> table->a->arr[(table->a->top - 1 + table->num) % table->num]
		&& table->a->arr[table->a->top]
		< table->a->arr[(table->a->top - 2 + table->num) % table->num])
	{
		sa(table);
		return ;
	}
	ra(table);
	if (table->a->arr[table->a->top]
		> table->a->arr[(table->a->top - 1 + table->num) % table->num]
		&& table->a->arr[table->a->top]
		< table->a->arr[(table->a->top - 2 + table->num) % table->num])
	{
		sa(table);
		return ;
	}
	if (check_sort(table->a, 3))
		return ;
	ra(table);
	if (check_sort(table->a, 3))
		return ;
	sa(table);
}

static void	sort_only_five(t_table *table, int a, int b)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (i < 5)
	{
		if (cnt == 2)
			break ;
		if (table->a->arr[table->a->top] == a
			|| table->a->arr[table->a->top] == b)
		{
			pb(table);
			cnt++;
		}
		else
			ra(table);
		i++;
	}
	sort_only_three(table);
	if (table->b->arr[table->b->top]
		< table->b->arr[(table->b->top - 1 + table->num) % table->num])
		sb(table);
	pa(table);
	pa(table);
}

int	check_sort(t_stack *stack, size_t cnt)
{
	size_t	i;

	if (cnt <= 1)
		return (1);
	i = 0;
	while (i < cnt - 1)
	{
		if (stack->arr[(stack->top - i + stack->num) % stack->num]
			> stack->arr[(stack->top - i - 1 + stack->num) % stack->num])
			return (0);
		i++;
	}
	return (1);
}

void	sort_a(t_table *table, size_t cnt)
{
	int	*arr;

	if (cnt == 2)
	{
		if (table->a->arr[table->a->top]
			> table->a->arr[(table->a->top - 1 + table->num) % table->num])
			sa(table);
	}
	else if (cnt == 3 && (table->a->top - table->a->bottom + table->num)
		% table->num == 3)
		sort_only_three(table);
	else if (cnt == 5 && (table->a->top - table->a->bottom + table->num)
		% table->num == 5)
	{
		arr = (int *)malloc(sizeof(int) * cnt);
		if (!arr)
			print_error(table, 0);
		while (cnt--)
			arr[4 - cnt] = table->a->arr[(table->a->top - 4
					+ cnt + table->num) % table->num];
		bubble_sort(arr, 5);
		sort_only_five(table, arr[0], arr[1]);
		free(arr);
	}
}

void	sort_b(t_table *table, size_t cnt)
{
	if (cnt == 1)
		pa(table);
	else if (cnt == 2)
	{
		if (table->b->arr[table->b->top]
			< table->b->arr[(table->b->top - 1 + table->num) % table->num])
			sb(table);
		pa(table);
		pa(table);
	}
}
