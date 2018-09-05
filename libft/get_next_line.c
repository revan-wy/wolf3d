/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: revan-wy <revan-wy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 13:07:38 by revan-wy          #+#    #+#             */
/*   Updated: 2018/08/09 19:31:00 by revan-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static int	read_loop(char **first_new_line, char **workspace, int fd)
{
	int		res;
	char	*buff;
	char	*to_clear;

	res = 1;
	buff = (char*)ft_memalloc(sizeof(char) * BUFF_SIZE + 1);
	while (!(*first_new_line = ft_strchr(*workspace, '\n')))
	{
		res = read(fd, buff, BUFF_SIZE);
		to_clear = *workspace;
		*workspace = ft_strjoin(*workspace, buff);
		free(to_clear);
		ft_strclr(buff);
		if (!res)
			break ;
	}
	if (buff)
		ft_strdel(&buff);
	return (res);
}

static void	cut_and_sort(char **line, char **first_new_line, char **workspace)
{
	char	*to_free;

	*line = ft_strnew(*first_new_line - *workspace);
	if (*first_new_line - *workspace)
		ft_strncpy(*line, *workspace, (*first_new_line - *workspace));
	to_free = *workspace;
	*workspace = ft_strsub(*workspace, *first_new_line - *workspace + 1,
			ft_strlen(*workspace) - (*first_new_line - *workspace + 1));
	free(to_free);
}

int			get_next_line(const int fd, char **line)
{
	static char *workspace;
	int			res;
	char		*first_new_line;

	first_new_line = NULL;
	if (!workspace || fd < 0 || read(fd, NULL, 0) < 0)
		if (!(workspace = ft_strnew(0)) || fd < 0 || read(fd, NULL, 0) < 0)
			return (-1);
	res = read_loop(&first_new_line, &workspace, fd);
	if (first_new_line)
		cut_and_sort(line, &first_new_line, &workspace);
	else
	{
		*line = workspace;
		workspace = ft_strnew(0);
	}
	if (res || ft_strlen(*line) || ft_strlen(workspace))
		return (1);
	else
		return (0);
}
