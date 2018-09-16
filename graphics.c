/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revan-wy <revan-wy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 10:35:01 by revan-wy          #+#    #+#             */
/*   Updated: 2018/09/16 11:28:50 by revan-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	draw(t_data *data)
{
	mlx_clear_window(data->gsci, data->win);
	data->x = 0;
	while (data->x < WIN_WIDTH)
	{
		data->camerax = 2 * data->x / WIN_WIDTH - 1;
		data->rayposx = data->posx;
		data->rayposy = data->posy;
		data->raydirx = data->dirx + data->planex * data->camerax;
		data->raydiry = data->diry + data->planey * data->camerax;
		data->mapx = data->rayposx;
		data->mapy = data->rayposy;
		data->deltadistx = sqrt(1 + (data->raydiry * data->raydiry) /
				(data->raydirx * data->raydirx));
		data->deltadisty = sqrt(1 + (data->raydirx * data->raydirx) /
				(data->raydiry * data->raydiry));
		data->hit = 0;
		calc_pre_cast_values(data);
		calc_ray_termination_location(data);
		calc_ray_termination_distance_and_wall_size(data);
		colour_picker(data);
		draw_vert_line(data);
		data->x++;
	}
}

void	draw_vert_line(t_data *data)
{
	int y;

	y = data->drawstart;
	while (y <= data->drawend)
		mlx_pixel_put(data->gsci, data->win, data->x, y++, data->colour);
}

int		exit_hook(t_data *data)
{
	mlx_destroy_window(data->gsci, data->win);
	exit(0);
}

void	set_up_window(t_data *data)
{
	data->gsci = mlx_init();
	data->win = mlx_new_window(data->gsci, WIN_WIDTH, WIN_HEIGHT,
			"#iamwolfhearmehowl");
}
