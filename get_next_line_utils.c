/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:23:19 by tsomacha          #+#    #+#             */
/*   Updated: 2024/12/01 15:56:49 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			count;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	count = 0;
	if (n == 0)
		return (dest);
	ptr1 = (unsigned char *)src;
	ptr2 = (unsigned char *)dest;
	while (count < n)
	{
		ptr2[count] = ptr1[count];
		count++;
	}
	return (dest);
}

int	ft_has_newline(char *str)
{
	int count;

	count = 0;
	while(str[count] != '\0')
	{
		if(str[count] == '\n')
			return (count);
		count++;
	}
	return (-1);
}
