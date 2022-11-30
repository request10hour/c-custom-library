/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjang <hyunjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 20:32:27 by hyunjang          #+#    #+#             */
/*   Updated: 2022/07/15 17:13:15 by hyunjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	calc_size(char const *s, char c)
{
	size_t	size;
	size_t	i;

	size = 0;
	i = 0;
	while (s[i])
	{
		if (i == 0)
		{
			if (!(s[i] == c))
				size++;
		}
		else if ((s[i - 1] == c) && !(s[i] == c))
			size++;
		i++;
	}
	return (size);
}

char	*makestr(size_t i, char const *s, char c)
{
	char	*out;
	size_t	len;
	size_t	j;

	len = i;
	while (s[len] != 0 && !(s[len] == c))
		len++;
	out = (char *)malloc(sizeof(char) * (len - i + 1));
	if (!out)
		return (0);
	j = 0;
	while (j < len - i)
	{
		out[j] = s[i + j];
		j++;
	}
	out[j] = 0;
	return (out);
}

char	*creation(size_t n, char const *s, char c)
{
	size_t	size;
	size_t	i;

	size = 0;
	i = 0;
	while (s[i])
	{
		if (i == 0)
		{
			if (!(s[i] == c))
				size++;
		}
		else if ((s[i - 1] == c) && !(s[i] == c))
			size++;
		if (size == n)
			return (makestr(i, s, c));
		i++;
	}
	return (0);
}

char	**freeall(char **split, size_t i)
{
	size_t	n;

	n = 0;
	while (n < i)
	{
		free(split[n]);
		n++;
	}
	free(split);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char		**split;
	char		*tmp;
	size_t		size;
	size_t		i;

	if (!s)
		return (0);
	size = calc_size(s, c);
	split = (char **)malloc(sizeof(char *) * (size + 1));
	if (!split)
		return (0);
	i = 0;
	while (i < size)
	{
		tmp = creation(i + 1, s, c);
		if (!tmp)
			return (freeall(split, i));
		split[i] = tmp;
		i++;
	}
	split[i] = 0;
	return (split);
}
