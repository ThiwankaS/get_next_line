/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:22:57 by tsomacha          #+#    #+#             */
/*   Updated: 2024/12/01 16:05:14 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_extract_newline(char *str, int c)
{
	ssize_t	count;
	ssize_t	index;
	char	*new_line;

	index = ft_haschar(str, c);
	count = 0;
	if (index < 0)
		return (str);
	new_line = malloc((index + 2) * sizeof(char));
	if (!new_line)
		return (NULL);
	while (str && str[count] && count < index)
		new_line[count++] = str[count];
	new_line[count] = '\n';
	new_line[count + 1] = '\0';
	return (new_line);
}

static char	*ft_readingbuffer(int fd)
{
	ssize_t	byte_read;
	char	*content;
	char	buffer[BUFFER_SIZE + 1];

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	content = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!content)
		return (NULL);
	byte_read = read(fd, buffer, BUFFER_SIZE);
	if (byte_read <= 0)
	{
		free(content);
		return (NULL);
	}
	buffer[byte_read] = '\0';
	ft_memcpy(content, buffer, byte_read);
	return (content);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*content;
	static char	*holder_buffer;
	ssize_t		index;
	ssize_t		length;

	index = 0;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	content = ft_readingbuffer(fd);
	holder_buffer = ft_strjoin(holder_buffer, content);
	index = ft_haschar(holder_buffer, '\n');
	while (index == -1 && content)
	{
		content = ft_readingbuffer(fd);
		holder_buffer = ft_strjoin(holder_buffer, content);
		index = ft_haschar(holder_buffer, '\n');
	}
	if (!content)
		return (NULL);
	length = ft_strlen(holder_buffer);
	line = ft_extract_newline(holder_buffer, '\n');
	content = ft_strchr(holder_buffer, '\n');
	ft_memcpy(holder_buffer, &content[1], length);
	return (line);
}
