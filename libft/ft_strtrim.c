/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjang <hyunjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 15:11:39 by hyunjang          #+#    #+#             */
/*   Updated: 2022/07/15 17:29:56 by hyunjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*out;
	size_t	i;
	size_t	j;

	if (!s1 || !set)
		return (0);
	i = 0;
	while (s1[i])
	{
		if (!ft_strchr(set, s1[i]))
			break ;
		i++;
	}
	j = ft_strlen(s1);
	if (i == j)
		return (ft_calloc(1, 1));
	while (j)
	{
		if (!ft_strchr(set, s1[j - 1]))
			break ;
		j--;
	}
	out = ft_substr(s1, i, j - i);
	return (out);
}
