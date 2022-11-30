/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  hyunjang < hyunjang@student.42seoul.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:16:09 by  hyunjang         #+#    #+#             */
/*   Updated: 2022/07/18 14:16:09 by  hyunjang        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	maxlen;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
	{
		out = malloc(1);
		out[0] = 0;
		return (out);
	}
	maxlen = ft_strlen(&s[start]);
	if (maxlen < len)
		len = maxlen;
	out = malloc(len + 1);
	if (!out)
		return (0);
	out[0] = 0;
	ft_strlcat(out, &s[start], len + 1);
	return (out);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return (&((char *)s)[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*out;
	size_t	len[2];

	if (!s1 || !s2)
		return (0);
	len[0] = ft_strlen(s1);
	len[1] = ft_strlen(s2);
	if (len[0] + len[1] == 0)
		return (0);
	out = malloc(len[0] + len[1] + 1);
	if (!out)
		return (0);
	out[0] = 0;
	ft_strlcat(out, s1, len[0] + 1);
	ft_strlcat(out, s2, len[0] + len[1] + 1);
	return (out);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	finlen;
	size_t	i;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstlen + srclen < dstsize)
		finlen = srclen + 1;
	else
	{
		finlen = dstsize - dstlen - 1;
		dst[finlen + dstlen] = 0;
	}
	i = 0;
	while (i < finlen)
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	return (dstlen + srclen);
}
