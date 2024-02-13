/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kali <kali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:58:49 by aamirkha          #+#    #+#             */
/*   Updated: 2024/02/14 02:17:44 by kali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../get_next_line.h"

void gnl(int fd, char * str)
{
	char * line;


	line = get_next_line(fd);
//	printf("%s", line);
	if (!line && !str)
		printf("1 & NULLIK\n");
	else
		printf("%d\n", !strcmp(line, str));
	free(line);
}

int main()
{
	int fd = open("foo.txt", O_RDONLY);

	gnl(fd, "aaaa");
	gnl(fd, "aaaa");

	static int *a;

	int *p = malloc(4);


	a = p;

	close(fd);
	//system("leaks a.out");
}
