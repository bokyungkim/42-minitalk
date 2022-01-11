/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 20:25:31 by bokim             #+#    #+#             */
/*   Updated: 2021/07/08 01:49:14 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_hex(unsigned int n, t_opt *option, int conversion)
{
	int		num_size;

	if (n == 0 && option->precision == 0)
	{
		ft_putspace(option->width);
		return (option->width);
	}
	num_size = ft_get_lnumsize(n, HEX);
	if (option->zero == 1 && option->precision <= -1)
		option->precision = option->width;
	if (option->precision <= -1 || option->precision < num_size)
		option->precision = num_size;
	if (option->left == 0)
		ft_putl_right(option, n, num_size, conversion);
	else
		ft_putl_left(option, n, num_size, conversion);
	if (option->width > option->precision)
		return (option->width);
	else
		return (option->precision);
}
