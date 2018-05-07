/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbazz <rbarbazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:51:51 by rbarbazz          #+#    #+#             */
/*   Updated: 2018/05/07 18:25:42 by rbarbazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			c_nul(t_arg *arg)
{
	if (arg->flag != '-')
		apply_width(arg);
	arg->ret = arg->ret + write(arg->fd, arg->buffer, ft_strlen(arg->buffer));
	write(arg->fd, "\0", 1);
	arg->ret++;
	arg->buffer = ft_strnew(0);
	apply_width(arg);
	return (0);
}

int			convert_c(t_arg *arg)
{
	arg->width--;
	if (!arg->uc && arg->specifier != '%')
		c_nul(arg);
	else if (arg->flag != '-')
		apply_width(arg);
	if (arg->specifier == '%')
		arg->buffer = ft_strjoinchar(arg->buffer, '%');
	else
		arg->buffer = ft_strjoinchar(arg->buffer, arg->uc);
	apply_width(arg);
	arg->retc = ft_strlen(arg->buffer);
	return (0);
}
