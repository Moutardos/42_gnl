/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 06:59:27 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/12/07 17:42:26 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>



char	*get_next_line(int fd)
{
	static t_list	*filedata = NULL;
	char			*line;
	char			*data;
	size_t			size;

	if (!fill_lst(&filedata, fd))
		return (NULL);
	print_lst(filedata);
	line = malloc_line(filedata);
	if (line == NULL)
		return (NULL);
	size = 0;
	while(filedata)
	{
		data = (char *) (filedata)->content;
		if (ft_strchr(data, '\n') != NULL)
		{
			size += ft_strchr(data , '\n') - data;
			ft_strlcat(line, data, size + 1);
			filedata->content += ft_strchr(data , '\n') - data + 1;
			break ;
		}
		size += ft_strlen(data);
		ft_strlcat(line, data, size + 1);
		filedata = filedata->next;
	}
	return (line);
}


char	*malloc_line(t_list *filedata)
{
	size_t	res_len;
	char	*data;

	res_len = 0;
	while(filedata != NULL)
	{
		data = (char *) filedata->content;
				printf("%s dataing\n", data);
		if (ft_strchr(data, '\n') == NULL)
			res_len += ft_strlen(data);
		else
		{
			res_len += ft_strchr(data, '\n') - data + 1;
			break;
		}
		filedata = filedata->next;
	}
	printf("res_len : %lu\n", res_len + 1);
	return (malloc(res_len + 1));
}

int		fill_lst(t_list **filedata, int fd)
{
	char	buf[BUFFER_SIZE];
	t_list	*node;

	if (*filedata == NULL)
	{
		if (read(fd, buf, BUFFER_SIZE) < 0)
			return (0);
		node = ft_lstnew(ft_strdup(buf));
		if (node == NULL)
			return (0);
		ft_lstadd_back(filedata, node);
		printf("readed[%d] %s alias\n", BUFFER_SIZE, (*filedata)->content);
	}
	while (read(fd, buf, BUFFER_SIZE) > 0)
	{
		node = ft_lstnew(ft_strdup(buf));
		if (node == NULL)
		{
			ft_lstclear(filedata, malloc);
			return (0);
		}
		ft_lstadd_back(filedata, node);
		printf("readed :%s\n", (*filedata)->content);
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

char	*ft_strdup(const char *s)
{
	char	*s_dup;
	size_t	size;
	size_t	i;

	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	if (size >= SIZE_MAX)
		return (NULL);
	s_dup = malloc(size + 1);
	if (s_dup == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		s_dup[i] = s[i];
		i++;
	}
	s_dup[i] = '\0';
	return (s_dup);
}