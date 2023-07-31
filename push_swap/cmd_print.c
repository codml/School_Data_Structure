/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:52:53 by taewanki          #+#    #+#             */
/*   Updated: 2023/02/22 17:54:43 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

static void	write_cmd(t_table *table, char **pptr, t_cmd cmd)
{
	size_t	i;
	ssize_t	num;

	i = 0;
	while (pptr[cmd][i])
		i++;
	num = write(1, pptr[cmd], i);
	if (num != (ssize_t)i)
		print_error(table, pptr);
}

void	print_error(t_table *table, char **pptr)
{
	if (pptr)
		free(pptr);
	write(2, "Error\n", 6);
	free_table(table);
	exit(1);
}

void	set_cmd_list(t_table *table)
{
	table->cmd_list = (char **)malloc(sizeof(char *) * 11);
	if (!(table->cmd_list))
		print_error(table, 0);
	table->cmd_list[SA] = "sa\n";
	table->cmd_list[SB] = "sb\n";
	table->cmd_list[SS] = "ss\n";
	table->cmd_list[PA] = "pa\n";
	table->cmd_list[PB] = "pb\n";
	table->cmd_list[RA] = "ra\n";
	table->cmd_list[RB] = "rb\n";
	table->cmd_list[RR] = "rr\n";
	table->cmd_list[RRA] = "rra\n";
	table->cmd_list[RRB] = "rrb\n";
	table->cmd_list[RRR] = "rrr\n";
}

static int	ft_check_cmd(t_cmd a, t_cmd b)
{
	if ((a == PA && b == PB) || (a == PB && b == PA) || (a == RA && b == RRA)
		|| (a == RRA && b == RA) || (a == RB && b == RRB)
		|| (a == RRB && b == RB) || (a == RR && b == RRR)
		|| (a == RRR && b == RR))
		return (1);
	else if ((a == SA && b == SB) || (a == SB && b == SA))
		return (2);
	else if ((a == RA && b == RB) || (a == RB && b == RA))
		return (3);
	else
		return (0);
}		

void	cmd_print(t_table *table)
{
	t_cmd_list	*tmp;

	set_cmd_list(table);
	tmp = table->head;
	while (tmp)
	{
		if (tmp->next && ft_check_cmd(tmp->cmd, tmp->next->cmd) == 2)
		{
			write_cmd(table, table->cmd_list, SS);
			tmp = tmp->next;
		}
		else if (tmp->next && ft_check_cmd(tmp->cmd, tmp->next->cmd) == 3)
		{
			write_cmd(table, table->cmd_list, RR);
			tmp = tmp->next;
		}
		else if (tmp->next && ft_check_cmd(tmp->cmd, tmp->next->cmd) == 1)
			tmp = tmp->next;
		else
			write_cmd(table, table->cmd_list, tmp->cmd);
		tmp = tmp->next;
	}
}
