/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:51:56 by taewanki          #+#    #+#             */
/*   Updated: 2023/02/15 17:29:36 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_cntstrs(char const *str)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (((str[i] != ' ') && (str[i] < 9 || str[i] > 13))
			&& ((str[i + 1] == ' ') || (str[i + 1] >= 9 && str[i + 1] <= 13)))
			cnt++;
		i++;
	}
	if ((str[i - 1] != ' ') && (str[i - 1] < 9 || str[i - 1] > 13))
		cnt++;
	return (cnt);
}

static size_t	ft_strlen_c(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i] != ' ' && str[i] && (str[i] < 9 || str[i] > 13))
		i++;
	return (i);
}

static int	ft_putstrs(char const *str, size_t cnt, char **pptr)
{
	char	*ptr;
	size_t	i;

	i = 0;
	while (i < cnt)
	{
		while (*str && ((*str == ' ') || (*str >= 9 && *str <= 13)))
			str++;
		ptr = (char *)malloc(ft_strlen_c(str) + 1);
		if (!ptr)
			return (0);
		pptr[i] = ptr;
		while (*str && ((*str != ' ') && (*str < 9 || *str > 13)))
		{
			*ptr = *str;
			ptr++;
			str++;
		}
		*ptr = 0;
		while (*str && ((*str != ' ') && (*str < 9 || *str > 13)))
			str++;
		i++;
	}
	return (1);
}

char	**ft_split(char const *str)
{
	int		i;
	size_t	cnt;
	char	**pptr;

	if (!str || !(str[0]))
		return (0);
	cnt = ft_cntstrs(str);
	if (!cnt)
		return (0);
	pptr = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!pptr)
		return (0);
	ft_memset(pptr, 0, sizeof(char *) * (cnt + 1));
	if (ft_putstrs(str, cnt, pptr))
		return (pptr);
	else
	{
		i = 0;
		while (pptr[i])
			free(pptr[i++]);
		free(pptr);
		return (0);
	}
}
