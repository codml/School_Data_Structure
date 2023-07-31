/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 23:26:25 by taewanki          #+#    #+#             */
/*   Updated: 2023/02/22 18:50:53 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	pa(t_table *table)
{
	int	num;

	if (table->b->bottom == table->b->top
		|| table->a->bottom == (table->a->top + 1) % table->num)
		return ;
	num = table->b->arr[table->b->top];
	table->b->top = (table->b->top - 1 + table->num) % table->num;
	table->a->top = (table->a->top + 1) % table->num;
	table->a->arr[table->a->top] = num;
	make_cmd_list(table, PA);
}

void	pb(t_table *table)
{
	int	num;

	if (table->a->bottom == table->a->top
		|| table->b->bottom == (table->b->top + 1) % table->num)
		return ;
	num = table->a->arr[table->a->top];
	table->a->top = (table->a->top - 1 + table->num) % table->num;
	table->b->top = (table->b->top + 1) % table->num;
	table->b->arr[table->b->top] = num;
	make_cmd_list(table, PB);
}
