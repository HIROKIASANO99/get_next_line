/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:05:11 by hiasano           #+#    #+#             */
/*   Updated: 2024/07/04 13:19:48 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_BONUS_H 
# define GET_NEXT_LINE_BONUS_H

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

//下のincludeを消す
#include <stdio.h>

# ifndef EOF
#  define EOF 0x1A
# endif
 
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# if BUFFER_SIZE > 99999999 ||  BUFFER_SIZE <= 0
# error "BUFFER_SIZE must be greater than 0 and less than or equal to 99999999"
# endif

# define READ_ERROR -42

typedef struct s_line
{
	char *str;
	size_t len;
	size_t capacity;
} t_line;

typedef struct s_buffinfo
{

	char	buf[BUFFER_SIZE];
	char	*buffer;
	int	read_byte;
}	t_buffinfo;


char *get_next_line(int fd);

#endif
