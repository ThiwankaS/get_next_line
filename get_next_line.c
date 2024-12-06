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

static char	*ft_extract_newline(char *str, int c)
{
	ssize_t	count;
	ssize_t	index;
	char	*new_line;

	count = 0;
	index = ft_haschar(str, c);
	if (index < 0)
		return (str);
	new_line = malloc((index + 2) * sizeof(char));
	if (!new_line)
		return (NULL);
	while (str && str[count] && count < index)
	{
		new_line[count] = str[count];
		count++;
	}
	new_line[count] = '\n';
	new_line[count + 1] = '\0';
	return (new_line);
}
static char	*ft_get_newline(char **buffer, int index)
{
	char	*line;
	char	*new_buffer;

	line = NULL;
	new_buffer = NULL;
	if(!buffer || !*buffer || index < 0)
	line = ft_extract_newline(*buffer, '\n');
	if(!line)
		return (NULL);
	new_buffer = ft_strdup(&(*buffer)[index + 1]);
	if(!new_buffer)
	{
		free(line);
		return (NULL);
	}
	free(*buffer);
	*buffer = new_buffer;
	free(new_buffer);
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
		line = ft_extract_newline(holder_buffer, '\n');
		content = ft_strdup(&holder_buffer[index + 1]);
		free(holder_buffer);
		holder_buffer = ft_strdup(content);
		free(content);
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
