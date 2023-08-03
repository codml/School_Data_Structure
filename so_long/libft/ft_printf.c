/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 16:47:58 by taewanki          #+#    #+#             */
/*   Updated: 2023/07/14 16:48:12 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_conv(va_list ap, char ch, int *sum)
{
	char	ret;
	char	*ptr;

	if (ch == 'c')
	{
		ret = va_arg(ap, int);
		if (write(1, &ret, 1) != 1)
			return (0);
		*sum += 1;
	}
	else if (ch == 's')
	{
		ptr = va_arg(ap, char *);
		if (!ptr)
			ptr = "(null)";
		if (write(1, ptr, ft_strlen(ptr)) != (ssize_t)ft_strlen(ptr))
			return (0);
		*sum += ft_strlen(ptr);
	}
	else if (ft_strchr("pdiuxX%", ch))
		return (ft_conv2(ap, ch, sum));
	else
		return (0);
	return (1);
}

int	ft_conv2(va_list ap, char ch, int *sum)
{
	if (ch == 'p')
		return (ft_print_p(ap, sum));
	else if (ch == 'd')
		return (ft_print_d(ap, sum));
	else if (ch == 'i')
		return (ft_print_i(ap, sum));
	else if (ch == 'u')
		return (ft_print_u(ap, sum));
	else if (ch == 'x')
		return (ft_print_x(ap, sum, 'x'));
	else if (ch == 'X')
		return (ft_print_x(ap, sum, 'X'));
	else if (ch == '%')
	{
		if (write(1, &ch, 1) != 1)
			return (0);
		*sum += 1;
		return (1);
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		sum;

	va_start(ap, str);
	sum = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (!ft_conv(ap, *str, &sum))
				return (-1);
		}
		else
		{
			if (write(1, str, 1) != 1)
				return (-1);
			sum++;
		}
		if (*str)
			str++;
	}
	va_end(ap);
	return (sum);
}
