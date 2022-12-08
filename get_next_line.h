/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 06:59:19 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/12/08 23:30:03 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif
# ifdef BUFFER_SIZE 
#  if BUFFER_SIZE < 0
#   undef BUFFER_SIZE
#   define BUFFER_SIZE 0
#  endif
# endif
# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdio.h>


typedef struct s_list
{
	char	content[BUFFER_SIZE + 1];
	struct s_list	*next;
}	t_list;

/* return the next line in the fd file */
char	*get_next_line(int fd);
char	*malloc_line(t_list **filedata);
int		fill_lst(t_list **filedata, int fd);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
void	get_line(char *line, t_list **filedata);
/** UTILS **/
size_t  ft_strlen(const char *s);  
t_list	*ft_lstnew(char *buff);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstadd_back(t_list **lst, t_list *new);
char	*ft_strchr(const char *s, int c);
void    print_lst(t_list *lst);
#endif
