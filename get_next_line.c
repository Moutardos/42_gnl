/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 06:59:27 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/12/04 10:19:51 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>




char	*get_next_line(int fd)
{
	static char	*megabuf[BUFFER_SIZE];
	char		*buf;
	size_t		is_over;

	megabuf = malloc(0);
	if (megabuf == NULL)
		return (NULL);
	if (read(fd, NULL, 0) < 0)
		return (NULL);
	read(fd, buf, BUFFER_SIZE);
	printf("%s", buf);
	is_over = check_end(buf, &megabuf);
	while (!is_over)
	{
		//is_over = check_end(buf, &megabuf);	
		if (read(fd, buf, BUFFER_SIZE) <= 0)
			break ;
	}
	return (cutalloc(megabuf, is_over)); // rendre megabuf couped
}

int	check_end(char *buf, char **megabuf)
{
	size_t	i;
	size_t	is_over;
	char 	*old_mega;

	old_mega = *megabuf;
	is_over = 0;
	i = 0;
	while (i < BUFFER_SIZE && !is_over)
	{
		if (buf[i] == '\n' || buf[i] == -1)
			is_over = i;
		i++;
	}
	*megabuf = ft_strjoin(*megabuf, buf);
	free(old_mega);
	return (is_over);
}

char	*cutalloc(char *megabuf, size_t size)
{
	size_t	i;
	char	*res;

	res = malloc(size);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		res[i] = megabuf[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}