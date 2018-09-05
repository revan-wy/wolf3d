/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revan-wy <revan-wy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 00:58:23 by revan-wy          #+#    #+#             */
/*   Updated: 2018/08/09 20:47:44 by revan-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**ret;
	int		i;
	int		j;
	size_t	w_count;

	if (!s || !(ret = (char**)malloc(sizeof(char*) * (ft_getwcntsd(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			w_count = 0;
			while (s[i + (int)w_count] && (s[i + (int)w_count] != c))
				w_count++;
			if (!(ret[j++] = ft_strsub(s, i, w_count)))
				return (NULL);
			i = i + (int)w_count;
		}
	}
	ret[j] = (NULL);
	return (ret);
}
