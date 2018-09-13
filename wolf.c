/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revan-wy <revan-wy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 09:51:43 by revan-wy          #+#    #+#             */
/*   Updated: 2018/09/13 21:49:45 by revan-wy         ###   ########.fr       */
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

void draw(t_data *data)
{
	mlx_clear_window(data->gsci, data->win);
	
	data->x = 0;
	while(data->x < win_width)
	{
		data->cameraX = 2 * data->x / win_width - 1;
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
			//*(data + i * COLS + j)

			//if (worldMap[data->mapX][data->mapY] > 0)
			if (*(data->worldMap + data->mapX * mapWidth + data->mapY))
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

		//*(data + i * COLS + j)
		//if (worldMap[data->mapX][data->mapY] == 1)
		if (*(data->worldMap + data->mapX * mapHeight + data->mapY) == 1)
			data->colour = 0x00FF0000; //red
		else if (*(data->worldMap + data->mapX * mapHeight + data->mapY) == 2)
			data->colour = 0x0000FF00; //green
		else if (*(data->worldMap + data->mapX * mapHeight + data->mapY) == 3)
			data->colour = 0x000000FF; //blue
		else if (*(data->worldMap + data->mapX * mapHeight + data->mapY) == 4)
			data->colour = 0x00FFFFFF; //white
		else
			data->colour = 0x00FFFF00; //yellow
		
		if (data->side == 1)
			data->colour = data->colour / 2;

		draw_vert_line(data);


		
		data->x++;
	}

}

void update_with_up(t_data *data)
{
	//int *worldMap = data->worldMap;
	//*(data + i * COLS + j)
	//if(!*(worldMap[(int)(data->posX + data->dirX * moveSpeed)][(int)(data->posY)])
	if (!*(data->worldMap + (int)(data->posX + data->dirX * moveSpeed) * mapWidth + (int)data->posY))	
		data->posX += data->dirX * moveSpeed;
	//if(!worldMap[(int)(data->posX)][(int)(data->posY + data->dirY * moveSpeed)])
	if (!*(data->worldMap + (int)data->posX * mapWidth + (int)(data->posY + data->dirY * moveSpeed)))
		data->posY += data->dirY * moveSpeed;
	draw(data);
}

void update_with_left(t_data *data)
{
	//both camera direction and camera plane must be rotated
	data->oldDirX = data->dirX;
	data->dirX = data->dirX * cos(rotSpeed) - data->dirY * sin(rotSpeed);
	data->dirY = data->oldDirX * sin(rotSpeed) + data->dirY * cos(rotSpeed);
	data->oldPlaneX = data->planeX;
	data->planeX = data->planeX * cos(rotSpeed) - data->planeY * sin(rotSpeed);
	data->planeY = data->oldPlaneX * sin(rotSpeed) + data->planeY * cos(rotSpeed);
	draw(data);
}

void update_with_down(t_data *data)
{
	//*(data + i * COLS + j)
	//if(worldMap[int(posX - dirX * moveSpeed)][int(posY)] == false)
	if (*(data->worldMap + (int)(data->posX - data->dirX * moveSpeed) * mapWidth + (int)data->posY) == 0)
		data->posX -= data->dirX * moveSpeed;
	//if(worldMap[int(posX)][int(posY - dirY * moveSpeed)] == false)
	if (*(data->worldMap + (int)data->posX * mapWidth + (int)(data->posY - data->dirY * moveSpeed)) == 0)
		data->posY -= data->dirY * moveSpeed;
	draw(data);
}

void update_with_right(t_data *data)
{
	//both camera direction and camera plane must be rotated
	data->oldDirX = data->dirX;
	data->dirX = data->dirX * cos(-rotSpeed) - data->dirY * sin(-rotSpeed);
	data->dirY = data->oldDirX * sin(-rotSpeed) + data->dirY * cos(-rotSpeed);
	data->oldPlaneX = data->planeX;
	data->planeX = data->planeX * cos(-rotSpeed) - data->planeY * sin(-rotSpeed);
	data->planeY = data->oldPlaneX * sin(-rotSpeed) + data->planeY * cos(-rotSpeed);
	draw(data);
}

int key_event(int key_code, void *data)
{
	if (key_code == 53)
		exit (0);
	else if (key_code == up)
		update_with_up(data);
	else if (key_code == left)
		update_with_left(data);
	else if (key_code == down)
		update_with_down(data);
	else if (key_code == right)
		update_with_right(data);
	return (0);
}

int exit_hook(t_data *data)
{
	mlx_destroy_window(data->gsci, data->win);
	exit(0);
}

int main()
{
	t_data *data;
	data = init_t_data();
	int worldMap[mapWidth][mapHeight] =
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
	
	data->worldMap = &worldMap[0][0];

	
	
	data->posX = 22;
	data->posY = 12;
	data->dirX = -1;
	data->dirY = 0;
	data->planeX = 0;
	data->planeY = 0.66;
	
	set_up_window(data);
	
	draw(data);
	
	mlx_key_hook(data->win, key_event, data);
	mlx_hook(data->win, 17, 0, exit_hook, data);
	mlx_loop(data->gsci);
	return (0);
	
}