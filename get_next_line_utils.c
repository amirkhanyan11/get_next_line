/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:02:14 by aamirkha          #+#    #+#             */
/*   Updated: 2024/02/14 20:15:46 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *const str, char const c)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	if (str[i] == c)
		return (str + i);
	return (NULL);
}

int	ft_strlen(char const *const str)
{
	int	len;

	if (!str)
		return (-1);
	len = 0;
	while (str[len])
		len++;
	return (len);
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
	target = (char *)malloc(ft_strlen((*memory)) + ft_strlen(buffer) + 1);
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

	dest = (char *)malloc(ft_strlen(newline) + 1);
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
