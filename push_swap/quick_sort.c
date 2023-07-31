/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:29:14 by taewanki          #+#    #+#             */
/*   Updated: 2023/02/20 19:13:39 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static void	rewind_stack(t_table *table, size_t num_ra, size_t num_rb)
{
	size_t	i;

	i = 0;
	while (i < num_ra || i < num_rb)
	{
		if (i >= num_ra)
			rrb(table);
		else if (i >= num_rb)
			rra(table);
		else
			rrr(table);
		i++;
	}
}

static void	devide_a(t_table *table, size_t cnt, size_t arr[], int pivot[])
{
	while (cnt--)
	{
		if (table->a->arr[table->a->top] >= pivot[1])
		{
			ra(table);
			arr[RA] += 1;
		}
		else
		{
			pb(table);
			arr[PB] += 1;
			if (table->b->arr[table->b->top] >= pivot[0])
			{
				rb(table);
				arr[RB] += 1;
			}
		}
	}
}

static void	devide_b(t_table *table, size_t cnt, size_t arr[], int pivot[])
{
	while (cnt--)
	{
		if (table->b->arr[table->b->top] < pivot[0])
		{
			rb(table);
			arr[RB] += 1;
		}
		else
		{
			pa(table);
			arr[PA] += 1;
			if (table->a->arr[table->a->top] < pivot[1])
			{
				ra(table);
				arr[RA] += 1;
			}
		}
	}
}

void	a_to_b(t_table *table, size_t cnt)
{
	size_t	arr[11];
	int		pivot[2];

	arr[RA] = 0;
	arr[RB] = 0;
	arr[PB] = 0;
	if (check_sort(table->a, cnt))
		return ;
	else if (cnt < 3
		|| (cnt == 3 && (table->a->top - table->a->bottom + table->num)
			% table->num == 3)
		|| (cnt == 5 && (table->a->top - table->a->bottom + table->num)
			% table->num == 5))
	{
		sort_a(table, cnt);
		return ;
	}
	set_pivot(table, 'a', cnt, pivot);
	devide_a(table, cnt, arr, pivot);
	rewind_stack(table, arr[RA], arr[RB]);
	a_to_b(table, arr[RA]);
	b_to_a(table, arr[RB]);
	b_to_a(table, arr[PB] - arr[RB]);
}

void	b_to_a(t_table *table, size_t cnt)
{
	size_t	arr[11];
	int		pivot[2];

	arr[RA] = 0;
	arr[RB] = 0;
	arr[PA] = 0;
	if (cnt < 3)
	{
		sort_b(table, cnt);
		return ;
	}
	set_pivot(table, 'b', cnt, pivot);
	devide_b(table, cnt, arr, pivot);
	a_to_b(table, arr[PA] - arr[RA]);
	rewind_stack(table, arr[RA], arr[RB]);
	a_to_b(table, arr[RA]);
	b_to_a(table, arr[RB]);
}
