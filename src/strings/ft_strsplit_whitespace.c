/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_whitespace.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 18:10:43 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/03/14 18:56:26 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			is_space(char *str, int i)
{
	if (str[i] == 32 || str[i] == 9 || str[i] == 10)
		return (1);
	if (str[i] == '\0')
		return (2);
	return (0);
}

int			count_words(char *str)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (is_space(str, i) == 1)
			i++;
		if (!is_space(str, i))
		{
			while (!is_space(str, i))
				i++;
			count++;
		}
	}
	return (count);
}

char		**copy(char **tab, char *str)
{
	int i;
	int wn;
	int cn;

	wn = 0;
	i = 0;
	while (wn < count_words(str))
	{
		cn = 0;
		tab[wn] = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1));
		while (is_space(str, i) == 1)
			i++;
		while (!is_space(str, i))
		{
			tab[wn][cn] = str[i];
			i++;
			cn++;
		}
		tab[wn][cn] = '\0';
		wn++;
	}
	tab[wn] = NULL;
	return (tab);
}

char		**ft_strsplit_whitespace(char *str)
{
	char	**tab;
	int		i;

	i = 0;
	tab = NULL;
	tab = (char**)malloc(sizeof(char*) * (count_words(str) + 1));
	copy(tab, str);
	return (tab);
}
