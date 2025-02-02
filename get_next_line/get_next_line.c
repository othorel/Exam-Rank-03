/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:09:24 by olthorel          #+#    #+#             */
/*   Updated: 2025/01/30 16:09:27 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_strdup(char *src)
{
    char    *dest;
    int     i;

    i = 0;
    while (src[i])
        i++;
    dest = (char *)malloc(sizeof(char) * (i + 1));
    if (!dest)
        return (NULL);
    i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char    *get_next_line(int fd)
{
    static char     buffer[BUFFER_SIZE];
    char     line[70000];
    static int      buffer_read;
    static int      buffer_pos;
    unsigned int    i;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    i = 0;
    while (1)
    {
        if (buffer_pos >= buffer_read)
        {
            buffer_read = read(fd, buffer, BUFFER_SIZE);
            buffer_pos = 0;
            if (buffer_read <= 0)
                break ;
        }
        line[i++] = buffer[buffer_pos++];
        if (buffer[buffer_pos -1] == '\n' || i >= sizeof(line) - 1)
            break ;
    }
    line[i] = '\0';
    if (i == 0)
        return (NULL);
    return (ft_strdup(line));
}
