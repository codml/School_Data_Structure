/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 23:28:23 by taewanki          #+#    #+#             */
/*   Updated: 2023/02/19 18:49:51 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sa(t_table *table)
{
	if (table->a->bottom == table->a->top
		|| table->a->top == (table->a->bottom + 1) % table->num)
		return ;
	swap(table->a->arr + table->a->top,
		table->a->arr + ((table->a->top - 1 + table->num) % table->num));
	make_cmd_list(table, SA);
}

void	sb(t_table *table)
{
	if (table->b->bottom == table->b->top
		|| table->b->top == (table->b->bottom + 1) % table->num)
		return ;
	swap(table->b->arr + table->b->top,
		table->b->arr + ((table->b->top - 1 + table->num) % table->num));
	make_cmd_list(table, SB);
}

void	ss(t_table *table)
{
	if (table->a->bottom == table->a->top
		|| table->a->top == (table->a->bottom + 1) % table->num
		|| table->b->bottom == table->b->top
		|| table->b->top == (table->b->bottom + 1) % table->num)
		return ;
	swap(table->a->arr + table->a->top,
		table->a->arr + ((table->a->top - 1 + table->num) % table->num));
	swap(table->b->arr + table->b->top,
		table->b->arr + ((table->b->top - 1 + table->num) % table->num));
	make_cmd_list(table, SS);
}
