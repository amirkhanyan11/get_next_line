/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 17:02:14 by aamirkha          #+#    #+#             */
/*   Updated: 2024/02/08 22:07:50 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(char const *str, char const c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		str++;
		len++;
	}
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
