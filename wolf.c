/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revan-wy <revan-wy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 09:51:43 by revan-wy          #+#    #+#             */
/*   Updated: 2018/09/12 21:15:56 by revan-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdio.h> //forbidden header file

t_data *init_t_data()
{
	t_data *ret;
	
	ret = ft_memalloc(sizeof(t_data));
	return (ret);
}

void set_up_window(t_data *data)
{
	data->gsci = mlx_init();
	data->win = mlx_new_window(data->gsci, win_width, win_height, "#makemehowl");
}

void draw_vert_line(t_data *data)
{
	int y;
	
	y = data->drawStart;
	while (y <= data->drawEnd)
		mlx_pixel_put(data->gsci,data->win,data->x,y++,data->colour);
}

int main()
{
	t_data *data;
	int worldMap[mapWidth][mapHeight]=
	{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};

	
	data = init_t_data();
	
	data->posX = 22;
	data->posY = 12;
	data->dirX = -1;
	data->dirY = 0;
	data->planeX = 0;
	data->planeY = 0.66;
	
	set_up_window(data);
	
	data->x = 0;
	while(data->x < win_width)
	{
		data->cameraX = 2 * data->x / (double)win_width - 1;
		data->rayPosX = data->posX;
		data->rayPosY = data->posY;
		data->rayDirX = data->dirX + data->planeX * data->cameraX;
		data->rayDirY = data->dirY + data->planeY * data->cameraX;
		printf("%f\n", data->cameraX);
		
		data->mapX = data->rayPosX;
		data->mapY = data->rayPosY;
		
		data->deltaDistX = sqrt(1 + (data->rayDirY * data->rayDirY) / (data->rayDirX * data->rayDirX));
		data->deltaDistY = sqrt(1 + (data->rayDirX * data->rayDirX) / (data->rayDirY * data->rayDirY));
		
		data->hit = 0;
		
		if (data->rayDirX < 0)
		{
			data->stepX = -1;
			data->sideDistX = (data->rayPosX - data->mapX) * data->deltaDistX;
		}
		else
		{
			data->stepX = 1;
			data->sideDistX = (data->mapX + 1.0 - data->rayPosX) * data->deltaDistX;
		}
		if (data->rayDirY < 0)
		{
			data->stepY = -1;
			data->sideDistY = (data->rayPosY - data->mapY) * data->deltaDistY;
		}
		else
		{
			data->stepY = 1;
			data->sideDistY = (data->mapY + 1.0 - data->rayPosY) * data->deltaDistY;
		}

		while (data->hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if (data->sideDistX < data->sideDistY)
			{
				data->sideDistX += data->deltaDistX;
				data->mapX += data->stepX;
				data->side = 0;
			}
			else
			{
				data->sideDistY += data->deltaDistY;
				data->mapY += data->stepY;
				data->side = 1;
			}
			//Check if ray has hit a wall
			if (worldMap[data->mapX][data->mapY] > 0)
				data->hit = 1;
		}

		if (data->side == 0)
			data->perpWallDist = fabs((data->mapX - data->rayPosX + (1 - data->stepX) / 2) / data->rayDirX);
		else
			data->perpWallDist = fabs((data->mapY - data->rayPosY + (1 - data->stepY) / 2) / data->rayDirY);

		data->lineHeight = fabs(win_height / data->perpWallDist);

		data->drawStart = -data->lineHeight / 2 + win_height / 2;
		if (data->drawStart < 0)
			data->drawStart = 0;
		data->drawEnd = data->lineHeight / 2 + win_height / 2;
		if (data->drawEnd >= win_height)
			data->drawEnd = win_height - 1;

		if (worldMap[data->mapX][data->mapY] == 1)
			data->colour = 0x00FF0000; //red
		else if (worldMap[data->mapX][data->mapY] == 2)
			data->colour = 0x0000FF00; //green
		else if (worldMap[data->mapX][data->mapY] == 3)
			data->colour = 0x000000FF; //blue
		else if (worldMap[data->mapX][data->mapY] == 4)
			data->colour = 0x00FFFFFF; //white
		else
			data->colour = 0x00FFFF00; //yellow
		
		if (data->side == 1)
			data->colour = data->colour / 2;

		draw_vert_line(data);


		
		data->x++;
	}
	mlx_loop(data->gsci);
	return (0);
	
}