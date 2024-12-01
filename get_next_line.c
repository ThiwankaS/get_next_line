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

char	*ft_readingbuffer(int fd)
{
	// 03. Declare and initialize necessary variables.
	int			byte_read;
	char		*content;
	static char	buffer[BUFFER_SIZE + 1];
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
	char	*content;
	char	*holder;
	int		index;
	// 01. First, check if BUFFER_SIZE is greater than 0. If it is equal to or less than 0, return NULL.
	// 02. Then, check if the file descriptor (fd) is valid (greater than or equal to 0). If not, return NULL.
	if(BUFFER_SIZE <= 0 || fd < 0)
		content = NULL;
	else
		content = ft_readingbuffer(fd);
	holder = malloc((BUFFER_SIZE + 1) * sizeof(char));
	index = ft_has_newline(content);
	if(index != -1)
	{
		ft_memcpy(holder, content, index);
		free(content);
	}
	holder[index] = '\n';
	holder[index + 1] = '\0';
	return(holder);
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
