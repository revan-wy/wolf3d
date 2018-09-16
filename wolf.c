/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revan-wy <revan-wy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 09:51:43 by revan-wy          #+#    #+#             */
/*   Updated: 2018/09/16 10:47:22 by revan-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	check_argc(int argc)
{
	if (argc != 2)
	{
		write(1, "Enter name of one map file\n", 27);
		exit(0);
	}
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
