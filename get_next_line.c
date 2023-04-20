/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:35:03 by isouaidi          #+#    #+#             */
/*   Updated: 2023/04/20 19:11:58 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*next_line(char *save)
{
	int		i;
	int		j;
	char	*newsave;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	newsave = malloc(sizeof(char) * ((ft_strlen(save) - i + 1)));
	i++;
	j = 0;
	while (save[i])
		newsave[j++] = save[i++];
	free(save);
	newsave[j] = '\0';
	return (newsave);
}

char	*this_line(char *save)
{
	int		i;
	char	*line;

	i = 0;
	if (!save)
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_free(char *buffer, char *reserve)
{
	char	*temp;

	temp = ft_strjoin(buffer, reserve);
	free(buffer);
	return (temp);
}

char	*read_all(int fd, char *res)
{
	char	*buffer;
	int		bytes;

	if (!res)
	res = ft_strdup("");
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	bytes = 42;
	while (bytes && !ft_strchr(res, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			free(res);
			return (NULL);
		}
		buffer[bytes] = 0;
		res = ft_free(res, buffer);
	}
	free(buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	char static	*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = read_all(fd, buf);
	if (!buf)
		return (NULL);
	line = this_line(buf);
	buf = next_line(buf);
	if (line[0] == '\0')
	{
		free(buf);
		free(line);
		return (NULL);
	}
	return (line);
}
