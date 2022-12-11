/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 07:37:18 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/12/11 19:35:32 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"
#include <fcntl.h>


int	test(t_fd *fdinfo)
{
	char	*red;
	
	read(fdinfo->fd, fdinfo->lines->buf, BUFFER_SIZE);
	fdinfo->lines->buf[BUFFER_SIZE] = '\0';
	printf("%s\n", fdinfo->lines->buf);
	return (0);
}

// #include "get_next_line_utils.c"
// #include "get_next_line.c"
int	main(int ac, char **av)
{
	char	*buf;
	t_fd 	*fdinfo;
	int		fd;
	char *res;

	fd = open("allo", O_RDWR);	

	while((res = get_next_line(fd)) != NULL)
	{
		printf("'%s'",res);
		free(res);
	} 
	// int fd=open("allo",O_RDWR);
	// buf = get_next_line(fd);
	// printf("first line :%s", buf);
	//  buf = get_next_line(fd);
	//  printf("second line :%s", buf);
	// buf = get_next_line(fd);
	// printf("third line :%s", buf);
	// buf = get_next_line(fd);
	// printf("over :%s", buf);
	// fd=open("allo",O_RDWR);
	// buf = get_next_line(fd);
	// printf("first line :%s\n", buf);

	return (0);
}

