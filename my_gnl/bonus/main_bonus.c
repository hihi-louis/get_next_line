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

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line_bonus.h"

int main(void)
{
    int fd1 = open("test.txt", O_RDONLY);
    int fd2 = open("text1.txt", O_RDONLY);
    int fd3 = open("text2.txt", O_RDONLY);
    char *line;

    if (fd1 < 0 || fd2 < 0 || fd3 < 0)
    {
        perror("Error opening file");
        return (1);
    }

    printf("Reading from file1.txt:\n");
    line = get_next_line(fd1);
    printf("%s", line);
    free(line);

    printf("Reading from file2.txt:\n");
    line = get_next_line(fd2);
    printf("%s", line);
    free(line);

    printf("Reading from file3.txt:\n");
    line = get_next_line(fd3);
    printf("%s", line);
    free(line);

    printf("Switching back to file1.txt:\n");
    line = get_next_line(fd1);
    printf("%s", line);
    free(line);

    close(fd1);
    close(fd2);
    close(fd3);
    return (0);
}

