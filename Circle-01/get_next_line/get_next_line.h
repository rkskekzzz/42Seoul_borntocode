/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhshin <suhshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 13:59:59 by suhshin           #+#    #+#             */
/*   Updated: 2021/01/27 14:04:53 by suhshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

int			get_next_line(int fd, char **line);
char*		gnl_strappend(char *str1, char *str2);
int			gnl_check_new_line(char *line);
int			gnl_strslice(char** backup, int i, char** line);
char*		gnl_strldup(char *src, size_t l);
size_t		gnl_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		gnl_strlen(char *str);

#endif
