/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 10:44:15 by jnovotny          #+#    #+#             */
/*   Updated: 2019/11/13 14:53:34 by jnovotny         ###   ########.fr       */
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
	f->i++;
	ft_getflag(f, format);
	ft_getwidth(f, format);
	ft_getprecision(f, format);
	ft_getlmod(f, format);
	ft_runflags(f, format);
}

void	ft_parse(t_format *f, const char *format)
{
	/* get values */
	ft_getinfo(f, format);
	/* create string */
	ft_create_out(f, format);
	
	/* free string? */
	if(f->out_str)
		free(f->out_str);
}
