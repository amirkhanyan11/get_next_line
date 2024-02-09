/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:48:04 by aamirkha          #+#    #+#             */
/*   Updated: 2024/02/09 20:59:21 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_read(int fd, char *buffer, char *str, char **next_line)
{
	if (ft_strchr(str, '\n'))
		return (str);
	char *n;
	while (read(fd, buffer, BUFFER_SIZE))
	{
		n = ft_strchr(buffer, '\n');
		if (n)
		{
			*next_line = n + 1;
			str = ft_strjoin(str, buffer);
			break;
		}
		str = ft_strjoin(str, buffer);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	static char *next;
	static char buffer[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';

	if (!str)
	{
		str = malloc(1);
		if (!str)
			return (NULL);
		str[0] = '\0';
	}

	else
	{
		//free(str);
		if (next < buffer + ft_strlen(buffer))
		{
			str = ft_strdup(next);
			next = ft_strchr(next + 1, '\n') + 1;
		}
		else
		{
			str = malloc(1);
			if (!str)
				return (NULL);
			str[0] = '\0';
		}
	}

	str = ft_read(fd, buffer, str, &next);

	return (str);
}
