/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_rrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 00:19:46 by taewanki          #+#    #+#             */
/*   Updated: 2023/02/20 18:15:13 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	rra(t_table *table)
{
	if (table->a->bottom == table->a->top)
		return ;
	table->a->arr[(table->a->top + 1) % table->num] = \
	table->a->arr[(table->a->bottom + 1) % table->num];
	table->a->bottom = (table->a->bottom + 1) % table->num;
	table->a->top = (table->a->top + 1) % table->num;
	make_cmd_list(table, RRA);
}

void	rrb(t_table *table)
{
	if (table->b->bottom == table->b->top)
		return ;
	table->b->arr[(table->b->top + 1) % table->num] = \
	table->b->arr[(table->b->bottom + 1) % table->num];
	table->b->bottom = (table->b->bottom + 1) % table->num;
	table->b->top = (table->b->top + 1) % table->num;
	make_cmd_list(table, RRB);
}

void	rrr(t_table *table)
{
	if (table->a->bottom == table->a->top || table->b->bottom == table->b->top)
		return ;
	table->a->arr[(table->a->top + 1) % table->num] = \
	table->a->arr[(table->a->bottom + 1) % table->num];
	table->a->bottom = (table->a->bottom + 1) % table->num;
	table->a->top = (table->a->top + 1) % table->num;
	table->b->arr[(table->b->top + 1) % table->num] = \
	table->b->arr[(table->b->bottom + 1) % table->num];
	table->b->bottom = (table->b->bottom + 1) % table->num;
	table->b->top = (table->b->top + 1) % table->num;
	make_cmd_list(table, RRR);
}
