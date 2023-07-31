/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:08:51 by taewanki          #+#    #+#             */
/*   Updated: 2023/02/15 17:14:11 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

static void	ft_print_error(char **pptr)
{
	int	i;

	write(2, "Error\n", 6);
	i = 0;
	while (pptr[i])
		free(pptr[i++]);
	free(pptr);
	exit(1);
}

static int	ft_not_int(long ret, int minus, char ch)
{
	if (minus == -1
		&& (ret > 214748364 || (ret == 214748364 && ch - '0' > 8)))
		return (1);
	else if (minus == 1
		&& (ret > 214748364 || (ret == 214748364 && ch - '0' > 7)))
		return (1);
	else
		return (0);
}

int	ft_atoi_error(char **pptr, int idx)
{
	int		i;
	int		minus;
	long	ret;

	i = 0;
	minus = 1;
	ret = 0;
	if (pptr[idx][i] == '-' || pptr[idx][i] == '+')
	{
		if (pptr[idx][i] == '-')
			minus *= -1;
		i++;
	}
	while (pptr[idx][i] >= '0' && pptr[idx][i] <= '9')
	{
		if (ft_not_int(ret, minus, pptr[idx][i]))
			ft_print_error(pptr);
		ret *= 10;
		ret += pptr[idx][i++] - '0';
	}
	if ((pptr[idx][i] != 0 && (pptr[idx][i] < '0' || pptr[idx][i] > '9'))
		|| (((pptr[idx][0] == '+') || (pptr[idx][0] == '-'))
		&& (pptr[idx][1] == 0)))
		ft_print_error(pptr);
	return ((int)(ret * minus));
}
