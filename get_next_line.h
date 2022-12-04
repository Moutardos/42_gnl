/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 06:59:19 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/12/04 08:53:24 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif
# ifdef BUFFER_SIZE 
#  if BUFFER_SIZE < 0
#   undef BUFFER_SIZE
#   define BUFFER_SIZE 0
#  endif
# endif
# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdio.h>
/* return the next line in the fd file */
char	*get_next_line(int fd);

/* concatenate two string*/
char	*ft_strjoin(const char *s1, const char *s2);

/* duplicate a string*/
char	*ft_strdup(const char *s);
static size_t	ft_strlen(const char *s);
static size_t	ft_strlcat(char *dst, const char *src, size_t size);
/* merg buf into megabuf, return the index where it met \n or eof */
int	check_end(char *buf, char **megabuf);

char	*cutalloc(char *megabuf, size_t i);
#endif
