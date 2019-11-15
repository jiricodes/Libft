/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 10:44:15 by jnovotny          #+#    #+#             */
/*   Updated: 2019/11/15 16:40:49 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_runflags(t_format *f, const char *format)
{
	flag_hash(f, format);
	flag_plus(f);
	flag_minus(f);
	flag_zero(f, format);
}

void	ft_getinfo(t_format *f, const char *format)
{
	ft_getflag(f, format);
	ft_getwidth(f, format);
	ft_getprecision(f, format);
	ft_getlmod(f, format);
	ft_runflags(f, format);
	if (ft_strchr(PF_SKIP, format[f->i]))
		f->i++;
}

void	ft_parse(t_format *f, const char *format)
{	
	f->i++;
	ft_getinfo(f, format);
	ft_create_out(f, format);
	if (f->out_str)
		free(f->out_str);
}
