/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:13:04 by igeorge           #+#    #+#             */
/*   Updated: 2023/01/08 19:37:57 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


static char	*ft_new_save(char *save)
{
	int		i;
	int		j;
	char	*new_save;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		save[0] = '\0';
		return (save);
	}
	i++;
	new_save = malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!new_save)
		return (ft_free_gnl(NULL, save));
	j = 0;
	while (save[i])
		new_save[j++] = save[i++];
	new_save[j] = '\0';
	free(save);
	return (new_save);
}

static char	*ft_get_line(char *save)
{
	int		i;
	char	*line;

	i = 0;
	if (!save[0])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = -1;
	while (save[++i] && save[i] != '\n')
		line[i] = save[i];
	if (save[i] == '\n')
	{
		line[i] = save[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_read(int fd, char *save)
{
	char	*buf;
	int		nbr_oct;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (ft_free_gnl(NULL, save));
	nbr_oct = 1;
	while (!ft_strchr_gnl(save, '\n') && nbr_oct != 0)
	{
		nbr_oct = read(fd, buf, BUFFER_SIZE);
		if (nbr_oct < 0)
			return (ft_free_gnl(buf, save));
		buf[nbr_oct] = '\0';
		if (!buf[0])
		{
			free(buf);
			return (save);
		}
		save = ft_strjoin_gnl(save, buf);
		if (!save)
			return (NULL);
	}
	free(buf);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = ft_read(fd, save);
	if (!save)
		return (NULL);
	line = ft_get_line(save);
	if (!line)
    {
        free(save);
        save = NULL;
        return (NULL);
    }
	save = ft_new_save(save);
	if (!save)
		return (NULL);
	return (line);
}
