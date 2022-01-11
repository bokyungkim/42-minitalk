/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 21:14:00 by bokim             #+#    #+#             */
/*   Updated: 2021/07/06 17:42:24 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*ft_pass_whitespace(const char *str)
{
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	return (str);
}

int	ft_atoi(const char *str)
{
	long long	result;
	int			sign;

	result = 0;
	sign = 1;
	str = ft_pass_whitespace(str);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		if (result * sign > 2147483647)
			return (-1);
		else if (result * sign < -2147483648)
			return (0);
		else
			result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
