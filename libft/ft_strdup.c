/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjang <hyunjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:38:22 by hyunjang          #+#    #+#             */
/*   Updated: 2022/07/15 16:51:26 by hyunjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	size_t	len;

	len = ft_strlen(s1);
	tmp = malloc(len + 1);
	if (!tmp)
		return (0);
	return (ft_memmove(tmp, s1, len + 1));
}
