/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datafeed.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:06:03 by jnovotny          #+#    #+#             */
/*   Updated: 2019/11/11 15:38:26 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_getflag(t_format *f, const char *format)
{
	bzero(&(f->flag), sizeof(t_flag));
	while (ft_strchr(FLAG_STR, format[f->i]))
	{
		if (format[f->i] == '0')
			f->flag.zero = 1;
		else if (format[f->i] == '#')
			f->flag.hash = 1;
		else if (format[f->i] == '+')
			f->flag.plus = 1;
		else if (format[f->i] == '-')
			f->flag.minus = 1;
		else if (format[f->i] == ' ')
			f->flag.space = 1;
		f->i++;
	}
}

void	ft_getwidth(t_format *f, const char *format)
{
	if (ft_isdigit(format[f->i]))
		f->width = ft_atoi(&format[f->i]);
	while (ft_isdigit(format[f->i]))
		f->i++;
}

void	ft_getprecision(t_format *f, const char *format)
{
	if (format[f->i] == '.')
	{
		f->i++;
		f->precision = ft_atoi(&format[f->i]);
		while (ft_isdigit(format[f->i]))
			f->i++;
	}
	else
		f->precision = -1;
}

void	ft_getlmod(t_format *f, const char *format)
{
	f->len_mod = nomod;
	if (format[f->i] == 'h' && format[f->i + 1] == 'h')
	{
		f->len_mod = hh;
		f->i++;
	}
	else if (format[f->i] == 'l' && format[f->i + 1] == 'l')
	{
		f->len_mod = ll;
		f->i++;
	}
	else if (format[f->i] == 'l' && format[f->i + 1] != 'l')
		f->len_mod = l;
	else if (format[f->i] == 'h' && format[f->i + 1] != 'h')
		f->len_mod = h;
	else if (format[f->i] == 'L')
		f->len_mod = L;
	if (f->len_mod != nomod)
		f->i++;
}
