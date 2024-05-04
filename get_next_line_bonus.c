/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianadovhanych <marianadovhanych@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:11:28 by marianadovh       #+#    #+#             */
/*   Updated: 2024/03/06 01:05:03 by marianadovh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*join(char *buffer, char *aux)
{
	char	*temp;

	temp = ft_strjoin(buffer, aux);
	free(buffer);
	buffer = NULL;
	return (temp);
}

char	*div_line(char *buffer)
{
	int		len;
	char	*line;

	len = strchr_num(buffer, '\n');
	if (len == -1 || buffer[len + 1] == 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = ft_substr(buffer, len + 1, ft_strlen(buffer));
	free(buffer);
	return (line);
}

char	*send_line(char *buffer)
{
	int		len;
	char	*line;

	len = strchr_num(buffer, '\n');
	if (len == -1)
		len = ft_strlen(buffer);
	line = ft_substr(buffer, 0, len + 1);
	if (line == NULL)
		return (NULL);
	return (line);
}

char	*read_file(int fd, char *buffer)
{
	int		num_bytes;
	char	buffer_aux[BUFFER_SIZE + 1];

	num_bytes = 1;
	while (num_bytes > 0)
	{
		num_bytes = read(fd, buffer_aux, BUFFER_SIZE);
		if (num_bytes == -1)
		{
			free(buffer);
			buffer = NULL;
			return (NULL);
		}
		buffer_aux[num_bytes] = '\0';
		if (num_bytes == 0)
			break ;
		buffer = join(buffer, buffer_aux);
		if (!buffer)
			return (NULL);
		if (strchr_num(buffer, '\n') > 0)
			break ;
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = read_file(fd, buffer[fd]);
	if (buffer[fd] == NULL)
		return (NULL);
	line = send_line(buffer[fd]);
	if (line == NULL)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	buffer[fd] = div_line(buffer[fd]);
	return (line);
}
