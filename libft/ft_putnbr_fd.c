/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjang <hyunjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 19:06:49 by hyunjang          #+#    #+#             */
/*   Updated: 2022/07/12 16:34:52 by hyunjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	ncopy;
	int		max_jaritsu;
	char	c;

	ncopy = (long)n;
	if (n < 0)
	{
		write(fd, "-", 1);
		ncopy *= -1;
	}
	max_jaritsu = 1;
	while (ncopy / max_jaritsu >= 10)
		max_jaritsu *= 10;
	while (max_jaritsu)
	{
		c = ncopy / max_jaritsu + '0';
		write(fd, &c, 1);
		ncopy %= max_jaritsu;
		max_jaritsu /= 10;
	}
}
