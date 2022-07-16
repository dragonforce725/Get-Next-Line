/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 08:54:50 by jsantann          #+#    #+#             */
/*   Updated: 2022/07/14 19:12:52 by mhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t read(int fd, void *buf, size_t count);

static char *fd_first_read(int fd, char *line)
{
	char    *alloc;
    int     b;

  	alloc = malloc(BUFFER_SIZE + 1 * sizeof(char));
    b = 1;
    while (!ft_strchr(line, '\n') && b != 0)
    {
		b = read(fd, alloc, BUFFER_SIZE);
        if (b == -1)
        {
            free(alloc);
            return (NULL);
        }
        alloc[b] = '\0';
        line = ft_strjoin(line, alloc);
    }
    free(alloc);
    return (line);
}

static char *fd_read_line(char *line)
{
	char    *alloc2;
    int     count;

	count = 0;
    if (!line[count])
		return (NULL);
    while (line[count] && line[count] != '\n')
         count++;
    alloc2 = malloc((count + 2) * sizeof(char));
    count = 0;
    while (line[count] && line[count] != '\n')
    {
        alloc2[count] = line[count];
        count++;
    }
    if (line[count] == '\n')
        alloc2[count++] = '\n';
    alloc2[count] = '\0';
    return (alloc2);
}

static char *fd_save_rest(char *line)
{
	char    *alloc3;
    int     count;
    int     count2;

    count = 0;
    count2 = 0;
    while (line[count] && line[count] != '\n')
        count++;
    if (!line[count])
    {
        free(line);
        return (NULL);
    }
    alloc3 = malloc((ft_strlen(line) - count + 1) * sizeof(char));
    if (!alloc3)
        return (NULL);
    count++;
    while (line[count])
        alloc3[count2++] = line[count++];
    alloc3[count2] = '\0';
    free(line);
    return (alloc3);
}
char	*get_next_line(int fd)
{
	char static	*file;
    char		*line;
	if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    file = fd_first_read(fd, file);
    if (!file)
        return (NULL);
    line = fd_read_line(file);
    file = fd_save_rest(file);
    return (line);
}
