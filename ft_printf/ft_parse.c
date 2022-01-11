/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 20:52:20 by bokim             #+#    #+#             */
/*   Updated: 2021/07/08 22:51:15 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_flag(char c, t_opt *option)
{
	if (c == '-')
		option->left = 1;
	else
		option->zero = 1;
	return (option->index + 1);
}

int	ft_parse_width(char c, t_opt *option, va_list ap)
{
	int		tmp;

	tmp = 0;
	if (c == '*')
	{
		tmp = va_arg(ap, int);
		if (tmp > 0)
			option->width = tmp;
		else if (tmp == 0)
			option->zero = 1;
		else
		{
			option->left = 1;
			option->width = tmp * (-1);
		}
	}
	else
		option->width = option->width * 10 + (c - 48);
	return (option->index + 1);
}

int	ft_parse_precision(char c, t_opt *option, va_list ap)
{
	int		tmp;

	tmp = 0;
	if (c == '*')
	{
		tmp = va_arg(ap, int);
		if (tmp < 0)
			option->precision = -1;
		else
			option->precision = tmp;
	}
	else
		option->precision = option->precision * 10 + (c - 48);
	return (option->index + 1);
}

int	ft_parse_type(char c, t_opt *option)
{
	option->type = (int)c;
	return (option->index + 1);
}

int	ft_parse(char *input, t_opt *option, va_list ap)
{
	int		cnt;
	int		*idx;

	cnt = 0;
	idx = &(option->index);
	while (ft_strchr(FLAG, input[*idx]) && input[*idx] != '\0')
		*idx = ft_parse_flag(input[*idx], option);
	while (ft_strchr(DIGIT, input[*idx]) && input[*idx] != '\0')
		*idx = ft_parse_width(input[*idx], option, ap);
	if (input[*idx] == '.')
	{
		option->dot = 1;
		option->precision = 0;
		(*idx)++;
	}
	while (ft_strchr(DIGIT, input[*idx]) && option->dot == 1
		&& input[*idx] != '\0')
		*idx = ft_parse_precision(input[*idx], option, ap);
	if (option->left == 1 && option->zero == 1)
		option->zero = 0;
	if (!(ft_strchr(TYPE, input[*idx]) && input))
		return (-1);
	*idx = ft_parse_type(input[*idx], option);
	cnt += ft_conversion(option->type, option, ap);
	return (cnt);
}
