/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 18:42:44 by tripham           #+#    #+#             */
/*   Updated: 2024/11/25 20:55:34 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free(char **s)
{
	if(*s)
	{
		free(*s);
		*s = NULL;
	}
	return (NULL);
}

static char	ft_read(int fd, char *big_buf, int bean_read, char *small_buf);

static char	ft_extract_read_line(char *big_buf);

static void	ft_get_remainder(char **big_buf);

char	*get_next_line(int fd)
{
	static char	*big_buf;
	char		*small_buf;
	char		*line;
	int				been_read;

	line =	NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, BUFFER_SIZE, 0) < 0)
		return (ft_free(&big_buf));
}