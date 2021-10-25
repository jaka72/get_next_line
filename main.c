/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmurovec <jmurovec@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/25 11:09:34 by jmurovec      #+#    #+#                 */
/*   Updated: 2021/10/25 13:03:57 by jmurovec      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		fd;
	int		ret;


//	fd = open("text.txt", O_RDONLY);
	fd = 0;
	if (fd < 0)
		return (-1);

	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		printf("line: %s\n", line);
		free(line);
	}
	ret = get_next_line(fd, &line);
	printf("line: %s\n", line);
	free(line);


	return (0);
}