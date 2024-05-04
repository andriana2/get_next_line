/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianadovhanych <marianadovhanych@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 21:48:26 by marianadovh       #+#    #+#             */
/*   Updated: 2024/03/06 01:04:52 by marianadovh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	while (num_bytes > 0 && strchr_num(buffer, '\n') == -1)
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
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if ((buffer && strchr_num(buffer, '\n') == -1) || !buffer)
		buffer = read_file(fd, buffer);
	if (buffer == NULL)
		return (NULL);
	line = send_line(buffer);
	if (line == NULL)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = div_line(buffer);
	return (line);
}
