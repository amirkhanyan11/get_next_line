/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:02:14 by aamirkha          #+#    #+#             */
/*   Updated: 2024/02/09 20:35:59 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *str, char const c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	return (NULL);
}

int	ft_strlen(const char * const str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char  *ft_strjoin(char const * const self, char const * rhv)
{
	char * tgt;
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	tgt = (char *)malloc(ft_strlen(self) + ft_strlen(rhv) + 1);
	if (!tgt)
		return ((char *)self);
	while (self[i] || (rhv[j] && rhv[j] != '\n'))
	{
		if (self[i])
		{
			tgt[k] = self[i++];
		}
		else
			tgt[k] = rhv[j++];
		k++;
	}
	if (rhv[j] == '\n')
	{
		tgt[k] = '\n';
		tgt[k + 1] = '\0';
	}
	else
		tgt[k] = '\0';
	free((void *)self);
	return (tgt);
}



char	*ft_strdup(const char * const str)
{
	char	*dest;
	size_t	i;

	dest = (char *)malloc(ft_strlen(str) + 1);
	if (!dest)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		dest[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		dest[i] = '\n';
		dest[i + 1] = '\0';
	}
	else
		dest[i] = '\0';
	return (dest);
}
