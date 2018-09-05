/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revan-wy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 18:49:14 by revan-wy          #+#    #+#             */
/*   Updated: 2018/06/04 14:03:28 by revan-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *sc1;
	const unsigned char *sc2;

	sc1 = s1;
	sc2 = s2;
	if (n != 0)
	{
		while (n != 0)
		{
			if (*sc1++ != *sc2++)
				return (*--sc1 - *--sc2);
			n--;
		}
	}
	return (0);
}
