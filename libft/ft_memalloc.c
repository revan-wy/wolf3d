/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revan-wy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 14:32:20 by revan-wy          #+#    #+#             */
/*   Updated: 2018/06/04 13:55:13 by revan-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t n)
{
	char *res;

	if (!(res = (char*)malloc(n)))
		return (NULL);
	ft_memset(res, 0, n);
	return ((void*)res);
}
