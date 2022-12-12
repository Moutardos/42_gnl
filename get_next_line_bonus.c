/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 06:59:27 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/12/12 00:24:52 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>


char	*get_next_line(int fd)
{
	static t_fd		*fdinfo = NULL;
	char			*res;
	ssize_t			size;
	
	if (fd < 0)
		return (NULL);
	if (!get_new_fd(fd, &fdinfo))
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
		free_fd(fd, &fdinfo);
		return (NULL);
	}
	//print_line(fdinfo->lines);
	res = make_real_line(fdinfo, size);
	free_line(&fdinfo->lines);
	// while(filedata)
	// {
	// 	node = filedata;
	// 	if (ft_strchr(node->content, '\n') != NULL)
	// 	{
	// 		size += ft_strchr(node->content , '\n') - node->content + 1;
	// 		ft_strlcat(line, node->content, size + 1);
	// 		filedata->content += ft_strchr(data , '\n') - data + 1;
	// 		break ;
	// 	}
	// 	size += ft_strlen(data);
	// 	ft_strlcat(line, data, size + 1);
	// 	filedata = filedata->next;
	// }
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
// char	*malloc_line(t_list *filedata)
// {
// 	size_t	res_len;
// 	t_list	*node;

// 	res_len = 0;
// 	while(filedata != NULL)
// 	{
// 		node = (char *) filedata->content;
// 		if (ft_strchr(data, '\n') == NULL)
// 			res_len += ft_strlen(data);
// 		else
// 		{
// 			res_len += ft_strchr(data, '\n') - data + 1;
// 			break;
// 		}
		
// 		filedata = filedata->next;
// 	}
// 	if (res_len == 0)
// 		return (NULL);
// 	//printf("size : %d\n", res_len + 1);
// 	return (malloc(res_len + 1));
// }

// int		fill_lst(t_list **filedata, int fd)
// {
// 	char	buf[BUFFER_SIZE + 1];
// 	t_list	*node;
// 	size_t	n;
	
// 	if (*filedata != NULL)
// 		return (1);
// 	n = read(fd, buf, BUFFER_SIZE);
// 	if (n < 0)
// 		return (0);
// 	while (n > 0)
// 	{
// 		buf[n] = '\0';
// 		node = ft_lstnew(ft_strdup(buf));
// 		if (node == NULL)
// 		{
// 			ft_lstclear(filedata, free);
// 			return (0);
// 		}
// 		ft_lstadd_back(filedata, node);
// 		n = read(fd, buf, BUFFER_SIZE);
// 	}
// 	return (1);
// }

// size_t	ft_strlcat(char *dst, const char *src, size_t size)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	j = 0;
// 	while (i < size)
// 	{
// 		if (dst[i] == '\0')
// 			break ;
// 		i++;
// 	}
// 	if (i == size)
// 	{
// 		return (size + ft_strlen(src));
// 	}
// 	while (i < (size - 1) && src[j] != '\0')
// 	{
// 		dst[i] = src[j];
// 		i++;
// 		j++;
// 	}
// 	dst[i] = '\0';
// 	return ((i - j) + ft_strlen(src));
// }

// char	*ft_strdup(const char *s)
// {
// 	char	*s_dup;
// 	size_t	size;
// 	size_t	i;

// 	if (s == NULL)
// 		return (NULL);
// 	size = ft_strlen(s);
// 	if (size >= SIZE_MAX)
// 		return (NULL);
// 	s_dup = malloc(size + 1);
// 	if (s_dup == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (i < size)
// 	{
// 		s_dup[i] = s[i];
// 		i++;
// 	}
// 	s_dup[i] = '\0';
// 	return (s_dup);
// }