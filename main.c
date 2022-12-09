/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 07:37:18 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/12/08 18:05:41 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"
       #include <fcntl.h>
int	main(int ac, char **av)
{
	char	*buf;
	int fd=open("allo",O_RDWR);
	buf = get_next_line(fd);
	printf("first line :%s", buf);
	 buf = get_next_line(fd);
	 printf("second line :%s", buf);
	// buf = get_next_line(fd);
	// printf("third line :%s", buf);
	// buf = get_next_line(fd);
	// printf("over :%s", buf);
	// fd=open("allo",O_RDWR);
	// buf = get_next_line(fd);
	// printf("first line :%s\n", buf);

	return (0);
}
