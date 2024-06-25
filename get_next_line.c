/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:01:27 by hiasano           #+#    #+#             */
/*   Updated: 2024/06/26 00:41:56 by hiasano          ###   ########.fr       */
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
			return(read_byte++, READ_ERROR);
		bufptr = buf;
	}
		read_byte--;
	if(read_byte >= 0)
		return(*bufptr++);
	return(read_byte++, EOF);
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
		len = line->len;
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
	t_line	str; 
	char  c;

	if(fd < 0)
		return(NULL);
	str.str = NULL;
	str.len = 0;
	str.capacity = 0;
	while(1)
	{
		c  = ft_getchar(fd);
		if(c == READ_ERROR)	
			return(free(str.str), NULL);	
		if(c == EOF)
			break;
		if(ft_addchar(&str, c) == 0)
			return(free(str.str), NULL);
		if(c == '\n')
			break;
	}
	if (str.len > 0 && (ft_addchar(&str, '\0') == 0))
		return (free(str.str), NULL);
	return(str.str);	
}
