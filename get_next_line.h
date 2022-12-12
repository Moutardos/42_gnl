/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcozdenm <lcozdenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 06:59:19 by lcozdenm          #+#    #+#             */
/*   Updated: 2022/12/12 01:18:10 by lcozdenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
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
	int			fd;
	struct s_fd	*first;
	char		reste[BUFFER_SIZE + 1];
	t_line		*lines;
	struct s_fd	*next;
}	t_fd;

/* return the next line in the fd file */
char	*get_next_line(int fd);
t_line	*get_line(t_fd *fdinfo);
t_line	*fill_lines(t_fd *fdinfo, ssize_t *nsize);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *s);
char	*make_real_line(t_fd *fdinfo, ssize_t size);
/** UTILS **/

/* Actualise ou cree une nouvelle struct contenant la data du fd*/
t_fd	*get_new_fd(int fd, t_fd **fdinfo);
void	free_fd(int fd, t_fd **fdinfo);
void	free_line(t_line **line);
// /* return index of where character c is found*/
ssize_t	ft_strchr(const char *s, int c);
void	print_line(t_line *lst);
void	fill_reste(t_fd *fdinfo, t_line *line);
#endif
