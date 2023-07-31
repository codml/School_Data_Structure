/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:47:07 by taewanki          #+#    #+#             */
/*   Updated: 2023/01/03 20:08:02 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_print_p(va_list ap, int *sum)
{
	void				*ptr;
	unsigned long long	num;

	ptr = va_arg(ap, void *);
	num = (unsigned long long)ptr;
	if (write(1, "0x", 2) != 2)
		return (0);
	if (!ft_putnbr_base(num, "0123456789abcdef", 16))
		return (0);
	*sum += ft_cntlen(num, 16) + 2;
	return (1);
}

int	ft_print_d(va_list ap, int *sum)
{
	int			minus;
	int			num;
	long long	ret;

	minus = 0;
	num = va_arg(ap, int);
	ret = num;
	if (num < 0)
	{
		if (write(1, "-", 1) != 1)
			return (0);
		ret *= -1;
		minus++;
	}
	if (!ft_putnbr_base(ret, "0123456789", 10))
		return (0);
	*sum += ft_cntlen(ret, 10) + minus;
	return (1);
}

int	ft_print_i(va_list ap, int *sum)
{
	int			minus;
	int			num;
	long long	ret;

	minus = 0;
	num = va_arg(ap, int);
	ret = num;
	if (num < 0)
	{
		if (write(1, "-", 1) != 1)
			return (0);
		ret *= -1;
		minus++;
	}
	if (!ft_putnbr_base(ret, "0123456789", 10))
		return (0);
	*sum += ft_cntlen(ret, 10) + minus;
	return (1);
}

int	ft_print_u(va_list ap, int *sum)
{
	unsigned int	num;

	num = va_arg(ap, unsigned int);
	if (!ft_putnbr_base(num, "0123456789", 10))
		return (0);
	*sum += ft_cntlen(num, 10);
	return (1);
}

int	ft_print_x(va_list ap, int *sum, char ch)
{
	unsigned int	num;

	num = va_arg(ap, unsigned int);
	if (ch == 'x')
	{
		if (!ft_putnbr_base(num, "0123456789abcdef", 16))
			return (0);
	}
	else
	{
		if (!ft_putnbr_base(num, "0123456789ABCDEF", 16))
			return (0);
	}
	*sum += ft_cntlen(num, 16);
	return (1);
}
