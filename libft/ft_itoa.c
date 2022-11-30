/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjang <hyunjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:38:57 by hyunjang          #+#    #+#             */
/*   Updated: 2022/07/15 16:21:38 by hyunjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	jaritsu(int n)
{
	size_t	i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	if (i == 0)
		return (1);
	return (i);
}

char	*ft_itoa(int n)
{
	unsigned int	un;
	char			*out;
	size_t			i;
	size_t			sign;

	i = jaritsu(n);
	sign = (n < 0);
	un = (1 - 2 * sign) * n;
	out = malloc((i + sign) + 1);
	if (!out)
		return (0);
	out[(i + sign)] = '\0';
	if (n < 0)
		out[0] = '-';
	while (i)
	{
		out[(i + sign) - 1] = un % 10 + '0';
		un /= 10;
		i--;
	}
	return (out);
}
