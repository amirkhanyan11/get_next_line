/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:48:04 by aamirkha          #+#    #+#             */
/*   Updated: 2024/02/10 20:39:07 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_read(int fd, char *buffer, char *str, char **next_line)
{
	if (ft_strchr(str, '\n'))
		return (str);
	char *n;
	int x;
	while ((x = read(fd, buffer, BUFFER_SIZE)))
	{
		if ((n = ft_strchr(buffer, '\n')))
		{
			*next_line = n + 1;
			str = ft_strjoin(str, buffer, x);
			return (str);
		}
		str = ft_strjoin(str, buffer, x);
	}
	if (strcmp(str, ""))
		return (str);
	//printf("%s", str);
	free(str);
	return (NULL);
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
		if (next > buffer && (next - buffer) < ft_strlen(buffer))
		{
			str = ft_strdup(next);
			next = NULL;
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
	//printf("%s", str);
	return (str);
}
