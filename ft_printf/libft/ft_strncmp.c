/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 18:12:41 by bokim             #+#    #+#             */
/*   Updated: 2021/07/06 16:40:43 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] || s2[i]) && i < n)
	{
		if ((unsigned char)(s1[i]) == (unsigned char)(s2[i]))
			i++;
		else
		{
			if ((unsigned char)(s1[i]) > (unsigned char)(s2[i]))
				return (1);
			return (-1);
		}
	}
	return (0);
}
