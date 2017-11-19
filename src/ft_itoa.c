/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 09:36:23 by rbarbazz          #+#    #+#             */
/*   Updated: 2017/11/15 10:29:18 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	char	*tmp;
	long	max;

	if (!(str = ft_strnew(0)))
		return (NULL);
	if (!(tmp = ft_strnew(1)))
		return (NULL);
	max = (long)n;
	max = max < 0 ? -max : max;
	if (max == 0)
		str[0] = '0';
	while (max)
	{
		tmp[0] = (max % 10) + 48;
		if (!(str = ft_strjoin(tmp, str)))
			return (NULL);
		max = max / 10;
	}
	if (n < 0)
		if (!(str = ft_strjoin((char*)("-"), str)))
			return (NULL);
	return (str);
}
