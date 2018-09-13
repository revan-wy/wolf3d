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

# define win_width 640.0
# define win_height 460.0
# define mapWidth 24
# define mapHeight 24
# define up 126
# define left 123
# define down 125
# define right 124
# define moveSpeed 0.2
# define rotSpeed 0.2

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
    //int ***worldMap;
    int x;
    void *gsci;
    void *win;
    int *worldMap;
}               t_data;

#endif