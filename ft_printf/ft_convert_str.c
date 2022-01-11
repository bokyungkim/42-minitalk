/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 00:03:46 by bokim             #+#    #+#             */
/*   Updated: 2021/07/08 20:17:01 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_cutnput_str(char *str, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		ft_putchar(str[i]);
		i++;
	}
	return ;
}

static void	ft_put_str_right(char *str, t_opt *option)
{
	if (option->zero == 1)
		ft_putzero(option->width - option->precision);
	else
		ft_putspace(option->width - option->precision);
	ft_cutnput_str(str, option->precision);
}

static void	ft_put_str_left(char *str, t_opt *option)
{
	ft_cutnput_str(str, option->precision);
	ft_putspace(option->width - option->precision);
}

int	ft_convert_str(char *str, t_opt *option)
{
	int		len;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (option->precision > len || option->precision <= -1)
		option->precision = len;
	if (option->width <= option->precision)
		ft_cutnput_str(str, option->precision);
	else if (option->left == 0)
		ft_put_str_right(str, option);
	else if (option->left == 1)
		ft_put_str_left(str, option);
	if (option->width > option->precision)
		return (option->width);
	else
		return (option->precision);
}
