/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 00:48:11 by bokim             #+#    #+#             */
/*   Updated: 2021/05/13 15:54:36 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;

	i = ft_strlen(str) - 1;
	if (c == '\0')
		return ((char *)str + i + 1);
	while (i >= 0)
	{
		if ((unsigned char)(str[i]) == (unsigned char)c)
			return ((char *)(str + i));
		i--;
	}
	return (NULL);
}
