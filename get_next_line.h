/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 09:47:43 by wnocchi           #+#    #+#             */
/*   Updated: 2023/12/11 10:52:55 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <stdint.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/stat.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*ft_line_cpy(char *s);
char *ft_new_line(char *buffer);
char	*ft_get_first_line(int fd, char *line);
char *get_next_line(int fd);
size_t	ft_strlen(char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, char to_find);

#endif