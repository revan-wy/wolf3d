/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revan-wy <revan-wy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 15:09:16 by revan-wy          #+#    #+#             */
/*   Updated: 2018/09/13 20:17:09 by revan-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "libft.h"
# include "mlx.h"
# include <math.h>

# define WIN_WIDTH 640.0
# define WIN_HEIGHT 460.0
# define MAPWIDTH 24
# define MAPHEIGHT 24
# define UP 126
# define LEFT 123
# define DOWN 125
# define RIGHT 124
# define MOVESPEED 0.2
# define ROTSPEED 0.1

typedef struct  s_data
{
    double cameraX;
    double deltaDistX;
    double deltaDistY;
    double dirX;
    double dirY;
    double oldDirX;
    double oldPlaneX;
    double perpWallDist;
    double planeX;
    double planeY;
    double posX;
    double posY;
    double rayDirX;
    double rayDirY;
    double rayPosX;
    double rayPosY;
    double sideDistX;
    double sideDistY;
    int colour;
    int drawEnd;
    int drawStart;
    int hit;
    int lineHeight;
    int mapX;
    int mapY;
    int side;
    int stepX;
    int stepY;
    int *worldMap;
    int x;
    void *gsci;
    void *win;
}               t_data;

#endif
