/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datafeed.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:06:03 by jnovotny          #+#    #+#             */
/*   Updated: 2021/08/04 20:41:33 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_getflag(t_format *f, const char *format)
{
	while (format[f->i] != '\0' && ft_strchr(FLAG_STR, format[f->i]))
	{
		if (format[f->i] == '0')
			f->flags |= PF_FZERO;
		else if (format[f->i] == '#')
			f->flags |= PF_FHASH;
		else if (format[f->i] == '+')
			f->flags |= PF_FPLUS;
		else if (format[f->i] == '-')
			f->flags |= PF_FMINUS;
		else if (format[f->i] == ' ')
			f->flags |= PF_FSPACE;
		else if (format[f->i] == '*')
			f->width = (int)va_arg(f->list, long);
		f->i++;
	}
}

void	ft_getwidth(t_format *f, const char *format)
{
	size_t	ret_i;

	if (ft_isdigit(format[f->i]))
	{
		f->width = ft_atoi_and_index(&format[f->i], &ret_i);
		f->i += ret_i;
	}
}

void	ft_getprecision(t_format *f, const char *format)
{
	size_t	ret_i;

	ret_i = 1;
	if (format[f->i] == '.')
	{
		f->i++;
		if (format[f->i] == '*')
			f->precision = (int)va_arg(f->list, long);
		else
			f->precision = ft_atoi_and_index(&format[f->i], &ret_i);
		f->i += ret_i;
	}
}

void	ft_getlmod(t_format *f, const char *format)
{
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
	else if (format[f->i] == 'q')
		f->len_mod = ll;
	else if (format[f->i] == 'l')
		f->len_mod = l;
	else if (format[f->i] == 'h')
		f->len_mod = h;
	else if (format[f->i] == 'L')
		f->len_mod = L;
	else if (format[f->i] == 'j')
		f->len_mod = j;
	else if (format[f->i] == 'z' || format[f->i] == 'Z')
		f->len_mod = z;
	else if (format[f->i] == 't')
		f->len_mod = t;
	else
		return ;
	f->i++;
}
