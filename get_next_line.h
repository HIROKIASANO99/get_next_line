/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiasano <hiasano@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:04:20 by hiasano           #+#    #+#             */
/*   Updated: 2024/06/25 01:00:46 by hiasano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H 
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <fcntl.h> 
#include <unistd.h>

//下のincludeを消す
#include <stdio.h>

# ifndef EOF
#  define EOF 0x1A
# endif
 
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
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



char *get_next_line(int fd);

#endif
