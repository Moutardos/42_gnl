/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 07:37:18 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/12/12 21:39:18 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"
#include <fcntl.h>
#include <string.h>
void	gnl(int fd, char *exp)
{
	char	*res;
	res = get_next_line(fd);
	if (exp == NULL && res != NULL)
	{
		printf("malaise");
	}
	else if (exp == NULL && res == NULL)
	{
		printf("good");
	}
	else if ( exp != NULL && res == NULL)
	{
		printf("malaise");
	}
	else if (strcmp(exp, res))
	{
		printf("MALAISE");
	}
	else
	{
		printf("GOOD");
	}
	printf("\n");
	
}

int	main(int ac, char **av)
{
	char	*buf;
	t_fd 	*fdinfo;
	int		fd[100];
	char *res;
	fd[0] = open("files/41_with_nl", O_RDWR);
	/* 1 */ gnl(1000, NULL);
	/* 2 */ gnl(fd[0], "0123456789012345678901234567890123456789\n");

	fd[1] = open("files/42_with_nl", O_RDWR);
	/* 3 */ gnl(1001, NULL);
	/* 4 */ gnl(fd[1], "01234567890123456789012345678901234567890\n");

	fd[2] = open("files/43_with_nl", O_RDWR);
	/* 5 */ gnl(1002, NULL);
	/* 6 */ gnl(fd[2], "012345678901234567890123456789012345678901\n");

	/* 7 */ gnl(1003, NULL);
	/* 8 */ gnl(fd[0], "0");

	/* 9 */ gnl(1004, NULL);
	/* 10 */ gnl(fd[1], "1");

	/* 11 */ gnl(1005, NULL);
	/* 12 */ gnl(fd[2], "2");

	/* 13 */ gnl(fd[0], NULL);
	/* 14 */ gnl(fd[1], NULL);
	/* 15 */ gnl(fd[2], NULL);

	fd[3] = open("files/nl", O_RDWR);
	/* 16 */ gnl(1006, NULL);
	/* 17 */ gnl(fd[3], "\n");
	/* 18 */ gnl(1007, NULL);
	/* 19 */ gnl(fd[3], NULL);
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

