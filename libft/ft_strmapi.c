/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revan-wy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 12:26:30 by revan-wy          #+#    #+#             */
/*   Updated: 2018/06/04 21:42:40 by revan-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	size_t			n;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = 0;
	n = ft_strlen(s);
	if (!(res = (char*)malloc(n + 1)))
		return (NULL);
	while (*s)
	{
		res[i] = f(i, *s++);
		i++;
	}
	res[n] = 0;
	return (res);
}
