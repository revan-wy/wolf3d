/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revan-wy <revan-wy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 10:37:09 by revan-wy          #+#    #+#             */
/*   Updated: 2018/09/16 11:28:57 by revan-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	calc_pre_cast_values(t_data *data)
{
	if (data->raydirx < 0)
	{
		data->stepx = -1;
		data->sidedistx = (data->rayposx - data->mapx) * data->deltadistx;
	}
	else
	{
		data->stepx = 1;
		data->sidedistx = (data->mapx + 1.0 - data->rayposx) *
				data->deltadistx;
	}
	if (data->raydiry < 0)
	{
		data->stepy = -1;
		data->sidedisty = (data->rayposy - data->mapy) * data->deltadisty;
	}
	else
	{
		data->stepy = 1;
		data->sidedisty = (data->mapy + 1.0 - data->rayposy) *
				data->deltadisty;
	}
}

void	calc_ray_termination_distance_and_wall_size(t_data *data)
{
	if (data->side == 0)
		data->perpwalldist = fabs((data->mapx - data->rayposx +
				(1 - data->stepx) / 2) / data->raydirx);
	else
		data->perpwalldist = fabs((data->mapy - data->rayposy +
				(1 - data->stepy) / 2) / data->raydiry);
	data->lineheight = fabs(WIN_HEIGHT / data->perpwalldist);
	data->drawstart = -data->lineheight / 2 + WIN_HEIGHT / 2;
	if (data->drawstart < 0)
		data->drawstart = 0;
	data->drawend = data->lineheight / 2 + WIN_HEIGHT / 2;
	if (data->drawend >= WIN_HEIGHT)
		data->drawend = WIN_HEIGHT - 1;
}

void	calc_ray_termination_location(t_data *data)
{
	while (data->hit == 0)
	{
		if (data->sidedistx < data->sidedisty)
		{
			data->sidedistx += data->deltadistx;
			data->mapx += data->stepx;
			data->side = 0;
		}
		else
		{
			data->sidedisty += data->deltadisty;
			data->mapy += data->stepy;
			data->side = 1;
		}
		if (*(data->worldmap + data->mapx * data->colmax + data->mapy))
			data->hit = 1;
	}
}

void	colour_picker(t_data *data)
{
	if (data->side)
	{
		if (data->raydiry < 0)
			data->colour = 0x00FF0000;
		else
			data->colour = 0x000000FF;
	}
	else
	{
		if (data->raydirx < 0)
			data->colour = 0x00FFFF00;
		else
			data->colour = 0x0000FF00;
	}
}
