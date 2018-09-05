/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revan-wy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 16:06:39 by revan-wy          #+#    #+#             */
/*   Updated: 2018/06/04 21:39:13 by revan-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		to_go;
	size_t		dlen;

	d = dst;
	s = src;
	to_go = n;
	while (to_go-- != 0 && *d != 0)
		d++;
	dlen = d - dst;
	to_go = n - dlen;
	if (to_go == 0)
		return (dlen + ft_strlen(s));
	while (*s != 0)
	{
		if (to_go != 1)
		{
			*d++ = *s;
			to_go--;
		}
		s++;
	}
	*d = 0;
	return (dlen + (s - src));
}
