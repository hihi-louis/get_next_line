/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 20:35:47 by tripham           #+#    #+#             */
/*   Updated: 2024/11/26 21:23:10 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int fd;
	char *next_line;

	fd = open("text.txt", O_RDONLY);
	while (1)
	{
		next_line = get_next_line(fd);
		if(!next_line)
			break;
		printf("%s", next_line);
		free(next_line);
	}
	close(fd);
	return (0);
}
