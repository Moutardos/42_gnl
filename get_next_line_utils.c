/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 07:50:33 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/12/04 08:47:44 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*res;
	size_t	size_s1;
	size_t	size_s2;

	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	if (size_s1 + size_s2 == SIZE_MAX)
		return (NULL);
	res = malloc(size_s1 + size_s2 + 1);
	if (res == NULL)
		return (NULL);
	res[0] = '\0';
	ft_strlcat(res, s1, size_s1 + 1);
	ft_strlcat(res, s2, size_s2 + size_s1 + 1);
	return (res);
}

char	*ft_strdup(const char *s)
{
	char	*s_dup;
	size_t	size;
	size_t	i;

	size = ft_strlen(s);
	if (size + 1 >= SIZE_MAX)
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

static size_t	ft_strlcat(char *dst, const char *src, size_t size)
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

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}