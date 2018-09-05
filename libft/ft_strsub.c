/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revan-wy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 13:33:22 by revan-wy          #+#    #+#             */
/*   Updated: 2018/06/04 22:01:18 by revan-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t n)
{
	char	*res;
	int		i;

	if (!s)
		return (NULL);
	if (!(res = (char*)malloc(n + 1)))
		return (NULL);
	i = 0;
	while ((i <= (int)n) && s[start + i])
	{
		res[i] = s[start + i];
		i++;
	}
	res[n] = 0;
	return (res);
}
