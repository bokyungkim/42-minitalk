/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 16:10:19 by bokim             #+#    #+#             */
/*   Updated: 2021/05/12 02:32:08 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*pre;
	t_list	*post;

	if (!lst || !del)
		return ;
	post = *lst;
	pre = post;
	while (pre)
	{
		post = post->next;
		del(pre->content);
		free(pre);
		pre = post;
	}
	*lst = NULL;
}
