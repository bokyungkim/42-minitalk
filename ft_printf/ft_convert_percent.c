/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:13:15 by bokim             #+#    #+#             */
/*   Updated: 2021/07/08 21:09:13 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_percent(t_opt *option)
{
	int	len;

	len = 1;
	if (option->width > 1)
		len = option->width;
	if (option->left == 0)
	{
		if (option->zero == 1)
			ft_putzero(len - 1);
		else
			ft_putspace(len - 1);
		ft_putchar('%');
	}
	else
	{
		ft_putchar('%');
		ft_putspace(len - 1);
	}
	if (option->width > 1)
		return (option->width);
	else
		return (1);
}
