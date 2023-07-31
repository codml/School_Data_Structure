/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_tool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:03:50 by taewanki          #+#    #+#             */
/*   Updated: 2023/02/19 18:49:58 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static t_cmd_list	*make_cmd_node(t_cmd cmd)
{
	t_cmd_list	*new;

	new = (t_cmd_list *)malloc(sizeof(t_cmd_list));
	if (!new)
		return (0);
	new->cmd = cmd;
	new->next = 0;
	return (new);
}

void	make_cmd_list(t_table *table, t_cmd cmd)
{
	t_cmd_list	*new;
	t_cmd_list	*head;

	head = table->head;
	new = make_cmd_node(cmd);
	if (!new)
	{
		write(2, "Error\n", 6);
		free_table(table);
		exit(1);
	}
	if (!head)
	{
		table->head = new;
		return ;
	}
	while (head->next)
		head = head->next;
	head->next = new;
}

void	free_cmd_list(t_cmd_list *head)
{
	t_cmd_list	*tmp;

	if (!head)
		return ;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
