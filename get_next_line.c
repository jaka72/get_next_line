/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/20 22:27:48 by jmurovec      #+#    #+#                 */
/*   Updated: 2020/12/20 22:27:48 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

static int	str_to_line(char **str, char **line)
{
	int		len;
	char	*temp;

	len = 0;
	while ((*str)[len] != '\n' && (*str)[len] != '\0')
		len++;
	if ((*str)[len] == '\n')
	{
		(*str)[len] = '\0';
		*line = gnl_strdup(*str);
		temp = gnl_strdup(&(*str)[len + 1]);
		free(*str);
		*str = temp;
		if (*line == NULL || *str == NULL)
			return (-1);
	}
	else
	{
		*line = gnl_strdup(*str);
		free(*str);
		*str = NULL;
		if (*line == NULL)
			return (-1);
	}
	return (1);
}

static int	buff_to_str(int fd, int bytes_read, char *buff, char **str)
{
	char	*temp;

	while (bytes_read > 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read >= 0)
			buff[bytes_read] = '\0';
		if (*str == NULL)
		{
			*str = gnl_strdup(buff);
			if (*str == NULL)
				return (-1);
		}
		else
		{
			temp = gnl_strjoin(*str, buff);
			free(*str);
			*str = temp;
			if (*str == NULL)
				return (-1);
		}
		if (gnl_strchr(*str, '\n') != NULL)
			return (bytes_read);
	}
	return (bytes_read);
}

int			get_next_line(int fd, char **line)
{
	int			bytes_read;
	char		buff[BUFFER_SIZE + 1];
	static char	*str[1024];

	if (fd < 0 || BUFFER_SIZE == 0 || line == NULL)
		return (-1);
	if (str[fd] == NULL || !gnl_strchr(str[fd], '\n'))
		bytes_read = buff_to_str(fd, 1, buff, &str[fd]);
	else
		bytes_read = 0;
	if (bytes_read < 0)
		return (-1);
	if (str_to_line(&str[fd], line) < 0)
		return (-1);
	if (bytes_read == 0 && str[fd] == NULL)
		return (0);
	return (1);
}
