/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:11:17 by hiasano           #+#    #+#             */
/*   Updated: 2024/07/04 13:15:08 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char ft_getchar(int fd)
{
	static t_buffinfo	buffinfo[OPEN_MAX + 1];

	if(buffinfo[fd].read_byte == 0)
	{
		buffinfo[fd].read_byte = read( fd, buffinfo[fd].buf, BUFFER_SIZE);
		if(buffinfo[fd].read_byte < 0)
			return(buffinfo[fd].read_byte++, READ_ERROR);
		buffinfo[fd].buffer = buffinfo[fd].buf;
	}
	buffinfo[fd].read_byte--;
	if(buffinfo[fd].read_byte >= 0)
		return(*(buffinfo[fd].buffer)++);
	return(buffinfo[fd].read_byte++, EOF);
}

int ft_addchar(t_line *line, char c)
{
	char *new_str;
	unsigned char *dest;
	unsigned char *src;	
	size_t len;

	new_str = 0;
	if(line->len +1 >= line->capacity)
	{
		line->capacity = (line->len + 1) * 2;
		new_str = (char *)malloc(sizeof(char) * line->capacity);
		if(new_str == NULL)
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
	t_line line;
	char c;

	
	if(fd < 0 || fd > OPEN_MAX)
		return(NULL);
	line.str = 0;
	line.len = 0;
	line.capacity = 0;
	while(1)
	{
		c = ft_getchar(fd);
		if(c == READ_ERROR)
			return(free(line.str), NULL);
		if(c == EOF)
			break;
		if(ft_addchar(&line, c) == 0)
			return(free(line.str), NULL);
		if(c == '\n')
			break;
	}
	if(line.len > 0 && (ft_addchar(&line ,'\0') == 0))
		return(free(line.str), NULL);
	return(line.str);
}
