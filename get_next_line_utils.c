/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: prouvoet <prouvoet@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/06 18:52:11 by prouvoet       #+#    #+#                */
/*   Updated: 2019/12/07 17:47:27 by prouvoet      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strsub(const char *str, unsigned int start, size_t lg)
{
	char	*new;
	size_t	i;

	i = 0;
	new = (char *)malloc((lg + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	while (str[start + i] && i < lg)
	{
		new[i] = str[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return ((void *)dst);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_bzero(void *str, size_t n)
{
	size_t			i;
	unsigned char	*tmp;

	i = 0;
	tmp = (unsigned char*)str;
	while (i < n)
	{
		tmp[i] = 0;
		i++;
	}
}
