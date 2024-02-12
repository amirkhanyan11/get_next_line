/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:48:04 by aamirkha          #+#    #+#             */
/*   Updated: 2024/02/12 21:26:07 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void ft_read(int fd, char **memory)
{
	size_t seen;
	char buffer[BUFFER_SIZE + 1];
	buffer[BUFFER_SIZE] = '\0';

	seen = 0;
	while (!ft_strchr(*memory, '\n'))
	{
		seen = read(fd, buffer, BUFFER_SIZE);
		buffer[seen] = '\0';
		if(!seen)
			break ;
		*memory = ft_append(*memory, buffer);
	}
	printf("memory : %s\n", *memory);

}

char	*get_next_line(int fd)
{
	static char	*memory;
	char *next_line;
	void *tmp;

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
		char *nl;
		tmp = memory;
		if ((nl = ft_strchr(memory, '\n')))
		{
			memory = ft_strdup(nl + 1);
			free(tmp);
		}
		else
		{
			free(tmp);
			return (NULL);
		}
	}
	ft_read(fd, &memory);

	next_line = ft_strdup(memory);

	if (!strcmp(memory, ""))
	{
		free(next_line);
		free(memory);
		memory = NULL;
		return NULL;
	}

	//printf("%s", next_line);
	return (next_line);
}
