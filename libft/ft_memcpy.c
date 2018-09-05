/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revan-wy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 12:12:20 by revan-wy          #+#    #+#             */
/*   Updated: 2018/05/26 16:29:09 by revan-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *src_c;
	unsigned char *dst_c;

	src_c = (unsigned char*)src;
	dst_c = (unsigned char*)dst;
	while (n-- > 0)
		*dst_c++ = *src_c++;
	return ((void*)dst);
}
