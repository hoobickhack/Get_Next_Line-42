/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:35:03 by isouaidi          #+#    #+#             */
/*   Updated: 2023/04/25 13:23:14 by isouaidi         ###   ########.fr       */
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
	newsave = malloc(sizeof(char) * (ft_strlen(save) - i + 1));
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

char	*ft_free(char *save, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(save, buffer);
	free(save);
	return (temp);
}

char	*read_all(int fd, char *save)
{
	char	*buffer;
	int		bytes;

	if (!save)
		save = ft_strdup("");
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	bytes = -6;
	while (bytes != 0 && !ft_strchr(save, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			free(save);
			return (NULL);
		}
		buffer[bytes] = '\0';
		save = ft_free(save, buffer);
	}
	free(buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	char static	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = read_all(fd, save);
	if (!save)
		return (NULL);
	line = this_line(save);
	save = next_line(save);
	if (line[0] == '\0')
	{
		free(save);
		free(line);
		return (NULL);
	}
	return (line);
}
