/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjang <hyunjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:16:32 by hyunjang          #+#    #+#             */
/*   Updated: 2022/07/25 22:15:11 by hyunjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

size_t	ft_putstr(char *s)
{
	int	i;

	if (!s)
		return (write(1, "(null)", 6));
	i = 0;
	while (s[i])
		i++;
	return (write(1, s, i));
}

size_t	ft_int_base(int nbr, char *base)
{
	unsigned int	n;
	unsigned int	div;
	size_t			basesize;
	size_t			prntbyte;

	prntbyte = 0;
	n = nbr;
	if (nbr < 0)
	{
		n = -nbr;
		prntbyte = write(1, "-", 1);
	}
	div = 1;
	basesize = 0;
	while (base[basesize])
		basesize++;
	while (n / div >= basesize)
		div *= basesize;
	while (div != 0)
	{
		prntbyte += write(1, &base[n / div], 1);
		n %= div;
		div /= basesize;
	}
	return (prntbyte);
}

size_t	ft_uint_base(int nbr, char *base)
{
	unsigned int	n;
	unsigned int	div;
	size_t			basesize;
	size_t			prntbyte;

	prntbyte = 0;
	n = nbr;
	div = 1;
	basesize = 0;
	while (base[basesize])
		basesize++;
	while (n / div >= basesize)
		div *= basesize;
	while (div != 0)
	{
		prntbyte += write(1, &base[n / div], 1);
		n %= div;
		div /= basesize;
	}
	return (prntbyte);
}

size_t	ft_ull_base(long long nbr, char *base)
{
	unsigned long long	n;
	unsigned long long	div;
	size_t				basesize;
	size_t				prntbyte;

	prntbyte = write(1, "0x", 2);
	n = nbr;
	div = 1;
	basesize = 0;
	while (base[basesize])
		basesize++;
	while (n / div >= basesize)
		div *= basesize;
	while (div != 0)
	{
		prntbyte += write(1, &base[n / div], 1);
		n %= div;
		div /= basesize;
	}
	return (prntbyte);
}
