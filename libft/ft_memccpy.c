/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revan-wy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 05:28:25 by revan-wy          #+#    #+#             */
/*   Updated: 2018/05/31 10:00:55 by revan-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dsti;
	const unsigned char *srci;
	unsigned char		cc;

	cc = c;
	if (n)
	{
		dsti = dst;
		srci = src;
		while (n--)
		{
			if ((*dsti++ = *srci++) == cc)
				return ((void*)dsti);
		}
	}
	return (0);
}
