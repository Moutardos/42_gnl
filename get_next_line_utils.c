/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 07:50:33 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/12/08 22:22:50 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_new_fd(int fd, t_fd **fdinfo)
{
	t_fd	*node;

	node = *fdinfo;
	while(node)
	{
		if (node->fd == fd)
			return (1);
		node = node->next;
	}
	node = malloc(sizeof(t_fd *));
	if (!node)
		return (0);
	node->fd = fd;
	node->next = *fdinfo;
	return (1);
}

void	free_fd(int fd, t_fd **fd_info)
{
	t_fd	*curr;
	t_fd	*node;
	
	curr = *fd_info;
	if (curr->fd == fd)
	{
		node = curr->next;
		free(curr);
		*fd_info = node;
		return ;
	}
	node = curr;
	curr = curr->next;
	while(curr)
	{
		if (curr->fd == fd)
		{
			node->next = curr->next;
			free(curr);
			return ;
		}
		curr = curr->next;
		node = node->next;
	}
}

void	free_line(t_line **line)
{
	t_line	*node;
	t_line	*curr;

	if (*line == NULL)
		return ;
	curr = *line;
	while (curr)
	{
		node = curr->next;
		free(curr);
		curr = node;
	}
	*line = NULL;
}
size_t	ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return (i);
		i++;
	}
	return (-1);
}

void	print_lst(t_list *lst)
{
	while (lst)
	{
		printf("%s->", (char*) lst->content);
		lst = lst->next;
	}
	printf("NULL\n");
}
 