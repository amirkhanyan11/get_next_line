/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:48:04 by aamirkha          #+#    #+#             */
/*   Updated: 2024/02/15 17:05:02 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*memory;
	char		*newline;

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
		newline = ft_frankenstein(memory, '\n', ft_strchr);
		if (newline)
			ft_mutate(&memory, newline + 1);
		else
		{
			free(memory);
			return ((memory = NULL));
		}
	}
	ft_read(fd, &memory);
	return (ft_fetch(&memory));
}
