/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjang <hyunjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:20:16 by hyunjang          #+#    #+#             */
/*   Updated: 2022/07/25 22:35:20 by hyunjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_doprint(const char **s, va_list *ap, size_t *prntbyte)
{
	if (*(*s) == 'c')
		(*prntbyte) += ft_putchar(va_arg(*ap, int));
	else if (*(*s) == 's')
		(*prntbyte) += ft_putstr(va_arg(*ap, char *));
	else if (*(*s) == 'p')
		(*prntbyte) += ft_ull_base(va_arg(*ap, long long), "0123456789abcdef");
	else if (*(*s) == 'd' || *(*s) == 'i')
		(*prntbyte) += ft_int_base(va_arg(*ap, int), "0123456789");
	else if (*(*s) == 'u')
		(*prntbyte) += ft_uint_base(va_arg(*ap, int), "0123456789");
	else if (*(*s) == 'x')
		(*prntbyte) += ft_uint_base(va_arg(*ap, int), "0123456789abcdef");
	else if (*(*s) == 'X')
		(*prntbyte) += ft_uint_base(va_arg(*ap, int), "0123456789ABCDEF");
	else if (*(*s) == '%')
		(*prntbyte) += ft_putchar('%');
	(*s)++;
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	size_t	prntbyte;

	if (write(1, 0, 0) < 0)
		return (-1);
	prntbyte = 0;
	va_start(ap, s);
	while (*s != '\0')
	{
		if (*s != '%')
		{
			prntbyte += ft_putchar(*s);
			s++;
			continue ;
		}
		s++;
		ft_doprint(&s, &ap, &prntbyte);
	}
	va_end(ap);
	return (prntbyte);
}
