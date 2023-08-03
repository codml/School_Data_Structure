/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 22:44:19 by taewanki          #+#    #+#             */
/*   Updated: 2023/07/25 15:48:36 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_map.h"

void	keycode_split(t_vars *vars, int keycode)
{
	int	err;

	err = 0;
	if (keycode == 123)
		err = move_left(vars);
	else if (keycode == 124)
		err = move_right(vars);
	else if (keycode == 125)
		err = move_down(vars);
	else if (keycode == 126)
		err = move_up(vars);
	if (err == 2)
	{
		free_vars(vars);
		write(2, "Error\n", 6);
		exit(1);
	}
}

int	move_left(t_vars *vars)
{
	int	x;
	int	y;

	if (vars->pptr[vars->now_y][vars->now_x - 1] != '1')
	{
		ft_printf("Move count: %d\n", ++(vars->cnt));
		if (vars->pptr[vars->now_y][vars->now_x - 1] == 'E'
			&& collect_all(vars))
		{
			free_vars(vars);
			exit(0);
		}
		if (vars->pptr[vars->now_y][vars->now_x - 1] == 'C')
			vars->pptr[vars->now_y][vars->now_x - 1] = '0';
		vars->now_x--;
	}
	mlx_destroy_image(vars->mlx, vars->img_p.img);
	vars->img_p.img = mlx_xpm_file_to_image(vars->mlx,
			"textures/hero_left.xpm", &x, &y);
	if (vars->img_p.img == 0)
		return (2);
	vars->img_p.addr = mlx_get_data_addr(vars->img_p.img,
			&(vars->img_p.bits_per_pixel),
			&(vars->img_p.line_length), &(vars->img_p.endian));
	return (1);
}

int	move_right(t_vars *vars)
{
	int	x;
	int	y;

	if (vars->pptr[vars->now_y][vars->now_x + 1] != '1')
	{
		ft_printf("Move count: %d\n", ++(vars->cnt));
		if (vars->pptr[vars->now_y][vars->now_x + 1] == 'E'
			&& collect_all(vars))
		{
			free_vars(vars);
			exit(0);
		}
		if (vars->pptr[vars->now_y][vars->now_x + 1] == 'C')
			vars->pptr[vars->now_y][vars->now_x + 1] = '0';
		vars->now_x++;
	}
	mlx_destroy_image(vars->mlx, vars->img_p.img);
	vars->img_p.img = mlx_xpm_file_to_image(vars->mlx,
			"textures/hero_right.xpm", &x, &y);
	if (vars->img_p.img == 0)
		return (2);
	vars->img_p.addr = mlx_get_data_addr(vars->img_p.img,
			&(vars->img_p.bits_per_pixel),
			&(vars->img_p.line_length), &(vars->img_p.endian));
	return (1);
}

int	move_down(t_vars *vars)
{
	int	x;
	int	y;

	if (vars->pptr[vars->now_y + 1][vars->now_x] != '1')
	{
		ft_printf("Move count: %d\n", ++(vars->cnt));
		if (vars->pptr[vars->now_y + 1][vars->now_x] == 'E'
			&& collect_all(vars))
		{
			free_vars(vars);
			exit(0);
		}
		if (vars->pptr[vars->now_y + 1][vars->now_x] == 'C')
			vars->pptr[vars->now_y + 1][vars->now_x] = '0';
		vars->now_y++;
	}
	mlx_destroy_image(vars->mlx, vars->img_p.img);
	vars->img_p.img = mlx_xpm_file_to_image(vars->mlx,
			"textures/hero_down.xpm", &x, &y);
	if (vars->img_p.img == 0)
		return (2);
	vars->img_p.addr = mlx_get_data_addr(vars->img_p.img,
			&(vars->img_p.bits_per_pixel),
			&(vars->img_p.line_length), &(vars->img_p.endian));
	return (1);
}

int	move_up(t_vars *vars)
{
	int	x;
	int	y;

	if (vars->pptr[vars->now_y - 1][vars->now_x] != '1')
	{
		ft_printf("Move count: %d\n", ++(vars->cnt));
		if (vars->pptr[vars->now_y - 1][vars->now_x] == 'E'
			&& collect_all(vars))
		{
			free_vars(vars);
			exit(0);
		}
		if (vars->pptr[vars->now_y - 1][vars->now_x] == 'C')
			vars->pptr[vars->now_y - 1][vars->now_x] = '0';
		vars->now_y--;
	}
	mlx_destroy_image(vars->mlx, vars->img_p.img);
	vars->img_p.img = mlx_xpm_file_to_image(vars->mlx,
			"textures/hero_up.xpm", &x, &y);
	if (vars->img_p.img == 0)
		return (2);
	vars->img_p.addr = mlx_get_data_addr(vars->img_p.img,
			&(vars->img_p.bits_per_pixel),
			&(vars->img_p.line_length), &(vars->img_p.endian));
	return (1);
}
