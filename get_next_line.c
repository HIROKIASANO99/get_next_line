/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:01:27 by hiasano           #+#    #+#             */
/*   Updated: 2024/06/25 01:00:47 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char ft_getchar(int fd)
{
	static char buf[BUFFER_SIZE];
	static int read_byte;
	static char *bufptr;

	if(read_byte == 0)
	{
		read_byte = read( fd, buf, BUFFER_SIZE);
		if(read_byte == -1)
			return(READ_ERROR);
		bufptr = buf;
	}
		read_byte--;
	if(read_byte >= 0)
		return(*bufptr++);
	return(EOF);
}

int ft_addchar(t_line *line , char c)
{
	char *new_str;
	unsigned char *dest;
	unsigned char *src;
	size_t len;

	if(line->len +1 >= line->capacity)
	{
		line->capacity = (line->len +1) * 2;
		new_str = (char *)malloc(sizeof(char) * line->capacity);
		if(!new_str)
			return(0);
		dest = (unsigned char *)new_str;
		src = (unsigned char *)line->str;
		len = line ->len;
		while(len--)
			*dest++ = *src++;
		free(line->str);
		line->str = new_str;
	}
	line->str[line->len++] = c;
	return(1);
}

char *get_next_line(int fd)
{
	t_line	line; 
	char  c;

	if(fd < 0)
		return(NULL);

	line.str = NULL;
	line.len = 0;
	line.capacity = 0;
	while(1)
	{
		c  = ft_getchar(fd);
		if(c == READ_ERROR)	
			return(free(line.str), NULL);	
		if(c == EOF)
			break;
		if(ft_addchar(&line, c) ==0)
			return(free(line.str), NULL);
		if(c == '\n')
			break;
	}
	return(line.str);	
}
