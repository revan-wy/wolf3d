/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revan-wy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 19:23:12 by revan-wy          #+#    #+#             */
/*   Updated: 2018/06/04 21:59:28 by revan-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *hstck, const char *ndl)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (ndl[0] == '\0')
		return ((char*)hstck);
	while (hstck[i] != '\0')
	{
		while (hstck[i + j] == ndl[j])
		{
			if (ndl[j + 1] == '\0')
				return ((char*)&hstck[i]);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}
