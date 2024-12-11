/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:23:19 by tsomacha          #+#    #+#             */
/*   Updated: 2024/12/05 19:33:40 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str && str[len] != '\0')
		len++;
	return (len);
}

ssize_t	ft_haschar(char *str, int c)
{
	size_t	count;

	count = 0;
	while (str && str[count])
	{
		if (str[count] == (char)c)
			return (count);
		count++;
	}
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	ssize_t	len1;
	ssize_t	len2;
	ssize_t	count;
	ssize_t	step;
	char	*result;

	count = 0;
	step = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = malloc((len1 + len2 + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (s1 && s1[count] && count < len1)
	{
		result[count] = s1[count];
		count++;
	}
	while (s2 && s2[step] && step < len2)
	{
		result[count + step] = s2[step];
		step++;
	}
	result[count + step] = '\0';
	return (result);
}

char	*ft_strdup(char *str)
{
	char	*result;
	size_t	len;
	int		count;

	count = 0;
	if (!str || !*str)
		return (NULL);
	len = ft_strlen(str);
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (str && str[count])
	{
		result[count] = str[count];
		count++;
	}
	result[count] = '\0';
	return (result);
}

char	*ft_extract_line(char *str, int c)
{
	ssize_t	count;
	ssize_t	index;
	char	*new_line;

	count = 0;
	index = ft_haschar(str, c);
	if (index < 0)
		return (NULL);
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
