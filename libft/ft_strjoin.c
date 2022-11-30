/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjang <hyunjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:55:07 by hyunjang          #+#    #+#             */
/*   Updated: 2022/07/12 20:47:18 by hyunjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*out;
	size_t	len[2];

	if (!s1 || !s2)
		return (0);
	len[0] = ft_strlen(s1);
	len[1] = ft_strlen(s2);
	out = malloc(len[0] + len[1] + 1);
	if (!out)
		return (0);
	ft_strlcpy(out, s1, len[0] + 1);
	ft_strlcat(out, s2, len[0] + len[1] + 1);
	return (out);
}
