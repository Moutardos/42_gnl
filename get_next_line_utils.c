/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 07:50:33 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/12/08 23:33:32 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s[size])
		size++;
	return (size);
}

t_list	*ft_lstnew(char *buf)
{
	t_list	*new;
	size_t	i;

	i = 0;
	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	while (i < BUFFER_SIZE + 1)
	{
		new->content[i] = buf[i];
		i++;
	}
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (lst == NULL || *lst == NULL)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next)
	{
		current = current->next;
	}
	current->next = new;
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = ft_strlen(s);
	while (i <= size)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}