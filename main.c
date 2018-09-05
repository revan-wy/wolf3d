/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revan-wy <revan-wy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 17:49:45 by revan-wy          #+#    #+#             */
/*   Updated: 2018/09/03 17:50:15 by revan-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void draw_screen()
{
	
}

int main()
{
	void *gsci;
	void *win;
	
	gsci = mlx_init();
	win = mlx_new_window(gsci, WINWIDTH, WINHEIGHT, "#MAKEMEHOWL");
	
	create environment
		graphic system interface
		create map in memory
		set player position
		set camera position
	
	draw screen //this will be the initial starting view of the camera
	mlx_key_hook(gsci, key_event, param);
	mlx_loop_hook(gsci, reg_loop, param);
	mlx_loop(gsci);
}