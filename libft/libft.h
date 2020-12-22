#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>


void*		ft_memset(void* dest, int value, size_t size);
void		ft_bzero(void* dest, size_t size);
void*		ft_memcpy(void* dest, const void* src, size_t size);
void*		ft_memccpy(void* dest, const void* src, int ch, size_t size);
void*		ft_memmove(void* dest, const void* src, size_t size);
void*		ft_memchr(const void* dest, int ch, size_t size);
int			ft_memcmp(const void* ptr1, const void* ptr2, size_t size);
size_t		ft_strlen(const char* str);
size_t		ft_strlcpy(char* dest, const char* src, size_t size);
size_t		ft_strlcat(char *dest, char *src, size_t size);

#endif
