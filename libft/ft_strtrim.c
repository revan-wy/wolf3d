/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revan-wy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 13:54:07 by revan-wy          #+#    #+#             */
/*   Updated: 2018/06/04 22:31:42 by revan-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*res;
	int		wsaf;
	int		wsab;

	if (!s)
		return (NULL);
	wsaf = 0;
	while (s[wsaf] == ' ' || s[wsaf] == '\n' || s[wsaf] == '\t')
		wsaf++;
	wsab = ft_strlen(s) - 1;
	while ((wsab > wsaf) && (s[wsab] == ' ' || s[wsab] == '\n' ||
			s[wsab] == '\t'))
		wsab--;
	if (wsab < wsaf)
		return (ft_strsub(s, 0, 0));
	return (res = ft_strsub(s, wsaf, wsab - wsaf + 1));
}
