/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 07:37:18 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/12/07 17:39:30 by lcozdenm         ###   ########.fr       */
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
	printf("%s", buf);

	return (0);
}
