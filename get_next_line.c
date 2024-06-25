/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosabir <yosabir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:17:52 by yosabir           #+#    #+#             */
/*   Updated: 2024/02/25 12:07:03 by yosabir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		return (free(line), line = NULL);
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
	static char	*line;
	char		*str;
	char		*tmp;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (free(line), line = NULL);
	line = get_read(fd, line);
	if (!line)
		return (NULL);
	if (!(*line))
	{
		ft_free(&line);
		return (NULL);
	}
	i = check(line) + 1;
	str = ft_substr(line, 0, i);
	tmp = line;
	line = ft_substr(line, i, ft_strlen(line) - i + 1);
	ft_free(&tmp);
	return (str);
}
