/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 23:10:41 by bokim             #+#    #+#             */
/*   Updated: 2021/05/17 17:58:59 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	len;
	size_t	i;

	if (!s || !f)
		return (0);
	i = 0;
	len = ft_strlen(s);
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (0);
	while (i < len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	return (str);
}
