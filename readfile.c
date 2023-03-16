/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarlen <jcarlen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:58:15 by fmalizia          #+#    #+#             */
/*   Updated: 2023/03/16 15:01:26 by jcarlen          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

char	*readfile(char *filename)
{
	int		fd;
	char	buffer[BUFSIZE];
	char	*line;
	size_t	line_size;
	ssize_t	bytes_read;

	line_size = 0;
	bytes_read = 1;
	line = NULL;
	fd = open(filename, O_RDONLY);
	readfile_2(fd, filename);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFSIZE);
		line = readfile_3(bytes_read, line, &line_size, buffer);
	}
	if (line_size > 0)
	{
		line = ft_realloc_rt(line, line_size + 1);
		ft_memcpy(line + line_size, "\0", 1);
	}
	close(fd);
	return (line);
}

void	readfile_2(int fd, char *filename)
{
	if (fd < 0)
	{
		printf("file : %s doesn't exist", filename);
		exit(0);
	}
}

char	*readfile_3(ssize_t bytes_read, char *line,
		size_t *line_size, char *buffer)
{
	int	i;

	i = 0;
	while (i < bytes_read)
	{
		if (buffer[i] == '\n')
		{
			line = ft_realloc_rt(line, *line_size + i + 1);
			ft_memcpy(line + *line_size, buffer, i);
			line[*line_size + i] = '\0';
			*line_size = 0;
		}
		else
		{
			line = ft_realloc_rt(line, *line_size + bytes_read - i);
			ft_memcpy(line + *line_size, buffer + i, bytes_read - i);
			*line_size += bytes_read - i;
			break ;
		}
		i++;
	}
	i = 0;
	return (line);
}
