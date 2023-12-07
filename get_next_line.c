/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:33:05 by wnocchi           #+#    #+#             */
/*   Updated: 2023/12/07 16:42:14 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*line_cpy(char *s)
{
	int	i;
	char *ptr;
	
	if(s == NULL)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	ptr = ft_calloc(1, i + 2);
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		ptr[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		ptr[i] = '\n';
	return (ptr);
}
char *ft_new_line(char *buffer)
{
	char	*new_line;
	int		i;
	int		j;
	
	i = 0;
	j = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	new_line = ft_calloc(1, (ft_strlen(buffer) - i + 1));
	if (!new_line)
		return (NULL);
	i++;
	while (buffer[i])
		new_line[j++] = buffer[i++];
	free(buffer);
	return (new_line);
}

char	*ft_get_first_line(int fd, char *line)
{
	int			bytes;
	char 		buffer[BUFFER_SIZE + 1];

	bytes = 1;
	if (!line)
		line = ft_calloc(1, 1);
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (NULL);
		buffer[bytes] = '\0';
		line = ft_strjoin_free(line, buffer);
		if (!line || *line == 0)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (line);
}

char *get_next_line(int fd)
{
	static char *buffer[1024];
	char		*line;
	
	if ((BUFFER_SIZE <= 0) || (read(fd, 0, 0) < 0))
		return (NULL);
	buffer[fd] = ft_get_first_line(fd, buffer[fd]);
	line = line_cpy(buffer[fd]);
	if(line == NULL)
		return (NULL);
	buffer[fd] = ft_new_line(buffer[fd]);
	return (line);
}

// int main(void)
// {
// 	char *str;
// 	int fd = open("test.txt", O_RDONLY);

// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	free(str);
// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	free(str);
// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	free(str);
// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	free(str);
// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	free(str);
// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	free(str);
// }
