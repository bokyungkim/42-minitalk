/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:53:43 by bokim             #+#    #+#             */
/*   Updated: 2021/07/06 16:40:58 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (!*to_find)
		return ((char *)str);
	i = 0;
	while (str[i] && i < len)
	{
		j = 0;
		k = i;
		while (to_find[j] && k < len && str[k] == to_find[j])
		{
			k++;
			j++;
		}
		if (!to_find[j])
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}
