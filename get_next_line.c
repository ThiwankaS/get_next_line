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
#include <stdio.h>

static char	*ft_extract_newline(const char *str, int c)
{
	ssize_t	count;
	ssize_t	index;
	char *new_line;

	index = ft_haschar(str,c);
	if(index < 0)
		return (NULL);
	new_line = malloc((index + 1) * sizeof(char));
	if(!new_line)
		return (NULL);
	while(str && str[count] && ++count < index)
		new_line[count] = str[count];
	return (new_line);
}

static char	*ft_readingbuffer(int fd)
{
	// 03. Declare and initialize necessary variables.
	ssize_t	byte_read;
	char	*content;
	char	buffer[BUFFER_SIZE + 1];
	// 04. Allocate memory dynamically to hold the content read. If memory allocation fails, return NULL.
	content = malloc((BUFFER_SIZE + 1)* sizeof(char));
	if(!content)
		return (NULL);
	byte_read = read(fd, buffer, BUFFER_SIZE);
	if(byte_read <= 0)
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
	char	*line = NULL;
	char	*content;
	static char	*holder_buffer;
	// 01. First, check if BUFFER_SIZE is greater than 0. If it is equal to or less than 0, return NULL.
	// 02. Then, check if the file descriptor (fd) is valid (greater than or equal to 0). If not, return NULL.
	if(BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	content = ft_readingbuffer(fd);
	printf("Content 1 : %s\n", content);
	printf("Content length : %ld\n", ft_strlen(content));
	//ft_memcpy(holder_buffer, content, ft_strlen(content));
	//printf("Holder buffer 1 : %s\n", holder_buffer);
	// line = ft_strchr(holder_buffer,'\n');
	// while(!line && content)
	// {
	// 	content = ft_readingbuffer(fd);
	// 	holder_buffer = ft_strjoin_free(holder_buffer, content);
	// 	line = ft_strchr(holder_buffer,'\n');
	// }
	// line = ft_extract_newline(holder_buffer, '\n');
	// content = ft_strchr(holder_buffer,'\n');
	// ft_memcpy(holder_buffer, content, ft_strlen(content));
	// free(content);
	return(line);
}

// 01. First, check if BUFFER_SIZE is greater than 0. If it is equal to or less than 0, return NULL.
// 02. Then, check if the file descriptor (fd) is valid (greater than or equal to 0). If not, return NULL.
// 03. Declare and initialize necessary variables.
// 04. Allocate memory dynamically to hold the content read. If memory allocation fails, return NULL.
// 05. Traverse through the returned string to check for the presence of a newline character.
// 06. If a newline character is found, return a string up to and including the newline character.
// 07. If no newline character is found, store the content in another string holder and read the next chunk of data.
// 08. Repeat steps 04 to 06 until a newline character is found or the end of the file is reached.
// 09. If no newline character is present in any part of the file, the function should return the entire content at once.
// 10. Ensure proper memory management and return NULL in case of errors.
