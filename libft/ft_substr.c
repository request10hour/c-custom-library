/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjang <hyunjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:18:45 by hyunjang          #+#    #+#             */
/*   Updated: 2022/07/15 18:24:05 by hyunjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	maxlen;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_calloc(1, 1));
	maxlen = ft_strlen(&s[start]);
	if (maxlen < len)
		len = maxlen;
	out = ft_calloc(len + 1, 1);
	if (!out)
		return (0);
	ft_strlcpy(out, &s[start], len + 1);
	return (out);
}
