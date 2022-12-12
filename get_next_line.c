/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 06:59:27 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/12/12 19:09:57 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>


char	*get_next_line(int fd)
{
	static t_fd		*fdinfos = NULL;
	t_fd			*fdinfo;
	char			*res;
	ssize_t			size;
	
	fdinfo = NULL;
	if (fd < 0)
		return (NULL);
	fdinfo = get_new_fd(fd, &fdinfos);
	if (!fdinfo)
		return (NULL);
	fdinfo->lines = fill_lines(fdinfo, &size);
	if (fdinfo->lines == NULL)
	{
		free_fd(fd, &fdinfo);
		return (NULL);
	}
	if (size == 0)
	{
		free_line(&fdinfo->lines);
		free_fd(fd, &fdinfos);
		return (NULL);
	}
	res = make_real_line(fdinfo, size);
	free_line(&fdinfo->lines);
	return (res);
}

t_line	*fill_lines(t_fd *fdinfo, ssize_t *nsize)
{
	t_line	*curr;
	t_line	*res;

	*nsize = 0;
	res = get_line(fdinfo);
	if (!res)
		return (NULL);
	curr = res;
	while (curr->size && ft_strchr(curr->buf, '\n') == -1)
	{
		curr->next = get_line(fdinfo);
		if (!curr->next)
		{
			free_line(&res);
			return (NULL);
		}
		*nsize += curr->size;
		curr = curr->next;
	} 
	*nsize += curr->size;
	fill_reste(fdinfo, curr);
	return (res);
}

t_line	*get_line(t_fd *fdinfo)
{
	t_line	*res;
	ssize_t	size;

	res = malloc(sizeof(t_line));
	res->next = NULL;
	if (!res)
		return (NULL);
	size = -1;
	if (fdinfo->reste[size + 1])
		while (fdinfo->reste[++size])
		{
			res->buf[size] = fdinfo->reste[size];
			fdinfo->reste[size] = '\0';
		}
	else
	{
		size = read(fdinfo->fd, res->buf, BUFFER_SIZE);
		if (size == -1)
		{
			free(res);
			return (NULL);
		}
	}
	res->buf[size] = '\0';
	if (ft_strchr(res->buf, '\n') != -1)
		res->size = ft_strchr(res ->buf, '\n') + 1;
	else
		res->size = size;
	return (res);
}

char	*make_real_line(t_fd *fdinfo, ssize_t size)
{
	char	*res;
	t_line	*curr;
	ssize_t	i;
	ssize_t	len;
	
	curr = fdinfo->lines;
	res = malloc(size + 1);
	len = 0;
	if (!res)
		return (NULL);
	while (curr)
	{
		i = -1;
		while (++i < curr->size)
			res[len++] = curr->buf[i];
		curr = curr->next;
	}
	res[len] = '\0';
	return (res);
}

void	get_line(char *line, t_list **filedata)
{
	size_t	i;
	size_t	size;
	size_t	eol;
	t_list	*node;

	size = 0;
	while(*filedata)
	{
		node = (*filedata);
		//printf("!treating %s!", node->content);
		if (ft_strchr(node->content, '\n') != NULL)
		{
			eol = ft_strchr(node->content , '\n') - node->content + 1;
			//printf("!EOL : %d DANS %s\n", eol, node->content);
			size += eol;
			ft_strlcat(line, node->content, size + 2);
			if (eol < BUFFER_SIZE)
			{
				i = -1;
				while (node->content[++i + eol])
					node->content[i] = node->content[i + eol];
				node->content[i] = '\0';
			}
			else
			{
				*filedata = node->next;
				free(node);
			}
			return ;
			
		}
		size += ft_strlen(node->content);
		//printf("size %s %d", node->content, size + 1);
		ft_strlcat(line, node->content, size + 1);
		*filedata = node->next;
		free(node);
	}
}