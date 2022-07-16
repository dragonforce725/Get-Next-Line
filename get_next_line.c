/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsantann <jsantann@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 08:54:50 by jsantann          #+#    #+#             */
/*   Updated: 2022/07/16 07:55:24 by mhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *ft_read(int fd, char *line)
{
	char    *buf;
    int     rby;

  	buf = malloc(BUFFER_SIZE + 1 * sizeof(char));
    if (!buf)
		return (NULL);
	rby = 1;
    while (!ft_strchr(line, '\n') && rby != 0)
    {
		rby = read(fd, buf, BUFFER_SIZE);
        if (rby < 0)
            break ;
        buf[rby] = '\0';
        line = ft_strjoin(line, buf);
    }
    free(buf);
    if (rby < 0)
		return (NULL);
	else
		return (line);
}

static char *ft_read_line(char *line)
{
	char	*alloc;
    size_t	count;

	count = 0;
    if (!line)
		return (NULL);
    while (line[count] && line[count] != '\n')
         count++;
    alloc = (char *)malloc((count + 2) * sizeof(char));
    if (!line)
		return (NULL);
	ft_strlcpy(alloc, line, count + 1);
    if (line[count] == '\n')
        alloc[count++] = '\n';
    alloc[count] = '\0';
    return (alloc);
}

static char *ft_save_rest(char *line)
{
	char    *new_line;
    int     i;
    int     j;

    i = 0;
    j = 0;
    while (line[i] && line[i] != '\n')
		i++;
    if (!line[i])
    {
        free(line);
        return (NULL);
    }
    new_line = (char *)malloc((ft_strlen(line) - i + 1) * sizeof(char));
    if (!new_line)
        return (NULL);
    i++;
    while (line[i])
        new_line[j++] = line[i++];
    new_line[j] = '\0';
    free(line);
    return (new_line);
}
char	*get_next_line(int fd)
{
	static char	*file;
    char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    file = ft_read(fd, file);
    if (!file)
        return (NULL);
    line = ft_read_line(file);
    file = ft_save(file);
    return (line);
}
