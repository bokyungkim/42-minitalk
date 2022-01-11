/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 23:25:47 by bokim             #+#    #+#             */
/*   Updated: 2021/07/08 22:40:29 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_get_llnumsize(unsigned long long n, int base)
{
	int		size;

	size = 0;
	if (n == 0)
		size = 1;
	while (n > 0)
	{
		n /= base;
		size++;
	}
	return (size);
}

static void	ft_put_ptr(unsigned long long n)
{
	char	ch;

	if (n >= HEX)
		ft_put_ptr(n / HEX);
	ch = n % HEX;
	if (ch > 9)
		ch += 'a' - 10;
	else
		ch += '0';
	write(FD, &ch, 1);
}

static void	ft_put_ptr_right(unsigned long long n, int num_size, t_opt *option)
{
	ft_putspace(option->width - option->precision - 2);
	ft_putstr_fd("0x", FD);
	ft_putzero(option->precision - num_size);
	if (num_size)
		ft_put_ptr(n);
}

static void	ft_put_ptr_left(unsigned long long n, int num_size, t_opt *option)
{
	ft_putstr_fd("0x", FD);
	ft_putzero(option->precision - num_size);
	if (num_size)
		ft_put_ptr(n);
	ft_putspace(option->width - option->precision - 2);
}

int	ft_convert_ptr(void *ptr, t_opt *option)
{
	unsigned long long	n;
	int					num_size;

	n = (unsigned long long)ptr;
	if (!ptr && option->precision == 0)
		num_size = 0;
	else
		num_size = ft_get_llnumsize(n, HEX);
	if (option->precision < -1 || option->dot != 1
		|| option->precision < num_size)
		option->precision = num_size;
	if (option->width < option->precision + 2)
		option->width = option->precision + 2;
	if (option->left == 0)
		ft_put_ptr_right(n, num_size, option);
	else
		ft_put_ptr_left(n, num_size, option);
	return (option->width);
}
