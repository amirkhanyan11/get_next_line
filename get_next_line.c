/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:48:04 by aamirkha          #+#    #+#             */
/*   Updated: 2024/02/08 22:06:59 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

static char * ft_read(int fd, char *buffer)
{
	char *str;

	str = malloc(1);
	str[0] = '\0';
	while (read(fd, buffer, BUFFER_SIZE))
	{
		str = ft_strjoin(str, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	//printf("%s", str);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*ptr;
	char buffer[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';
	ptr = ft_read(fd, buffer);
	//printf("%s", ptr);
	return (ptr);
}


