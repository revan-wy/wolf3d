/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revan-wy <revan-wy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 17:49:45 by revan-wy          #+#    #+#             */
/*   Updated: 2018/09/08 13:53:03 by revan-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void vert_line(int x, int drawStart, int drawEnd, int colour, t_data *data)
{
	//static old;
	
	while (drawStart <= drawEnd)
	{
		mlx_pixel_put(data->gsci, data->win, x, drawStart++, colour);
		//ft_putnbr(colour);
		//ft_putchar('\n');
	}
}

void	draw_screen(t_data *data, int worldMap[MAPWIDTH][MAPHEIGHT])
{
	int x;
	int colour; 

	mlx_clear_window(data->gsci, data->win);
	x = 0;
	//colour = 0x00FF0000;
	while (x < WINWIDTH)
	{
		/*data->posX = 22; 
		data->posY = 12; //x and y start position
		data->dirX = -1; 
		data->dirY = 0;  //initial direction vector*/
		double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane
		double cameraX = 2 * x / WINWIDTH - 1; //x-coordinate in camera space
		double rayPosX = data->posX;
		double rayPosY = data->posY;
		double rayDirX = data->dirX + planeX * cameraX;
		double rayDirY = data->dirY + planeY * cameraX;
		//which box of the map we're in
		int mapX = (int)(rayPosX);
		int mapY = (int)(rayPosY);
		//length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;
		//length of ray from one x or y-side to next x or y-side
		double deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
		double deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
		double perpWallDist;
		//what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;
		int hit = 0; //was there a wall hit?
		int side; //was a NS or a EW wall hit?
		//calculate step and initial sideDist
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (rayPosX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - rayPosX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (rayPosY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - rayPosY) * deltaDistY;
		}
		//perform DDA
		while (hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if (worldMap[mapX][mapY] > 0) hit = 1;
		}
		//Calculate distance projected on camera direction (oblique distance will give fisheye effect!)
		if (side == 0)
		perpWallDist = fabs((mapX - rayPosX + (1 - stepX) / 2) / rayDirX);
		else
		perpWallDist = fabs((mapY - rayPosY + (1 - stepY) / 2) / rayDirY);
		//Calculate height of line to draw on screen
		int lineHeight = abs((int)(WINHEIGHT / perpWallDist));
		//calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + WINHEIGHT / 2;
		if (drawStart < 0) drawStart = 0;
		int drawEnd = lineHeight / 2 + WINHEIGHT / 2;
		if (drawEnd >= WINHEIGHT) drawEnd = WINHEIGHT - 1;
		//choose wall color
		
		//build colour chooser
		//if (worldMap[mapX][mapY] == 1)
			colour = 0x00FF0000;
		//else if 
		
		
		/*ColorRGB color;
		switch(worldMap[mapX][mapY])
		{
			case 1:  color = RGB_Red;  break; //red
			case 2:  color = RGB_Green;  break; //green
			case 3:  color = RGB_Blue;   break; //blue
			case 4:  color = RGB_White;  break; //white
			default: color = RGB_Yellow; break; //yellow
		}*/
		
		
		//give x and y sides different brightness
		if (side == 1) 
			colour = colour / 2;
		//draw the pixels of the stripe as a vertical line
		vert_line(x, drawStart, drawEnd, colour, data);
		x++;
	}
}

void update_pos_up_arrow(t_data *data, int worldMap[MAPWIDTH][MAPHEIGHT])
{
	ft_putnbr((int)data->dirX);
	ft_putchar(' ');
    ft_putnbr((int)data->posX);
	ft_putchar(' ');
    ft_putnbr((int)data->posY);
	ft_putchar(' ');
    ft_putnbr((int)data->dirY);	
	ft_putchar('\n');
	if(!worldMap[(int)(data->posX + data->dirX * MOVE_SPEED)][(int)(data->posY)]) 
	  	data->posX += data->dirX * MOVE_SPEED;
	if(!worldMap[(int)(data->posX)][(int)(data->posY + data->dirY * MOVE_SPEED)]) 
		data->posY += data->dirY * MOVE_SPEED;
	draw_screen(data, worldMap);
}

int key_event(int key_code, void **data, int worldMap[MAPWIDTH][MAPHEIGHT])
{
	if (1) //(key_code == UP_ARROW)
		update_pos_up_arrow(*data, worldMap);
	/*else if (key_code == DOWN_ARROW)
		update_pos_down_arrow();
	else if (key_code == LEFT_ARROW)
		update_rot_left_arrow();
	else if (key_code == RIGHT_ARROW)
		update_rot_right_arrow();*/
	if (key_code == ESCAPE_KEY)
		exit(0);
	return (1);
}

void set_initial_data(t_data *data)
{
	data->dirX = -1;
    data->posX = 22;
    data->posY = 12;
    data->dirY = 0;
}

int	main()
{
	//void *gsci;
	//void *win;
	t_data data;
	t_data *param;

	data.gsci = mlx_init();
	data.win = mlx_new_window(data.gsci, WINWIDTH, WINHEIGHT, "#MAKEMEHOWL");
	param = &data;
	

	int worldMap[MAPWIDTH][MAPHEIGHT]=
	{
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	
	set_initial_data(param);
	draw_screen(param, worldMap);
	mlx_loop_hook(data.win, key_event, &param);
	mlx_loop(data.gsci);
}