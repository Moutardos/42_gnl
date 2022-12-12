/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 07:50:33 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/12/12 19:09:39 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_fd	*get_new_fd(int fd, t_fd **fdinfo)
{
	t_fd	*node;
	ssize_t	i;

	node = *fdinfo;
	while(node)
	{
		if (node->fd == fd)
			return (node);
		node = node->next;
	}
	node = malloc(sizeof(t_fd));
	if (!node)
		return (NULL);
	i = -1;
	while(node->reste[++i])
			node->reste[i] = '\0';
	node->fd = fd;
	if (!*fdinfo)
		node->next = NULL;
	else
		node->next = *fdinfo;
	*fdinfo = node;
	return (node);
}

void	free_fd(int fd, t_fd **fd_info)
{
	t_fd	*curr;
	t_fd	*node;
	size_t	i;

	i = -1;
	if ((*fd_info)->fd == fd)
	{
		node = (*fd_info)->next;
		free(*fd_info);
		*fd_info = node;
		return ;
	}
	node = *fd_info;
	curr = node->next;
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

ssize_t	ft_strchr(const char *s, int c)
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

void	fill_reste(t_fd *fdinfo, t_line *line)
{
	ssize_t	offset;
	size_t	i;

	i = 0;
	offset = ft_strchr(line->buf, '\n');
	if (offset == -1)
		while (fdinfo->reste[i])
			fdinfo->reste[i++] = '\0';
	else
	{
		while (line->buf[offset + i + 1])
		{
			fdinfo->reste[i] = line->buf[offset + i + 1];
			i++;
		}
		while(fdinfo->reste[i])
			fdinfo->reste[i++] = '\0';
	}
}

void	print_line(t_line *lst)
{
	ssize_t	i;
	ssize_t	n;

	i = 1;
	while (lst)
	{
		n = 0;
		write(1, "'", 1);
		while(n < lst->size)
		{
			if (lst->buf[n] == '\n')
				write(1, "\\n",2);
			else
			{
				write(1, lst->buf + n, 1);
			}
			n++;
		}
		write(1, "'", 1);
		lst = lst->next;
		i++;
		printf("\n");
	}
	printf("NULL\n");
}