/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revan-wy <revan-wy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 15:09:16 by revan-wy          #+#    #+#             */
/*   Updated: 2018/09/11 21:00:52 by revan-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "libft.h"
# include "mlx.h"

# define win_width 640
# define win_height 460

typedef struct  s_data
{
    void *gsci;
    void *win;
    double posX;
    double posY;
    double dirX;
    double dirY;
    double planeX;
    double planeY;
}               t_data;

#endif