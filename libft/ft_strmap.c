/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revan-wy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 08:00:56 by revan-wy          #+#    #+#             */
/*   Updated: 2018/06/04 21:41:25 by revan-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*res;
	size_t	n;
	int		i;

	if (!s || !f)
		return (NULL);
	i = 0;
	n = ft_strlen(s);
	if (!(res = (char*)malloc(n + 1)))
		return (NULL);
	while (*s)
		res[i++] = f(*s++);
	res[n] = 0;
	return (res);
}
