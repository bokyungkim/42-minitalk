/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 16:46:55 by bokim             #+#    #+#             */
/*   Updated: 2021/07/08 03:37:42 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put_right(t_opt *option, int minus, int n, int num_size)
{
	ft_putspace(option->width - option->precision - minus);
	if (minus == 1 && n != -2147483648)
	{
		ft_putchar('-');
		n *= -1;
	}
	ft_putzero(option->precision - num_size);
	ft_put_int(n);
}

static void	ft_put_left(t_opt *option, int minus, int n, int num_size)
{
	if (minus == 1 && n != -2147483648)
	{
		ft_putchar('-');
		n *= -1;
	}
	ft_putzero(option->precision - num_size);
	ft_put_int(n);
	ft_putspace(option->width - option->precision - minus);
}

int	ft_convert_int(int n, t_opt *option)
{
	int		num_size;
	int		minus;

	minus = 0;
	if (n == 0 && option->precision == 0)
	{
		ft_putspace(option->width);
		return (option->width);
	}
	if (n < 0)
		minus = 1;
	num_size = ft_get_numsize(n, DEC);
	if (option->zero == 1 && option->precision <= -1)
		option->precision = option->width - minus;
	if (option->precision <= -1 || option->precision < num_size)
		option->precision = num_size;
	if (option->left == 0)
		ft_put_right(option, minus, n, num_size);
	else
		ft_put_left(option, minus, n, num_size);
	if (option->width > option->precision)
		return (option->width);
	else
		return (option->precision + minus);
}
