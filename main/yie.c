#include <unistd.h>
#include <stdlib.h>//check
#include <stdio.h>//check
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif


int ft_len(char *s)
{
	int i = 0;
	while(s[i])
		i++;
	return i;
}

char *ft_cpy(char *d, char *s)
{
	int i = 0;
	while(s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return d;
}

char *ft_chr(char *s, char c)
{
	int i = 0;
	if(!s)
		return 0;
	while(s[i])
	{
		if(s[i] == c)
			return (s+i);
		i++;
	}
	return 0;
}

char *ft_dup(char *s)
{
	int i = 0;
	char *new;
	if(!s)
		return 0;
	new = malloc(ft_len(s)+1);
	if(!new)
		return 0;
	while(s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return new;
}

char *ft_join(char *s1, char *s2)
{
	int i = 0;
	int j = 0;
	char *new;
	new = malloc(ft_len(s1) + ft_len(s2) + 1);
	if(!new)
		return 0;
	while(s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while(s2[j])
	{
		new[i+j] = s2[j];
		j++;
	}
	new[i+j] = '\0';
	free(s1);
	return new;
}

char *get_next_line(int fd)
{
	int size;
	char buf[BUFFER_SIZE+1];
	char *line;
	char *next_line = NULL;
	static char *mem;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return 0;
	if(mem)
	{
		if((next_line = ft_chr(mem, '\n')))
		{
			*next_line = '\0';
			line = ft_dup(mem);
			line = ft_join(line, "\n");
			next_line++;
			ft_cpy(mem, next_line);
		}
		else
		{
			line = ft_dup(mem);
			free(mem);
			mem = NULL;
		}
	}
	else
	{
		line = malloc(1);
		line[0] = '\0';
	}
	while(!next_line && (size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[size] = '\0';
		if((next_line = ft_chr(buf, '\n')))
		{
			*next_line = '\0';
			line = ft_join(line, buf);
			line = ft_join(line, "\n");
			next_line++;
			mem = ft_dup(next_line);
		}
		else
			line =ft_join(line, buf);
	}
	if(line[0] == 0)
	{
		free(line);
		return 0;
	}
	return line;
}

int main()
{
    int fd;
    char *out;

    fd = open("text.txt", O_RDONLY);
    out = get_next_line(fd);
	printf("%s", out);
	out = get_next_line(fd);
	printf("%s", out);
	out = get_next_line(fd);
	printf("%s", out);
}
