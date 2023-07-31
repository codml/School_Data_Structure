/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:14:36 by taewanki          #+#    #+#             */
/*   Updated: 2023/02/20 19:55:50 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H
# include <unistd.h>
# include <stdlib.h>

typedef enum e_cmd
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}			t_cmd;

typedef struct s_cmd_list
{
	t_cmd				cmd;
	struct s_cmd_list	*next;
}				t_cmd_list;

typedef struct s_stack
{
	int		*arr;
	size_t	bottom;
	size_t	top;
	size_t	num;
}				t_stack;

typedef struct s_table
{
	t_stack		*a;
	t_stack		*b;
	t_cmd_list	*head;
	char		**cmd_list;
	size_t		num;
}				t_table;

void	pa(t_table *table);
void	pb(t_table *table);
void	swap(int *a, int *b);
void	sa(t_table *table);
void	sb(t_table *table);
void	ss(t_table *table);
void	ra(t_table *table);
void	rb(t_table *table);
void	rr(t_table *table);
void	rra(t_table *table);
void	rrb(t_table *table);
void	rrr(t_table *table);
void	make_cmd_list(t_table *table, t_cmd cmd);
void	free_cmd_list(t_cmd_list *head);
void	print_error(t_table *table, char **pptr);
void	cmd_print(t_table *table);
t_table	*set_table(int *arr);
void	free_table(t_table *table);
void	bubble_sort(int *arr, size_t cnt);
void	set_pivot(t_table *table, char ch, size_t cnt, int *pivot);
int		check_sort(t_stack *stack, size_t cnt);
void	sort_a(t_table *table, size_t cnt);
void	sort_b(t_table *table, size_t cnt);
void	a_to_b(t_table *table, size_t cnt);
void	b_to_a(t_table *table, size_t cnt);

#endif