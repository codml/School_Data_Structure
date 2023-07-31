/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 20:10:48 by taewanki          #+#    #+#             */
/*   Updated: 2023/07/25 15:29:46 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_map.h"

void	free_vars(t_vars *vars)
{
	if (vars->img_p.img)
		mlx_destroy_image(vars->mlx, vars->img_p.img);
	if (vars->img_e.img)
		mlx_destroy_image(vars->mlx, vars->img_e.img);
	if (vars->img_1.img)
		mlx_destroy_image(vars->mlx, vars->img_1.img);
	if (vars->img_0.img)
		mlx_destroy_image(vars->mlx, vars->img_0.img);
	if (vars->img_c.img)
		mlx_destroy_image(vars->mlx, vars->img_c.img);
	if (vars->img.img)
		mlx_destroy_image(vars->mlx, vars->img.img);
	mlx_destroy_window(vars->mlx, vars->win);
	ft_free_pptr(vars->pptr);
}

int	destory_win(t_vars *vars)
{
	free_vars(vars);
	exit(0);
	return (0);
}

int	close_win(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		free_vars(vars);
		exit(0);
	}
	keycode_split(vars, keycode);
	return (0);
}

int	collect_all(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < vars->height)
	{
		x = 0;
		while (x < vars->width)
		{
			if (vars->pptr[y][x] == 'C')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
