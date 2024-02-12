/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:47:24 by aamirkha          #+#    #+#             */
/*   Updated: 2024/02/13 00:09:39 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif


#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>


char	*ft_strchr(char *str, char const c);
char	*ft_strdup(const char * const str);
char  *ft_append(char ** self, char const * rhv);
int	ft_strlen(const char * const str);
char	*get_next_line(int fd);

#endif // GET_NEXT_LINE_H
