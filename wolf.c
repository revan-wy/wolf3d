/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revan-wy <revan-wy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 09:51:43 by revan-wy          #+#    #+#             */
/*   Updated: 2018/09/15 22:13:08 by revan-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	set_up_window(t_data *data)
{
	data->gsci = mlx_init();
	data->win = mlx_new_window(data->gsci, WIN_WIDTH, WIN_HEIGHT,
			"#hearmehowl");
}

void	draw_vert_line(t_data *data)
{
	int y;

	y = data->drawstart;
	while (y <= data->drawend)
		mlx_pixel_put(data->gsci, data->win, data->x, y++, data->colour);
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

int	key_event(int key_code, void *data)
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

int	exit_hook(t_data *data)
{
	mlx_destroy_window(data->gsci, data->win);
	exit(0);
}

void	check_argc(int argc)
{
	if (argc != 2)
	{
		write(1, "Enter name of one map file\n", 27);
		exit(0);
	}
}

void	map_line_error(char *filename)
{
	ft_putstr("Map size inconsistent across lines of map file: ");
	ft_putstr(filename);
	ft_putchar('\n');
	exit(0);
}

void	get_size_of_map(t_data *data)
{
	int		fd;
	char	*pnl;
	int		res;

	if (!(fd = open(data->filename, O_RDONLY)) || fd == -1)
	{
		write(1, "File name not valid\n", 20);
		exit(0);
	}
	res = 1;
	while (res)
	{
		res = get_next_line(fd, &pnl);
		if (ft_strlen(pnl))
			data->rowmax++;
		if (!data->colmax)
			data->colmax = ft_getwcntsd(pnl, ' ');
		else if (res)
			if (ft_getwcntsd(pnl, ' ') != data->colmax)
				map_line_error(data->filename);
		free(pnl);
	}
	close(fd);
}

void	read_map(t_data *data)
{
	char		*pnl;
	char		**one_line_fields;
	t_read_map	read_map;

	read_map.i = -1;
	read_map.j = 0;
	read_map.fd = open(data->filename, O_RDONLY);
	read_map.res = 1;
	while (read_map.res && ++read_map.i < data->rowmax)
	{
		read_map.j = 0;
		read_map.res = get_next_line(read_map.fd, &pnl);
		one_line_fields = ft_strsplit(pnl, ' ');
		while (*one_line_fields != NULL && read_map.j < data->colmax)
		{
			*(data->worldmap + read_map.i * data->colmax + read_map.j) =
					ft_atoi(one_line_fields[read_map.j]);
			free(one_line_fields[read_map.j++]);
		}
		free(pnl);
		free(one_line_fields);
	}
}

void	create_world(t_data *data)
{
	int i;

	check_argc(data->argc);
	get_size_of_map(data);
	i = 0;
	data->worldmap = (int*)ft_memalloc(sizeof(int) * data->rowmax *
			data->colmax);
	while (i < data->rowmax)
	{
		data->worldmap[i] = (*data->worldmap + data->colmax * i);
		i++;
	}
	read_map(data);
}

t_data	*create_data(int argc, char **argv)
{
	t_data *data;

	data = ft_memalloc(sizeof(t_data));
	data->posx = 22;
	data->posy = 12;
	data->dirx = -1;
	data->diry = 0;
	data->planex = 0;
	data->planey = 0.66;
	data->argc = argc;
	data->filename = argv[1];
	create_world(data);
	return (data);
}

int	main(int argc, char **argv)
{
	t_data *data;

	data = create_data(argc, argv);
	set_up_window(data);
	draw(data);
	mlx_hook(data->win, 2, 0, key_event, data);
	mlx_hook(data->win, 17, 0, exit_hook, data);
	mlx_loop(data->gsci);
}
