/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 03:00:27 by taewanki          #+#    #+#             */
/*   Updated: 2023/02/22 19:51:48 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "parsing.h"
#include "sort.h"
#include "libft/libft.h"

static int	ft_is_else(t_table *table, char *str)
{
	if (!ft_strcmp(str, "pa\n"))
		pa(table);
	else if (!ft_strcmp(str, "pb\n"))
		pb(table);
	else if (!ft_strcmp(str, "sa\n"))
		sa(table);
	else if (!ft_strcmp(str, "sb\n"))
		sb(table);
	else if (!ft_strcmp(str, "ss\n"))
		ss(table);
	else if (!ft_strcmp(str, "ra\n"))
		ra(table);
	else if (!ft_strcmp(str, "rb\n"))
		rb(table);
	else if (!ft_strcmp(str, "rr\n"))
		rr(table);
	else if (!ft_strcmp(str, "rra\n"))
		rra(table);
	else if (!ft_strcmp(str, "rrb\n"))
		rrb(table);
	else if (!ft_strcmp(str, "rrr\n"))
		rrr(table);
	else
		return (1);
	return (0);
}

static void	ft_choice(t_table *table)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (!str)
			return ;
		if (ft_is_else(table, str))
		{
			free(str);
			free_table(table);
			write(2, "Error\n", 6);
			exit(1);
		}
		free(str);
	}
}

static int	ft_is_sort(t_stack *stack)
{
	size_t	i;

	i = stack->top;
	while (i != (stack->bottom + 1) % stack->num)
	{
		if (stack->arr[i]
			> stack->arr[(i - 1 + stack->num) % stack->num])
			return (0);
		i = (i - 1 + stack->num) % stack->num;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_table		*table;
	int			*arr;

	if (argc == 1)
		return (0);
	arr = parsing(argc, argv);
	if (!arr)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	table = set_table(arr);
	ft_choice(table);
	if (ft_is_sort(table->a)
		&& table->a->bottom == (table->a->top + 1) % table->num)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_table(table);
	return (0);
}
