/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 21:48:04 by bokim             #+#    #+#             */
/*   Updated: 2021/07/06 16:37:44 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_len(int n)
{
	int		len;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*res;
	int				sign;
	int				len;

	sign = 1;
	if (n < 0)
		sign = -1;
	len = ft_num_len(n);
	res = (char *)ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (0);
	res[len--] = '\0';
	if (n == 0)
		res[len] = '0';
	while (len >= 0)
	{
		res[len--] = '0' + (n % 10) * sign;
		n /= 10;
	}
	if (sign == 1)
		return (res);
	res[0] = '-';
	return (res);
}
