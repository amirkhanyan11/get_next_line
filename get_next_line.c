/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:48:04 by aamirkha          #+#    #+#             */
/*   Updated: 2024/02/14 01:21:20 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void ft_read(int fd, char **memory)
{
	size_t seen;
	char *buffer = malloc(BUFFER_SIZE + 1);
	buffer[BUFFER_SIZE] = '\0';

	seen = 0;
	while (!ft_strchr(*memory, '\n'))
	{
		seen = read(fd, buffer, BUFFER_SIZE);
		buffer[seen] = '\0';
		if(!seen)
			break ;
		ft_append(memory, buffer);
	//	printf("%d\n", strcmp(*memory, "\n\n\n\n\n"));
	}
	free(buffer);
	//printf("memory : %s\n", *memory);
}

char	*f(const char * const str)
{
	char	*dest;
	size_t	i;

	if (!str)
		return (NULL);
	dest = (char *)malloc(ft_strlen(str) + 1);
	if (!dest)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		dest[i] = str[i];
		i++;
	}
	if(str[i] == '\n')
		dest[i++] = '\n';
	dest[i] = '\0';
	return (dest);
}



char	*get_next_line(int fd)
{
	static char	*memory;
	char *next_line;
	char *ind;
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
		tmp = memory;
		if ((ind = ft_strchr(memory, '\n')))
		{
			memory = ft_strdup(ind + 1);
			//printf("%d\n", strcmp(memory, "\n\n\n\n"));
			free(tmp);
		}
		else
		{
			free(memory);
			memory = NULL;
			return (NULL);
		}
	}
	ft_read(fd, &memory);

	next_line = f(memory);

	if (!strcmp(memory, ""))
	{
		free(next_line); // ???
		free(memory);
		memory = NULL;
		return NULL;
	}


	//printf("%s", next_line);
	return (next_line);
}
