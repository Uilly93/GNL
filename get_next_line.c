/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnocchi <wnocchi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:33:05 by wnocchi           #+#    #+#             */
/*   Updated: 2023/12/12 14:26:18 by wnocchi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*join_free(char *line, char *buffer)
{
	char	*temp;

	if (!line)
	{
		free (line);
		return (NULL);
	}
	temp = ft_strjoin(line, buffer);
	if (!temp)
		return (NULL);
	free(line);
	return (temp);
}

char	*ft_line_cpy(char *s)
{
	int		i;
	char	*line;

	if (!s || *s == 0)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] && s[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_new_line(char *buffer)
{
	char	*new_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	new_line = malloc(ft_strlen(buffer) - i + 1);
	if (!new_line)
		return (NULL);
	if (buffer[i] != 0)
		i++;
	while (buffer[i])
		new_line[j++] = buffer[i++];
	new_line[j] = '\0';
	free(buffer);
	return (new_line);
}

char	*ft_get_first_line(int fd, char *line)
{
	int				bytes;
	static char		buffer[BUFFER_SIZE + 1];

	bytes = 1;
	if (!line)
		line = ft_calloc(1, 1);
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(line);
			return (NULL);
		}
		buffer[bytes] = '\0';
		line = join_free(line, buffer);
		if (!line)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (((BUFFER_SIZE <= 0) || (read(fd, 0, 0) < 0) || fd < 0))
		return (NULL);
	buffer = ft_get_first_line(fd, buffer);
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	line = ft_line_cpy(buffer);
	buffer = ft_new_line(buffer);
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
