/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewanki <taewanki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 19:53:30 by taewanki          #+#    #+#             */
/*   Updated: 2023/07/25 15:16:55 by taewanki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_MAP_H
# define DRAW_MAP_H
# include "check_map.h"
# include "libft/libft.h"
# include <mlx.h>
# define PHOTO_SIZE 50

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	t_data	img;
	t_data	img_p;
	t_data	img_e;
	t_data	img_1;
	t_data	img_0;
	t_data	img_c;
	char	**pptr;
	int		width;
	int		height;
	int		now_x;
	int		now_y;
	int		cnt;
}				t_vars;

void	set_vars(t_vars *vars, char **pptr);
int		render_next_frame(t_vars *vars);
void	free_vars(t_vars *vars);
int		destory_win(t_vars *vars);
int		close_win(int keycode, t_vars *vars);
int		collect_all(t_vars *vars);
void	keycode_split(t_vars *vars, int keycode);
int		move_left(t_vars *vars);
int		move_right(t_vars *vars);
int		move_down(t_vars *vars);
int		move_up(t_vars *vars);
#endif