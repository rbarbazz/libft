/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 10:02:45 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/03/11 14:08:50 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*to_backslash(char *str)
{
	int		index;
	char	*dst;

	index = 0;
	while (str[index] != '\n' && str[index] != '\0')
		index++;
	if (!(dst = (char*)malloc(sizeof(char) * (index + 1))))
		return (NULL);
	dst = ft_memcpy(dst, str, index);
	dst[index] = '\0';
	return (dst);
}

int		check_last(char *tmp, char **line, char **save)
{
	if (*tmp && ft_strchr(tmp, '\0'))
	{
		if (*save)
		{
			*line = ft_strjoin(*save, tmp);
			free(*save);
		}
		else
			*line = tmp;
		*save = NULL;
		return (1);
	}
	else if (*save && *save[0] && ft_strchr(*save, '\0'))
	{
		*line = *save;
		*save = NULL;
		return (1);
	}
	free(tmp);
	return (0);
}

int		save_buffer(char *tmp, char **line, char **save)
{
	char	*noleak;

	noleak = to_backslash(tmp);
	if (!*save)
		*line = noleak;
	else
	{
		*line = ft_strjoin(*save, noleak);
		free(noleak);
		free(*save);
	}
	*save = ft_strdup(ft_strchr(tmp, '\n') + 1);
	free(tmp);
	return (1);
}

int		read_buffer(const int fd, char **line, char **save)
{
	char	*noleak;
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;

	tmp = ft_strnew(0);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		noleak = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = noleak;
		if (ft_strchr(buf, '\n'))
			return (save_buffer(tmp, line, save));
	}
	if (ret < 0)
		return (-1);
	return (check_last(tmp, line, save));
}

int		get_next_line(const int fd, char **line)
{
	static char	*save = NULL;
	char		*noleak;

	if (fd < 0)
		return (-1);
	if (save)
	{
		if (ft_strchr(save, '\n'))
		{
			noleak = save;
			*line = to_backslash(save);
			save = ft_strdup(ft_strchr(save, '\n') + 1);
			free(noleak);
			return (1);
		}
	}
	return (read_buffer(fd, line, &save));
}
