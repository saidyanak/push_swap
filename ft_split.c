/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syanak <syanak@student.42kocaeli.com.tr >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 22:58:01 by yuocak            #+#    #+#             */
/*   Updated: 2025/03/14 12:24:04 by syanak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "push_swap.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;

	src_len = strlen(src);
	if (src_len + 1 < dstsize)
		ft_memcpy(dst, src, src_len + 1);
	else if (dstsize != 0)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = 0;
	}
	return (src_len);
}

static char	**free_mem(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static int	count_words(const char *str, char sep)
{
	int	count;

	count = 0;
	while (*str != '\0')
	{
		if (*str == sep)
			str++;
		else
		{
			count++;
			while (*str != '\0' && *str != sep)
				str++;
		}
	}
	return (count);
}

static int	word_len(const char *str, char sep)
{
	int	len;

	len = 0;
	while (*str != '\0' && *str != sep)
	{
		len++;
		str++;
	}
	return (len);
}

char	**ft_split(char *s, char c)
{
	char	**arr;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	arr = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	while (*s != '\0')
	{
		while (*s != '\0' && *s == c)
			s++;
		if (*s != '\0' && *s != c)
		{
			arr[i] = (char *)malloc((word_len(s, c) + 1) * sizeof(char));
			if (arr[i] == NULL)
				return (free_mem(arr));
			ft_strlcpy(arr[i], s, (word_len(s, c) + 1));
			s += word_len(s, c);
			i++;
		}
	}
	arr[i] = NULL;
	return (arr);
}
