/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 10:02:45 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/04/07 15:21:10 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_buffer(int fd, char **save)
{
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	int		ret;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!*save)
			*save = ft_strjoin("", buf);
		else
		{
			tmp = ft_strjoin(*save, buf);
			ft_strdel(save);
			*save = ft_strdup(tmp);
			ft_strdel(&tmp);
		}
		ft_bzero(buf, BUFF_SIZE + 1);
	}
	return (ret);
}

int	get_next_line(const int fd, char **line)
{
	static char	*save = NULL;
	char		*tmp;
	int			ret;

	if (fd < 0 || !line || BUFF_SIZE < 0)
		return (-1);
	if ((ret = read_buffer(fd, &save)) < 0)
		return (-1);
	if (save && save[0])
	{
		*line = dup_to_char(save, '\n');
		tmp = dup_from_char(save, '\n');
		ft_strdel(&save);
		if (tmp)
			save = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
	else
		ft_strdel(line);
	if (!*line && (!save || !*save))
	{
		ft_strdel(&save);
		return (0);
	}
	return (1);
}
