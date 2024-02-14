/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:48:04 by aamirkha          #+#    #+#             */
/*   Updated: 2024/02/14 17:51:23 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_read(int fd, char **memory)
{
	size_t	seen;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	buffer[BUFFER_SIZE] = '\0';
	seen = 0;
	while (!ft_strchr(*memory, '\n'))
	{
		seen = read(fd, buffer, BUFFER_SIZE);
		buffer[seen] = '\0';
		if (!seen)
			break ;
		ft_append(memory, buffer);
	}
	free(buffer);
}

char	*fetch(char **memory)
{
	char	*next_line;
	size_t	i;

	if (**memory == '\0')
	{
		free(*memory);
		*memory = NULL;
		return (NULL);
	}
	next_line = (char *)malloc(ft_strlen((*memory)) + 1);
	if (!next_line)
		return (0);
	i = 0;
	while ((*memory)[i] && (*memory)[i] != '\n')
	{
		next_line[i] = (*memory)[i];
		i++;
	}
	if ((*memory)[i] == '\n')
		next_line[i++] = '\n';
	next_line[i] = '\0';
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	*memory;
	char		*ind;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!memory)
	{
		memory = malloc(1);
		if (!memory)
			return (NULL);
		memory[0] = '\0';
	}
	else
	{
		ind = ft_strchr(memory, '\n');
		if (ind)
			ft_mutate(&memory, ind + 1);
		else
		{
			free(memory);
			return ((memory = NULL));
		}
	}
	ft_read(fd, &memory);
	return (fetch(&memory));
}
