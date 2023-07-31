/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:56:26 by taewanki          #+#    #+#             */
/*   Updated: 2023/07/25 15:20:38 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_map.h"

static void	put_image_to_buf(t_data *buf, t_data *img, int x, int y)
{
	char	*dst;
	char	*src;
	int		img_x;
	int		img_y;

	img_y = 0;
	while (img_y < 50)
	{
		img_x = 0;
		while (img_x < 50)
		{
			dst = buf->addr + ((y + img_y) * buf->line_length
					+ (x + img_x) * (buf->bits_per_pixel / 8));
			src = img->addr + (img_y
					* img->line_length + img_x * (img->bits_per_pixel / 8));
			if (*(unsigned int *)src != 0x0)
				*(unsigned int *)dst = *(unsigned int *)src;
			img_x++;
		}
		img_y++;
	}
}

static void	draw_icon(t_vars *vars, int img_x, int img_y, char ch)
{
	put_image_to_buf(&(vars->img), &(vars->img_0),
		img_x * PHOTO_SIZE, img_y * PHOTO_SIZE);
	if (ch == '1')
		put_image_to_buf(&(vars->img), &(vars->img_1),
			img_x * PHOTO_SIZE, img_y * PHOTO_SIZE);
	if (ch == 'E')
		put_image_to_buf(&(vars->img), &(vars->img_e),
			img_x * PHOTO_SIZE, img_y * PHOTO_SIZE);
	if (ch == 'C')
		put_image_to_buf(&(vars->img), &(vars->img_c),
			img_x * PHOTO_SIZE, img_y * PHOTO_SIZE);
	if (img_y == vars->now_y && img_x == vars->now_x)
		put_image_to_buf(&(vars->img), &(vars->img_p),
			img_x * PHOTO_SIZE, img_y * PHOTO_SIZE);
}

static void	set_imgs(t_vars *vars)
{
	if (vars->img_p.img == 0 || vars->img_e.img == 0 || vars->img_1.img == 0
		|| vars->img_0.img == 0 || vars->img_c.img == 0 || vars->img.img == 0)
	{
		free_vars(vars);
		write(2, "Error\n", 6);
		exit(1);
	}
	vars->img_0.addr = mlx_get_data_addr(vars->img_0.img,
			&(vars->img_0.bits_per_pixel),
			&(vars->img_0.line_length), &(vars->img_0.endian));
	vars->img_1.addr = mlx_get_data_addr(vars->img_1.img,
			&(vars->img_1.bits_per_pixel),
			&(vars->img_1.line_length), &(vars->img_1.endian));
	vars->img_p.addr = mlx_get_data_addr(vars->img_p.img,
			&(vars->img_p.bits_per_pixel),
			&(vars->img_p.line_length), &(vars->img_p.endian));
	vars->img_e.addr = mlx_get_data_addr(vars->img_e.img,
			&(vars->img_e.bits_per_pixel),
			&(vars->img_e.line_length), &(vars->img_e.endian));
	vars->img_c.addr = mlx_get_data_addr(vars->img_c.img,
			&(vars->img_c.bits_per_pixel),
			&(vars->img_c.line_length), &(vars->img_c.endian));
	vars->img.addr = mlx_get_data_addr(vars->img.img,
			&(vars->img.bits_per_pixel),
			&(vars->img.line_length), &(vars->img.endian));
}

void	set_vars(t_vars *vars, char **pptr)
{
	int	now[2];

	vars->width = return_width(pptr);
	vars->height = return_height(pptr);
	vars->pptr = pptr;
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx,
			PHOTO_SIZE * vars->width, PHOTO_SIZE * vars->height, "so_long");
	vars->img.img = mlx_new_image(vars->mlx,
			PHOTO_SIZE * vars->width, PHOTO_SIZE * vars->height);
	return_spot(vars->pptr, now, 'P');
	vars->now_y = now[0];
	vars->now_x = now[1];
	vars->cnt = 0;
	vars->img_p.img = mlx_xpm_file_to_image(vars->mlx,
			"textures/hero_down.xpm", now, now + 1);
	vars->img_e.img = mlx_xpm_file_to_image(vars->mlx,
			"textures/exit.xpm", now, now + 1);
	vars->img_1.img = mlx_xpm_file_to_image(vars->mlx,
			"textures/wall.xpm", now, now + 1);
	vars->img_0.img = mlx_xpm_file_to_image(vars->mlx,
			"textures/tile.xpm", now, now + 1);
	vars->img_c.img = mlx_xpm_file_to_image(vars->mlx,
			"textures/item.xpm", now, now + 1);
	set_imgs(vars);
}

int	render_next_frame(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < vars->height)
	{
		x = 0;
		while (x < vars->width)
		{
			draw_icon(vars, x, y, vars->pptr[y][x]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	return (0);
}
