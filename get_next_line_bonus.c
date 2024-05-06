/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconstan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 05:46:58 by aconstan          #+#    #+#             */
/*   Updated: 2023/12/19 05:47:00 by aconstan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_extract_first_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	if (buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*ft_remove_first_line(char *buffer)
{
	char	*lines;
	char	*newline_loc;

	int (i) = 0;
	newline_loc = ft_strchr(buffer, '\n');
	if (!newline_loc || !buffer)
	{
		free(buffer);
		return (NULL);
	}
	lines = ft_calloc((ft_strlen(newline_loc) + 1), sizeof(char));
	if (!lines)
	{
		free(buffer);
		return (NULL);
	}
	newline_loc++;
	while (newline_loc[i])
	{
		lines[i] = newline_loc[i];
		i++;
	}
	lines[i] = '\0';
	free(buffer);
	return (lines);
}

char	*ft_join_free(char *str1, char *str2)
{
	char	*temp;

	temp = ft_strjoin(str1, str2);
	free(str1);
	return (temp);
}

char	*ft_extract_buffer(int fd, char *buffer)
{
	int (read_statut) = 1;
	char *(stash) = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		buffer = ft_calloc(1, 1);
	if (!buffer)
		return (NULL);
	if (!stash)
		return (NULL);
	while (read_statut > 0)
	{
		read_statut = read(fd, stash, BUFFER_SIZE);
		if (read_statut == -1)
		{
			free(stash);
			free(buffer);
			return (NULL);
		}
		stash[read_statut] = 0;
		buffer = ft_join_free(buffer, stash);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(stash);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buffer[fd] == NULL || !ft_strchr(buffer[fd], '\n'))
		buffer[fd] = ft_extract_buffer(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_extract_first_line(buffer[fd]);
	buffer[fd] = ft_remove_first_line(buffer[fd]);
	return (line);
}
