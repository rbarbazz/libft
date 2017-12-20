/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 13:02:24 by rbarbazz          #+#    #+#             */
/*   Updated: 2017/12/20 13:03:28 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinchar(char const *s1, char const c)
{
	char	*c_s1;
	char	c_c;
	char	*r;
	int		i;
	int		j;

	c_s1 = (char *)s1;
	c_c = (char)c;
	if (c_s1 == NULL)
		return (NULL);
	r = (char *)malloc(sizeof(char) * ft_strlen(c_s1) + 2);
	if (!r)
		return (NULL);
	i = 0;
	j = 0;
	while (c_s1[i])
		r[j++] = c_s1[i++];
	r[j] = c_c;
	r[j + 1] = 0;
	return (r);
}
