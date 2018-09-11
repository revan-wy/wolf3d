/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revan-wy <revan-wy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 09:51:43 by revan-wy          #+#    #+#             */
/*   Updated: 2018/09/11 21:02:34 by revan-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#include <stdio.h> //forbidden header file

t_data *init_t_data()
{
	t_data *ret;
	//int element_count = 8;
	int i;
	
	ret = ft_memalloc(sizeof(t_data));
	i = 1;
	/*ret->gsci = ft_memalloc(sizeof(double) * element_count);
	ret->win = ret->gsci + i++;
	ret->posX = ret->gsci + i++;
	ret->posY = ret->gsci + i++;
	ret->dirX = ret->gsci + i++;
	ret->dirY = ret->gsci + i++;
	ret->planeX = ret->gsci + i++;
	ret->planeY = ret->gsci + i++;*/
	printf("Element count in struct is %d\n", i);
	return (ret);
}

void set_up_window(t_data *data)
{
	data->gsci = mlx_init();
	data->win = mlx_new_window(data->gsci, win_width, win_height, "#makemehowl");
}

int main()
{
	t_data *data;
	
	data = init_t_data();
	
	data->posX = 22;
	data->posY = 12;
	data->dirX = -1;
	data->dirY = 0;
	data->planeX = 0;
	data->planeY = 0.66;
	
	set_up_window(data);
	
	
	printf("%f\n", data->posX);
	printf("%f\n", data->posY);
	printf("%f\n", data->dirX);
	printf("%f\n", data->dirY);
	printf("%f\n", data->planeX);
	printf("%f\n", data->planeY);
	printf("%lu\n", sizeof(double));
	printf("%lu\n", sizeof(int));
	printf("%lu\n", sizeof(float));
	printf("%lu\n", sizeof(void*));
	while(1);
	return (0);
	
}