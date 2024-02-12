/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamirkha <aamirkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:58:49 by aamirkha          #+#    #+#             */
/*   Updated: 2024/02/12 21:16:05 by aamirkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../get_next_line.h"


void gnl(int fd, char * str)
{
	char * line;


	line = get_next_line(fd);
	printf("%s", line);
	// if (!line && !str)
	// 	printf("NULLIK\n");
	// else
	// 	printf("%d\n", !strcmp(line, str));
	free(line);
}

int main()
{
	//int fd = open("abc.txt", O_RDONLY);
	int fd = open("/Users/aamirkha/Desktop/get_next_line/trip/files/multiple_line_no_nl", O_RDONLY);


	gnl(fd, "01234567890123456789012345678901234567890\n");
	gnl(fd, "987654321098765432109876543210987654321098\n");
	gnl(fd, "0123456789012345678901234567890123456789012\n");
	gnl(fd, "987654321098765432109876543210987654321098\n");
	gnl(fd, "01234567890123456789012345678901234567890");
	gnl(fd, NULL);

	close(fd);
	//system("leaks a.out");
}
