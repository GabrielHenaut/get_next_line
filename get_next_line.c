/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 22:40:07 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/06/09 01:54:20 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*init_line(char *line_cache, int fd)
{
	char	*buf;
	int		read_rtn;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	read_rtn = 1;
	while (!ft_strchr(line_cache, '\n') && read_rtn != 0)
	{
		read_rtn = read(fd, buf, BUFFER_SIZE);
		if (read_rtn == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_rtn] = '\0';
		line_cache = ft_strjoin(line_cache, buf);
	}
	free(buf);
	return (line_cache);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*line_cache;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line_cache = init_line(line_cache, fd);
	if (!line_cache)
		return (NULL);
	line = get_line(line_cache);
	line_cache = clear_line(line_cache);
	return (line);
}
