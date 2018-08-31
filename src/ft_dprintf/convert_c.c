/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:51:51 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/08/31 02:13:01 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_dprintf_c_nul(t_arg *arg)
{
	if (arg->flag != '-')
		apply_width(arg);
	arg->ret = arg->ret + write(arg->fd, arg->buffer, ft_strlen(arg->buffer));
	write(arg->fd, "\0", 1);
	arg->ret++;
	if (!(arg->buffer = ft_strnew(1)))
		exit(EXIT_FAILURE);
	apply_width(arg);
	return (0);
}
