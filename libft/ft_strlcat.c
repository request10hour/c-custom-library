/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjang <hyunjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 10:43:35 by hyunjang          #+#    #+#             */
/*   Updated: 2022/07/15 16:59:24 by hyunjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstlen >= dstsize)
		return (dstsize + srclen);
	if (dstlen + srclen < dstsize)
		ft_memcpy(&dst[dstlen], src, srclen + 1);
	else
	{
		ft_memcpy(&dst[dstlen], src, dstsize - dstlen - 1);
		dst[dstsize - 1] = 0;
	}
	return (dstlen + srclen);
}
