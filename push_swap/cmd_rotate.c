/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 00:10:52 by taewanki          #+#    #+#             */
/*   Updated: 2023/02/20 18:15:31 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	ra(t_table *table)
{
	if (table->a->bottom == table->a->top)
		return ;
	table->a->arr[table->a->bottom] = table->a->arr[table->a->top];
	table->a->bottom = (table->a->bottom - 1 + table->num) % table->num;
	table->a->top = (table->a->top - 1 + table->num) % table->num;
	make_cmd_list(table, RA);
}

void	rb(t_table *table)
{
	if (table->b->bottom == table->b->top)
		return ;
	table->b->arr[table->b->bottom] = table->b->arr[table->b->top];
	table->b->bottom = (table->b->bottom - 1 + table->num) % table->num;
	table->b->top = (table->b->top - 1 + table->num) % table->num;
	make_cmd_list(table, RB);
}

void	rr(t_table *table)
{
	if (table->a->bottom == table->a->top || table->b->bottom == table->b->top)
		return ;
	table->a->arr[table->a->bottom] = table->a->arr[table->a->top];
	table->a->bottom = (table->a->bottom - 1 + table->num) % table->num;
	table->a->top = (table->a->top - 1 + table->num) % table->num;
	table->b->arr[table->b->bottom] = table->b->arr[table->b->top];
	table->b->bottom = (table->b->bottom - 1 + table->num) % table->num;
	table->b->top = (table->b->top - 1 + table->num) % table->num;
	make_cmd_list(table, RR);
}
