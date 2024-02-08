/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:48:04 by aamirkha          #+#    #+#             */
/*   Updated: 2024/02/09 02:49:48 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char * ft_read(int fd, char *buffer)
{
	char *str;

	str = malloc(1);
	str[0] = '\0';
	while (read(fd, buffer, BUFFER_SIZE))
	{
		if (ft_strchr(buffer, '\n'))
		{
			str = ft_strjoin(str, buffer);
			break ;
		}
		str = ft_strjoin(str, buffer);
	}
	//printf("%s", str);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*ptr;
	char *tmp;
	static char buffer[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';

	if ((ptr) && (tmp = ft_strchr(buffer, '\n')))
	{
		ptr = ft_strcpy(ptr, tmp + 1);
		if (ft_strchr(ptr, '\n'))
			return ptr;
	}
	else
		free(ptr);
	ptr = ft_read(fd, buffer);
	//printf("%s", ptr);
	return (ptr);
}


