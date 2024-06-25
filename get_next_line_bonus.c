/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosabir <yosabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:52:54 by yosabir           #+#    #+#             */
/*   Updated: 2024/02/25 12:06:22 by yosabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void static	ft_free(char **str)
{
	free(*str);
	*str = NULL;
}

static int	check(const char *s)
{
	int	i;

	i = 0;
	while (*s && *s != '\n')
	{
		i++;
		s++;
	}
	return (i);
}

static char	*get_read(int fd, char *line)
{
	char		*buff;
	int			count;

	buff = malloc((size_t)BUFFER_SIZE + 1);
	if (!buff)
		return (free(line), NULL);
	if (!line)
		line = ft_strdup("");
	while (!(ft_strchr(line, '\n')))
	{
		count = read(fd, buff, BUFFER_SIZE);
		if (count == 0)
			break ;
		if (count == -1)
			return (free(line), free(buff), NULL);
		buff[count] = '\0';
		line = ft_strjoin(line, buff);
	}
	ft_free(&buff);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line[O_MAX];
	char		*str;
	char		*tmp;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
	{
		if (line[fd])
			ft_free(&line[fd]);
		return (NULL);
	}
	line[fd] = get_read(fd, line[fd]);
	if (!line[fd])
		return (NULL);
	if (!(*line[fd]))
	{
		ft_free(&line[fd]);
		return (NULL);
	}
	i = check(line[fd]) + 1;
	str = ft_substr(line[fd], 0, i);
	tmp = line[fd];
	line[fd] = ft_substr(line[fd], i, ft_strlen(line[fd]) - i + 1);
	ft_free(&tmp);
	return (str);
}
