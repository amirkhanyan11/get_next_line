/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:02:14 by aamirkha          #+#    #+#             */
/*   Updated: 2024/02/13 00:22:11 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *str, char const c)
{
	int i;

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

int	ft_strlen(const char * const str)
{
	int	len;

	if (!str)
		return (-1);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

char  *ft_append(char **self, char const * rhv)
{
	char * tgt;
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	j = 0;
	k = 0;
	tgt = (char *)malloc(ft_strlen((*self)) + ft_strlen(rhv) + 1);
	if (!tgt)
		return ((char *)(*self));
	while ((*self)[i] || rhv[j])
	{
		if ((*self)[i])
			tgt[k] = (*self)[i++];
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
	free((void *)(*self));
	(*self) = tgt;
	return (*self);
}

char	*ft_strdup(const char * const str)
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
	if (str[i] == '\n')
	{
		dest[i] = '\n';
		dest[i + 1] = '\0';
	}
	else
		dest[i] = '\0';
	return (dest);
}

