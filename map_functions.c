/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revan-wy <revan-wy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 10:41:42 by revan-wy          #+#    #+#             */
/*   Updated: 2018/09/16 10:44:21 by revan-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

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

void	map_line_error(char *filename)
{
	ft_putstr("Map size inconsistent across lines of map file: ");
	ft_putstr(filename);
	ft_putchar('\n');
	exit(0);
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

