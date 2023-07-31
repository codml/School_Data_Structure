/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 21:01:48 by taewanki          #+#    #+#             */
/*   Updated: 2023/06/26 23:20:11 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_map.h"

void	set_stack(char **pptr, int row, int col, t_stack **stack)
{
	*stack = (t_stack *)malloc(sizeof(t_stack));
	if (!(*stack))
		ft_error_pptr(pptr);
	(*stack)->stack = (int *)malloc(sizeof(int) * row * col);
	if (!((*stack)->stack))
	{
		free(*stack);
		ft_error_pptr(pptr);
	}
	(*stack)->idx = 0;
	(*stack)->size = row * col;
}

void	push(t_stack *stack, int num)
{
	if (stack->idx == stack->size)
		return ;
	stack->stack[(stack->idx)++] = num;
}

int	pop(t_stack *stack)
{
	if (is_empty(stack))
		return (-1);
	return (stack->stack[--(stack->idx)]);
}

int	is_empty(t_stack *stack)
{
	if (stack->idx == 0)
		return (1);
	else
		return (0);
}
