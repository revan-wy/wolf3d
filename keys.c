/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revan-wy <revan-wy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 10:42:21 by revan-wy          #+#    #+#             */
/*   Updated: 2018/09/16 11:28:03 by revan-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		key_event(int key_code, void *data)
{
	if (key_code == 53)
		exit(0);
	else if (key_code == UP)
		update_with_up(data);
	else if (key_code == LEFT)
		update_with_left(data);
	else if (key_code == DOWN)
		update_with_down(data);
	else if (key_code == RIGHT)
		update_with_right(data);
	return (0);
}

void	update_with_up(t_data *data)
{
	if (!*(data->worldmap + (int)(data->posx + data->dirx * MOVESPEED) *
			data->colmax + (int)data->posy))
		data->posx += data->dirx * MOVESPEED;
	if (!*(data->worldmap + (int)data->posx * data->colmax + (int)(data->posy +
			data->diry * MOVESPEED)))
		data->posy += data->diry * MOVESPEED;
	draw(data);
}

void	update_with_left(t_data *data)
{
	data->olddirx = data->dirx;
	data->dirx = data->dirx * cos(ROTSPEED) - data->diry * sin(ROTSPEED);
	data->diry = data->olddirx * sin(ROTSPEED) + data->diry * cos(ROTSPEED);
	data->oldplanex = data->planex;
	data->planex = data->planex * cos(ROTSPEED) - data->planey * sin(ROTSPEED);
	data->planey = data->oldplanex * sin(ROTSPEED) + data->planey *
			cos(ROTSPEED);
	draw(data);
}

void	update_with_down(t_data *data)
{
	if (*(data->worldmap + (int)(data->posx - data->dirx * MOVESPEED) *
			data->colmax + (int)data->posy) == 0)
		data->posx -= data->dirx * MOVESPEED;
	if (*(data->worldmap + (int)data->posx * data->colmax + (int)(data->posy -
			data->diry * MOVESPEED)) == 0)
		data->posy -= data->diry * MOVESPEED;
	draw(data);
}

void	update_with_right(t_data *data)
{
	data->olddirx = data->dirx;
	data->dirx = data->dirx * cos(-ROTSPEED) - data->diry * sin(-ROTSPEED);
	data->diry = data->olddirx * sin(-ROTSPEED) + data->diry * cos(-ROTSPEED);
	data->oldplanex = data->planex;
	data->planex = data->planex * cos(-ROTSPEED) - data->planey *
		sin(-ROTSPEED);
	data->planey = data->oldplanex * sin(-ROTSPEED) + data->planey *
			cos(-ROTSPEED);
	draw(data);
}
