/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjang <hyunjang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:29:56 by hyunjang          #+#    #+#             */
/*   Updated: 2022/07/25 22:15:08 by hyunjang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
size_t	ft_putchar(char c);
size_t	ft_putstr(char *s);
size_t	ft_int_base(int nbr, char *base);
size_t	ft_uint_base(int nbr, char *base);
size_t	ft_ull_base(long long nbr, char *base);
#endif
