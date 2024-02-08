/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:48:04 by aamirkha          #+#    #+#             */
/*   Updated: 2024/02/09 03:31:29 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char * ft_read(int fd, char *buffer, char *str)
{
	while (read(fd, buffer, BUFFER_SIZE) && !ft_strchr(str, '\n'))
	{
		str = ft_strjoin(str, buffer);
	}
	//printf("%s", str);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char *tmp;
	static char buffer[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';

	if (!str)
	{
		str = malloc(1);
		str[0] = '\0';
	}

	if (str)
	{
		free(str);
		if (tmp = ft_strchr(buffer, '\n'))
			str = ft_strdup(tmp + 1);
		else
			str = ft_strdup(buffer);
		if (ft_strchr(str, '\n'))
			return str;
	}

	str = ft_read(fd, buffer, str);
	//printf("%s", str);
	return (str);
}


