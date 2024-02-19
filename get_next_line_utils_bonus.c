/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:02:14 by aamirkha          #+#    #+#             */
/*   Updated: 2024/02/19 13:43:04 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_read(int const fd, char **const memory)
{
	size_t	seen;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	buffer[BUFFER_SIZE] = '\0';
	seen = 0;
	while (!ft_frankenstein(*memory, '\n', ft_strchr))
	{
		seen = read(fd, buffer, BUFFER_SIZE);
		buffer[seen] = '\0';
		if (!seen)
			break ;
		ft_append(memory, buffer);
	}
	free(buffer);
}

char	*ft_frankenstein(char *str, char const c, t_Mode mode)
{
	if (mode == ft_strchr)
	{
		while (*str)
			if (*(str++) == c)
				return (str - 1);
		return (NULL);
	}
	else if (mode == ft_strlen)
	{

		while (*str && *str != c)
			str++;
		return (str);
	}
	else if (mode == ft_dealloc)
		free(str);
	return (NULL);
}

void	ft_append(char **const memory, char const *const buffer)
{
	char	*target;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	target = (char *)malloc((ft_frankenstein((char *)(*memory), 0, ft_strlen)
				- (*memory)) + (ft_frankenstein((char *)buffer, 0, ft_strlen)
				+ 1 - buffer));
	if (!target)
		return ;
	while ((*memory)[i] || buffer[j])
	{
		if ((*memory)[i])
			target[k++] = (*memory)[i++];
		else
			target[k++] = buffer[j++];
	}
	target[k] = '\0';
	free((void *)(*memory));
	(*memory) = target;
}

void	ft_mutate(char **const memory, char const *const newline)
{
	char	*dest;
	size_t	i;

	dest = (char *)malloc(ft_frankenstein((char *)newline, 0, ft_strlen)
			- newline + 1);
	if (!dest)
		return ;
	i = 0;
	while (newline[i])
	{
		dest[i] = newline[i];
		i++;
	}
	dest[i] = '\0';
	free((void *)(*memory));
	*memory = dest;
}

char	*ft_fetch(char **const memory)
{
	char	*next_line;
	size_t	i;

	if (**memory == '\0')
	{
		free(*memory);
		*memory = NULL;
		return (NULL);
	}
	next_line = (char *)malloc(ft_frankenstein((char *)(*memory), '\n',
				ft_strlen) + 1 - *memory);
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
