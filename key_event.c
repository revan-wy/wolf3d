/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revan-wy <revan-wy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 16:21:00 by revan-wy          #+#    #+#             */
/*   Updated: 2018/08/29 17:15:26 by revan-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void up_event()
{
	move player&camera forward;
	draw screen;
}

void down_event()
{
	move player&camera backward;
	draw screen;
}

void left_event()
{
	rotate player&camera left;
	draw screen;
}

void right_event()
{
	rotate player&camera right;
	draw screen;
}

int	key_event(int keycode, int **param)
{
	param = 0;

	if (keycode == 53)
		exit(0);
	else if (keycode == arrow_up)
		up_event();
	else if (keycode == arrow_down)
		down_event();
	else if (keycode == arrow_left)
		left_event();
	else if (keycode == arrow_right)
		right_event();
	return (1);
}
