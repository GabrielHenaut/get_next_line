/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 20:15:48 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/06/09 01:53:33 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

char	*get_line(char *line)
{
	size_t	i;
	size_t	j;
	char	*rtn;

	i = 0;
	j = -1;
	if (!line[i])
		return (NULL);
	while (line[i] != '\n' && line[i])
		i++;
	rtn = (char *)malloc(sizeof(char) * (i + 2));
	if (!rtn)
		return (NULL);
	while (line[++j] && line[j] != '\n')
		rtn[j] = line[j];
	if (line[j] == '\n')
	{
		rtn[j] = line[j];
		j++;
	}
	rtn[j] = '\0';
	return (rtn);
}

char	*clear_line(char *line)
{
	int		i;
	int		j;
	char	*rtn;

	i = 0;
	j = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	rtn = (char *)malloc(sizeof(char) * (ft_strlen(line) - i + 1));
	if (!rtn)
		return (NULL);
	while (line[++i])
	{
		rtn[j] = line[i];
		j++;
	}
	rtn[j] = '\0';
	free(line);
	return (rtn);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	free(s1);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != c && s[i])
		i++;
	if (s[i] == c)
		return ((char *)&s[i]);
	return (NULL);
}
