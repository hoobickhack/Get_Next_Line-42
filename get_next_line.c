/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isouaidi <isouaidi@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:35:03 by isouaidi          #+#    #+#             */
/*   Updated: 2023/04/19 18:01:52 by isouaidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*nextline(char *save)
{
	int		i;
	int		j;
	char	*newsave;

	i = 0;
	j = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (0);
	}
	newsave = malloc(sizeof(char) * ((ft_strlen(save) - i + 1)));
	i++;
	while (save[i])
		newsave[j++] = save[i++];
	save[j] = '\0';
	return (newsave);
}

char	*thisline(char *save)
{
	int		i;
	char	*line;

	i = 0;
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
		line[i] = '\n';
	else
		line[i] = '\0';
	return (line);
}

int main()
{
	printf("%s", thisline("ilyes salut\ndkos[p;de"));
}

/*char	*get_next_line(int fd)
{
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
 }*/
