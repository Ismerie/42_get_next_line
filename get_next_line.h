/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igeorge <igeorge@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 19:10:56 by igeorge           #+#    #+#             */
/*   Updated: 2023/01/08 19:42:15 by igeorge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# define BUFFER_SIZE 42

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
int     ft_strchr_gnl(const char *s, int c);
char	*ft_strjoin_gnl(char *save, char *buf);
size_t	ft_strlen(const char *str);
char	*ft_free_gnl(char *str, char *str2);

#endif
