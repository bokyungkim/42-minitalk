/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 00:03:15 by bokim             #+#    #+#             */
/*   Updated: 2021/07/08 22:23:45 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_char(char c, t_opt *option)
{
	int		len;

	len = 1;
	if (option->width > 1)
		len = option->width;
	if (option->left == 0)
	{
		ft_putspace(len - 1);
		ft_putchar(c);
	}
	else
	{
		ft_putchar(c);
		ft_putspace(len - 1);
	}
	return (len);
}
