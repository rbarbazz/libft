/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xxd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 17:05:46 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/10/08 18:13:25 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	xxd(char *file, int size, int bline)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_printf("%.2hhx", file[i++]);
		if (!(i % 2))
			ft_printf(" ");
		if (!(i % bline))
			ft_printf("\n");
	}
	ft_printf("\n");
}
