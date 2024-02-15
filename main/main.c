/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:58:49 by aamirkha          #+#    #+#             */
/*   Updated: 2024/02/15 16:00:33 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../get_next_line.h"

void gnl(int fd, char * str)
{
	char * line;


	line = get_next_line(fd);
	if (!line && !str)
		printf("1 & NULLIK\n");
	else
		printf("%d\n", !strcmp(line, str));
	free(line);
}

int main()
{
	int fd = open("/Users/aamirkha/Desktop/get_next_line/trip/files/41_no_nl", O_RDONLY);

	gnl(fd, "01234567890123456789012345678901234567890");
	gnl(fd, NULL);

	close(fd);
	//system("leaks a.out");
}
