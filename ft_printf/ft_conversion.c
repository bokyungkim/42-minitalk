/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 20:55:25 by bokim             #+#    #+#             */
/*   Updated: 2021/07/08 01:48:54 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_numsize(int n, int base)
{
	int		size;

	size = 0;
	if (n == 0)
		size = 1;
	else
	{
		if (n < 0 && n != -2147483648)
			n *= -1;
		while (n > 0 || n == -2147483648)
		{
			n /= base;
			if (n < 0)
				n *= -1;
			size++;
		}
	}
	return (size);
}

int	ft_conversion(int c, t_opt *option, va_list ap)
{
	int		cnt;

	cnt = 0;
	if (c == 'c')
		cnt += ft_convert_char(va_arg(ap, int), option);
	else if (c == 's')
		cnt += ft_convert_str(va_arg(ap, char *), option);
	else if (c == 'd' || c == 'i')
		cnt += ft_convert_int(va_arg(ap, int), option);
	else if (c == '%')
		cnt += ft_convert_percent(option);
	else if (c == 'u')
		cnt += ft_convert_unsigned(va_arg(ap, int), option);
	else if (c == 'x')
		cnt += ft_convert_hex(va_arg(ap, int), option, SMALLX);
	else if (c == 'X')
		cnt += ft_convert_hex(va_arg(ap, int), option, BIGX);
	else if (c == 'p')
		cnt += ft_convert_ptr(va_arg(ap, void *), option);
	return (cnt);
}
