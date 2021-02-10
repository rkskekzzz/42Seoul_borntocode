/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 14:02:12 by suhshin           #+#    #+#             */
/*   Updated: 2021/02/10 16:40:48 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		get_next_line(int fd, char **line)
{
	char buffer[BUFFER_SIZE + 1];
	static char	*backup;
	ssize_t		read_size;
	size_t			i;



	if (fd < 0 || BUFFER_SIZE < 1 || !line)
		return (-1);
	while ((read_size = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[read_size] = '\0';
		// 누수
		backup = gnl_strappend(backup, buffer);
		if ((i = gnl_check_new_line(backup)))
			return (gnl_strslice(&backup, i, line));
	}
	if (backup != NULL)
		free(backup);
	return (0);
}

int		gnl_strslice(char **backup, int i, char **line)
{
	char	*tmp_line;
	char	*tmp_backup;

	if (!*backup)
		return (0);
	tmp_line = gnl_strldup(*backup, i);
	*line = tmp_line;
	tmp_backup = *backup + i + 1;
	free(*backup);
	*backup = NULL;
	if (gnl_strlen(tmp_backup))
		*backup = tmp_backup;
	return (1);
}

char	*gnl_strappend(char *str1, char *str2)
{
	char	*dest;
	size_t	s1;
	size_t	s2;

	if (!str1 && !str2)
		return (NULL);
	if (!str2)
		return (str1);
	if (!str1)
		return (gnl_strldup(str2, gnl_strlen(str2)));
	s1 = gnl_strlen(str1);
	s2 = gnl_strlen(str2);
	if (!(dest = (char *)malloc(s1 + s2 + 1)))
		return (NULL);
	gnl_strlcpy(dest, str1, s1 + 1);
	gnl_strlcpy(dest + s1, str2, s2 + 1);
	return (dest);
}

int		gnl_check_new_line(char *line)
{
	size_t	len;
	size_t	i;

	i = 0;
	if (!line)
		return (-1);
	len = gnl_strlen(line);
	while (i < len)
	{
		if (line[i] == '\n')
			return (i);
		++i;
	}
	return (0);
}
