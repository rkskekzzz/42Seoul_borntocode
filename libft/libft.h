#ifndef LIBFT_H
# define LIBFT_H


# include <unistd.h>

void*		ft_memset(void* dest, int value, size_t size);
void		ft_bzero(void* dest, size_t size);
void*		ft_memcpy(void* dest, const void* src, size_t size);
void*		ft_memmove(void* dest, const void* src, size_t size);
#endif
