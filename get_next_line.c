/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:01:27 by hiasano           #+#    #+#             */
/*   Updated: 2024/06/19 00:13:27 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char ft_getchar(int fd)
{
	static char *buf;
	static int read_byte;
	static char *bufptr;;

	if(read == 0)
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
char *get_next_line(int fd)
{
	int  c;

	if(fd < 0)
		return(NULL);
	while(1)
	{
	c  = ft_getchar(fd);
	if(c == READ_ERROR);				
		return(NULL);	
	if(c == '\n')
		break;
	if(c == EOF)
		break;
	}
	return(read_str);	
}
