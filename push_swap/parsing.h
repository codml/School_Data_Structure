/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 17:04:59 by taewanki          #+#    #+#             */
/*   Updated: 2023/02/15 17:57:28 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_data
{
	int				num;
	struct s_data	*next;
}				t_data;

int		ft_atoi_error(char **pptr, int idx);
char	**ft_split(char const *str);
int		*parsing(int argc, char **argv);

#endif