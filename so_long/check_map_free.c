/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:06:06 by taewanki          #+#    #+#             */
/*   Updated: 2023/06/29 22:48:28 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_map.h"

void	ft_free_list(t_list *head)
{
	t_list	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

void	ft_error_list(t_list *head)
{
	t_list	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp->str);
		free(tmp);
	}
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_free_pptr(char **pptr)
{
	int	i;

	i = 0;
	while (pptr[i])
		free(pptr[i++]);
	free(pptr);
}

void	ft_error_pptr(char **pptr)
{
	int	i;

	i = 0;
	while (pptr[i])
		free(pptr[i++]);
	free(pptr);
	write(2, "Error\n", 6);
	exit(1);
}
