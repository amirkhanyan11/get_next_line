/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:48:04 by aamirkha          #+#    #+#             */
/*   Updated: 2024/02/15 17:01:53 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*memory[OPEN_MAX];
	char		*newline;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!(memory[fd]))
	{
		(memory[fd]) = malloc(1);
		if (!(memory[fd]))
			return (NULL);
		(memory[fd])[0] = '\0';
	}
	else
	{
		newline = ft_frankenstein((memory[fd]), '\n', ft_strchr);
		if (newline)
			ft_mutate(&(memory[fd]), newline + 1);
		else
		{
			free((memory[fd]));
			return (((memory[fd]) = NULL));
		}
	}
	ft_read(fd, &(memory[fd]));
	return (ft_fetch(&(memory[fd])));
}
