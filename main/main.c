/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:58:49 by aamirkha          #+#    #+#             */
/*   Updated: 2024/02/13 00:32:18 by kali             ###   ########.fr       */
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
	int fd = open("/home/kali/Desktop/get_next_line/trip/files/multiple_nlx5", O_RDONLY);

				 gnl(fd, "98765432109876543210987654321098765432109\n");
		 /* 2 */ gnl(fd, "\n");
		 /* 3 */ gnl(fd, "012345678901234567890123456789012345678901\n");
		 /* 4 */ gnl(fd, "\n");
		 /* 5 */ gnl(fd, "9876543210987654321098765432109876543210987\n");

	close(fd);
	//system("leaks a.out");
}
