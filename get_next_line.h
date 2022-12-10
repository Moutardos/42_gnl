/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 06:59:19 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/12/10 17:02:21 by lcozdenm         ###   ########.fr       */
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

typedef struct s_line
{
	ssize_t	size;
	char	buf[BUFFER_SIZE + 1];
	struct s_line	*next;
}	t_line;

typedef struct s_fd
{
	int		fd;
	char	reste[BUFFER_SIZE + 1];
	t_line	*lines;
	struct s_fd	*next;
}	t_fd;

/* return the next line in the fd file */
char	*get_next_line(int fd);
t_line	*get_line(t_fd *fdinfo);
t_line	*fill_lines(t_fd *fdinfo, ssize_t *nsize);
// char	*malloc_line(t_list *filedata);
// int		fill_lst(t_list **filedata, int fd);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *s);
/** UTILS **/

/* Actualise ou cree une nouvelle struct contenant la data du fd*/
int	get_new_fd(int fd, t_fd **fdinfo);
void	free_fd(int fd, t_fd **fdinfo);
void	free_line(t_line **line);
// void	ft_lstclear(t_list **lst, void (*del)(void *));
// void	ft_lstadd_back(t_list **lst, t_list *new);
// /* return index of where character c is found*/
ssize_t	ft_strchr(const char *s, int c);
void	print_line(t_line *lst);
void	fill_reste(t_fd *fdinfo, t_line *line);
#endif
