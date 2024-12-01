/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 21:37:31 by tripham           #+#    #+#             */
/*   Updated: 2024/12/01 02:28:35 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_free(char **s)
{
	if(*s)
	{
		free(*s);
		*s = NULL;
	}
	return (NULL);
}
static char	*ft_read(int fd, char *small_buf, char *big_buf, int been_read)
{
	char	*tpm;

	while (been_read)
	{
		been_read = read(fd, small_buf, BUFFER_SIZE);
		if (been_read < 0)
		{
			free(small_buf);
			return (ft_free(&big_buf));
		}
		small_buf[been_read] = '\0';
		tpm = big_buf;
		big_buf = ft_strjoin(big_buf, small_buf);
		if (!big_buf)
		{
			free(small_buf);
			return (ft_free(&tpm));
		}
		if (ft_strchr(big_buf, '\n'))
			break;
	}
	free(small_buf);
	return (big_buf);
}
char	*ft_extract_read_line(char *big_buf)
{
	char	*read_line;
	int	i;

	i = 0;
	if (!big_buf[i])
		 return (NULL);
	while (big_buf[i] != '\n' &&  big_buf[i] != '\0')
		i++;
	if (big_buf[i] == '\n')
		i++;
	read_line = malloc((ft_strlen(big_buf) + 1) * sizeof(char));
	if (!read_line)
		return (NULL);
	read_line = ft_memcpy(read_line, big_buf, i);
	read_line[i] = '\0';
	return (read_line);
}

static void	ft_get_remainder(char **big_buf)
{
	char	*new_big_buf;
	int		i;

	i = 0;
	while ((*big_buf)[i] != '\n' &&  (*big_buf)[i] != '\0')
		i++;
	if ((*big_buf)[i] == '\n')
		i++;
	while (!(*big_buf)[i])
	{
		ft_free(big_buf);
		return ;
	}
	new_big_buf = ft_strdup(*big_buf + i);
	free(*big_buf);
	*big_buf = new_big_buf;
}
char	*get_next_line(int fd)
{
	static char	*big_buf;
	char		*small_buf;
	char		*line;
	int				been_read;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (ft_free(&big_buf));
	been_read = 1;
	small_buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!small_buf)
		return (NULL);
	big_buf = ft_read(fd, small_buf, big_buf, been_read);
	if (!big_buf)
		return (NULL); 
	line = ft_extract_read_line(big_buf);
	if (!line)
		return (ft_free(&big_buf));
	ft_get_remainder(&big_buf);
	return (line);
}