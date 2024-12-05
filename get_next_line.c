/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:22:57 by tsomacha          #+#    #+#             */
/*   Updated: 2024/12/04 17:53:42 by tsomacha         ###   ########.fr       */
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

static char	*ft_readingbuffer(int fd)
{
	ssize_t	byte_read;
	char	*content;
	char	buffer[BUFFER_SIZE + 1];

	byte_read = 0;
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
	content = ft_strdup(buffer);
	return (content);
}

char	*get_next_line(int fd)
{
	ssize_t		index;
	char		*line;
	char		*content;
	static char	*holder_buffer;

	index = 0;
	line = NULL;
	content = NULL;
	if(!holder_buffer)
		holder_buffer = ft_strdup("");
	index = ft_haschar(holder_buffer, '\n');
	if(index != -1)
	{
		line = ft_extract_newline(holder_buffer, '\n');
		content = ft_strdup(&holder_buffer[index + 1]);
		free(holder_buffer);
		holder_buffer = ft_strdup(content);
		return (line);
	}
	content = ft_readingbuffer(fd);
	if(!content)
		return (NULL);
	while(content && holder_buffer)
	{
		holder_buffer = ft_strjoin(holder_buffer, content);
		free(content);
		index = ft_haschar(holder_buffer, '\n');
		if(index != -1)
			break;
		content = ft_readingbuffer(fd);
	}
	if(index != -1)
	{
		line = ft_extract_newline(holder_buffer, '\n');
		content = ft_strdup(&holder_buffer[index + 1]);
		free(holder_buffer);
		holder_buffer = ft_strdup(content);
		return (line);
	}
	if(holder_buffer && *holder_buffer)
		return(holder_buffer);
	return (NULL);
}

//01. Read the file using ft_readingbuffer store the output in content
//02. Check content is valid data
//03. Store the data in Holder_buffer
//04. Check for presence of \n if yes extract new line from it
//05. If not read another chunk unsing ft_readingbuffer
//06. Repeat the step 04 and 05 untill reach the EOF
//07. Check for presence of \n if yes extract new line from it
//08. If yes extract a new line and return save the remaining inside Holder_Buffer
//09. if not return the entire thing store inside Holder_Buffer and Make empty the Holder_Buffer after return.
//When the BUFFER_SIZE is larger than the file size, fd will become -1 in next call
//This will cause to print the first line only
//Need to handel this

//Adding chunk of data to Holder_Buffer using content
//While loop should run untill the Holder_Buffer get \n character inside
//Extract new line unsing ft_extract_line
