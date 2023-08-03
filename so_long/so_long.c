/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 21:01:00 by taewanki          #+#    #+#             */
/*   Updated: 2023/07/25 16:08:10 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "check_map.h"
#include "draw_map.h"
#include <mlx.h>

void	make_map_list(t_list **head, char *str)
{
	t_list	*tmp;
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
	{
		free(str);
		ft_error_list(*head);
	}
	new->str = str;
	new->next = 0;
	if (!*head)
	{
		*head = new;
		return ;
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

char	**read_map(char *file_name)
{
	int		fd;
	int		len;
	char	*str;
	t_list	*head;
	char	**pptr;

	head = 0;
	len = ft_strlen(file_name);
	if (len <= 4 || ft_strncmp(file_name + len - 4, ".ber", 4)
		|| file_name[len - 5] == '/')
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	fd = open(file_name, O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		make_map_list(&head, str);
	}
	close(fd);
	pptr = check_map(head);
	return (pptr);
}

void	check_screen_size(t_vars *vars)
{
	int	x;
	int	y;

	mlx_get_screen_size(vars->mlx, &x, &y);
	if (vars->width * PHOTO_SIZE > x || vars->height * PHOTO_SIZE > y)
	{
		free_vars(vars);
		write(2, "Error\n", 6);
		exit(1);
	}
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc != 2)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	set_vars(&vars, read_map(argv[1]));
	check_screen_size(&vars);
	mlx_key_hook(vars.win, close_win, &vars);
	mlx_hook(vars.win, 17, 0, destory_win, &vars);
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
