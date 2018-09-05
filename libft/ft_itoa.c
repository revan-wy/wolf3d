/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revan-wy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 03:18:00 by revan-wy          #+#    #+#             */
/*   Updated: 2018/06/04 07:12:04 by revan-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*res;
	int				len;
	unsigned int	abs;

	abs = ft_absval(n);
	len = ft_logrndup(abs);
	if (n < 0)
		len++;
	if (!(res = ft_strnew(len)))
		return (NULL);
	res += (len - 1);
	*res = '0' + (abs % 10);
	abs /= 10;
	while (abs != 0)
	{
		*--res = '0' + (abs % 10);
		abs /= 10;
	}
	if (n < 0)
		*--res = '-';
	return (res);
}
