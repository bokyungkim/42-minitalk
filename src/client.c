/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:12:31 by bokim             #+#    #+#             */
/*   Updated: 2022/01/05 20:26:09 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "../include/minitalk.h"

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		ft_putstr_fd("Wrong arguments : [1]filename [2]pid [3]message\n", 1);
		exit(1);
	}
}