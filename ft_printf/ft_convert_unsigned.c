/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_unsigned.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:40:07 by bokim             #+#    #+#             */
/*   Updated: 2021/07/08 01:53:13 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_lnumsize(unsigned int n, int base)
{
	int		size;

	size = 0;
	if (n == 0)
		size = 1;
	else
	{
		while (n > 0)
		{
			n /= base;
			size++;
		}
	}
	return (size);
}

void	ft_putl_right(t_opt *option, unsigned int n,
		int num_size, int conversion)
{
	int	base;

	if (conversion == SMALLX || conversion == BIGX)
		base = HEX;
	else
		base = DEC;
	ft_putspace(option->width - option->precision);
	ft_putzero(option->precision - num_size);
	ft_put_uint(n, base, conversion);
}

void	ft_putl_left(t_opt *option, unsigned int n,
		int num_size, int conversion)
{
	int	base;

	if (conversion == SMALLX || conversion == BIGX)
		base = HEX;
	else
		base = DEC;
	ft_putzero(option->precision - num_size);
	ft_put_uint(n, base, conversion);
	ft_putspace(option->width - option->precision);
}

int	ft_convert_unsigned(unsigned int n, t_opt *option)
{
	int		num_size;

	if (n == 0 && option->precision == 0)
	{
		ft_putspace(option->width);
		return (option->width);
	}
	num_size = ft_get_lnumsize(n, DEC);
	if (option->zero == 1 && option->precision <= -1)
		option->precision = option->width;
	if (option->precision <= -1 || option->precision < num_size)
		option->precision = num_size;
	if (option->left == 0)
		ft_putl_right(option, n, num_size, DEC);
	else
		ft_putl_left(option, n, num_size, DEC);
	if (option->width > option->precision)
		return (option->width);
	else
		return (option->precision);
}
