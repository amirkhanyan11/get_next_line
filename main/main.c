/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:58:49 by aamirkha          #+#    #+#             */
/*   Updated: 2024/02/10 20:30:04 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../get_next_line.h"


int main()
{
	//int fd = open("abc.txt", O_RDONLY);
	int fd = open("/Users/aamirkha/Desktop/get_next_line/trip/files/43_no_nl", O_RDONLY);
	char *line;

	line = get_next_line(fd);
	//printf("%d\n", !strcmp(line, "0123456789012345678901234567890123456789012"));
	printf("%s", line);
	free(line);

	// line = get_next_line(fd);
	// printf("%s", line);
	// free(line);

	close(fd);
	//system("leaks a.out");
}
