/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:58:49 by aamirkha          #+#    #+#             */
/*   Updated: 2024/02/09 21:11:34 by aamirkha         ###   ########.fr       */
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

	// for(int i = 0; i < lines; i++)
	// {
	// 	line = get_next_line(fd);
	// 	printf("%s", line);
	// }

	line = get_next_line(fd);
	printf("%d", *line == '\n');
	free(line);

	line = get_next_line(fd);
	printf("%d", *line == '\0');
	free(line);

	close(fd);
	system("leaks a.out");
}
