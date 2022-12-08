/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 06:59:27 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/12/09 00:50:01 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>



char	*get_next_line(int fd)
{
	static t_list	*filedata = NULL;
	char			*line;

	if (!fill_lst(&filedata, fd))
		return (NULL);
	if (filedata == NULL)
		return (NULL);
	if (fd < 0)
		return (NULL);
	line = malloc_line(&filedata);
	if (line == NULL)
		return (NULL);
	get_line(line, &filedata);
	//printf("RESULLTATT:::: %s", line);
	return (line);
}


char	*malloc_line(t_list **filedata)
{
	size_t	res_len;
	t_list	*curr;
	char	*res;

	res_len = 0;
	curr = *filedata;
	while(curr)
	{
		if (ft_strchr(curr->content, '\n') == NULL)
			res_len += ft_strlen(curr->content);
		else
		{
			res_len += ft_strchr(curr->content, '\n') - curr->content + 1;
			break;
		}
		curr = curr->next;
	}
	res = malloc(res_len + 1);
	if (res == NULL)
		return (NULL);
	while (res_len + 1)
		res[res_len--] = '\0';
	return (res);
}

int		fill_lst(t_list **filedata, int fd)
{
	char	buf[BUFFER_SIZE + 1];
	t_list	*node;
	size_t	n;
	
	if (*filedata != NULL)
		return (1);
	n = read(fd, buf, BUFFER_SIZE);
	while (n > 0)
	{
		buf[n] = '\0';
		node = ft_lstnew(buf);
		if (node == NULL)
		{
			while (*filedata)
			{
				node = (*filedata)->next;
				free(*filedata);
				*filedata = node;
			}
			return (0);
		}
		ft_lstadd_back(filedata, node);
		n = read(fd, buf, BUFFER_SIZE);
	}
	return (1);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		if (dst[i] == '\0')
			break ;
		i++;
	}
	if (i == size)
	{
		return (size + ft_strlen(src));
	}
	while (i < (size - 1) && src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return ((i - j) + ft_strlen(src));
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