/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:22:57 by tsomacha          #+#    #+#             */
/*   Updated: 2024/12/06 19:11:37 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*ft_get_newline(char **buffer, int index)
{
	char	*line;
	char	*new_buffer;

	line = NULL;
	new_buffer = NULL;
	if (!buffer || !*buffer)
		return (line);
	line = ft_extract_line(*buffer, '\n');
	new_buffer = ft_strdup(&(*buffer)[index + 1]);
	free(*buffer);
	*buffer = new_buffer;
	return (line);
}

static char	*ft_readingbuffer(int fd)
{
	ssize_t	byte_read;
	char	*content;
	char	buffer[BUFFER_SIZE + 1];

	byte_read = 0;
	content = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	byte_read = read(fd, buffer, BUFFER_SIZE);
	if (byte_read <= 0)
	{
		free(content);
		return (NULL);
	}
	buffer[byte_read] = '\0';
	content = ft_strdup(buffer);
	return (content);
}

char	*get_next_line(int fd)
{
	ssize_t		index;
	char		*line;
	char		*content;
	static char	*holder_buffer;

	index = -1;
	line = NULL;
	content = NULL;
	if (holder_buffer)
		index = ft_haschar(holder_buffer, '\n');
	if (index != -1)
	{
		line = ft_get_newline(&holder_buffer, index);
		return (line);
	}
	while (index == -1)
	{
		content = ft_readingbuffer(fd);
		if (!content)
			break ;
		line = ft_strjoin(holder_buffer, content);
		free(holder_buffer);
		free(content);
		holder_buffer = ft_strdup(line);
		free(line);
		index = ft_haschar(holder_buffer, '\n');
	}
	if (index != -1)
	{
		line = ft_get_newline(&holder_buffer, index);
		return (line);
	}
	if (holder_buffer && *holder_buffer)
	{
		line = ft_strdup(holder_buffer);
		free(holder_buffer);
		holder_buffer = NULL;
		return (line);
	}
	return (line);
}
