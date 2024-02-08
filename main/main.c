/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:58:49 by aamirkha          #+#    #+#             */
/*   Updated: 2024/02/09 02:52:56 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../get_next_line.h"

#ifndef lines
#define lines 1
#endif

int main()
{
	int fd = open("foo.txt", O_RDONLY);
	char *line;

	for(int i = 0; i < lines; i++)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}


	free(line);
	close(fd);
}
