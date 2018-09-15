/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revan-wy <revan-wy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 15:09:16 by revan-wy          #+#    #+#             */
/*   Updated: 2018/09/15 22:08:45 by revan-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <unistd.h>
# include <fcntl.h>

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

typedef struct	s_data
{
	char	*filename;
	double	camerax;
	double	deltadistx;
	double	deltadisty;
	double	dirx;
	double	diry;
	double	olddirx;
	double	oldplanex;
	double	perpwalldist;
	double	planex;
	double	planey;
	double	posx;
	double	posy;
	double	raydirx;
	double	raydiry;
	double	rayposx;
	double	rayposy;
	double	sidedistx;
	double	sidedisty;
	int		argc;
	int		colmax;
	int		colour;
	int		drawend;
	int		drawstart;
	int		hit;
	int		lineheight;
	int		mapx;
	int		mapy;
	int		rowmax;
	int		side;
	int		stepx;
	int		stepy;
	int		*worldmap;
	int		x;
	void	*gsci;
	void	*win;
}				t_data;

typedef struct s_read_map
{
	int		fd;
	int		res;
	int i;
	int j;
} t_read_map;

#endif
