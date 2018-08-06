/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 10:02:45 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/06 23:29:44 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	check_line(int *last, char **save, char **line)
{
	char	*tmp;

	if (ft_strchr(*save, '\n'))
	{
		tmp = *save;
		*line = dup_to_char(*save, '\n');
		*save = dup_from_char(*save, '\n');
		ft_strdel(&tmp);
		if (!*save || !*save[0])
			*last = 1;
		return (1);
	}
	*line = ft_strdup(*save);
	ft_strdel(save);
	*last = 1;
	return (1);
}

static char	*read_buffer(int *err, const int fd, char **save)
{
	char	buf[BUFF_SIZE];
	int		ret;
	char	*tmp;

	tmp = ft_strnew(0);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		*save = ft_strjoin(tmp, buf);
		ft_strdel(&tmp);
		tmp = *save;
	}
	if (ret < 0)
		*err = -1;
	return (*save);
}

int			get_next_line(const int fd, char **line)
{
	static char	*save = NULL;
	static int	last = 0;
	int			err;

	err = 0;
	if (fd < 0 || !line || BUFF_SIZE < 0)
		return (-1);
	if (last == 1)
		return (0);
	if (!save)
		save = read_buffer(&err, fd, &save);
	if (err < 0)
		return (err);
	return (check_line(&last, &save, line));
}
