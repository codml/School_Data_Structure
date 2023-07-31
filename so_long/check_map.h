/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:55:49 by taewanki          #+#    #+#             */
/*   Updated: 2023/07/14 15:55:35 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MAP_H
# define CHECK_MAP_H
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}				t_list;

typedef struct s_stack
{
	int	*stack;
	int	idx;
	int	size;
}				t_stack;

void	ft_free_list(t_list *head);
void	ft_error_list(t_list *head);
void	ft_free_pptr(char **pptr);
void	ft_error_pptr(char **pptr);
int		check_dup(t_list *head, int matrix[]);
char	**alloc_map(t_list *head, int cnt);
int		check_line(char **pptr, int matrix[]);
int		check_etc(char **pptr);
int		return_height(char **pptr);
int		return_width(char **pptr);
int		check_movable(char **pptr, int row, int col, int *visit);
void	dfs_map(char **pptr, int *visit, int len, t_stack *stack);
void	return_spot(char **pptr, int spot[], char ch);
char	**check_map(t_list *head);
void	set_stack(char **pptr, int row, int col, t_stack **stack);
void	push(t_stack *stack, int num);
int		pop(t_stack *stack);
int		is_empty(t_stack *stack);

#endif