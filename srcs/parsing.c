/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 10:44:15 by jnovotny          #+#    #+#             */
/*   Updated: 2019/11/13 09:43:43 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_runflags(t_format *f, const char *format)
{
	flag_hash(f, format);
	flag_plus(f);
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
	printf("Data read\n");
	printf("Flags: 0 > %d | # > %d | + > %d | - > %d | ' ' > %d\n", f->flag.zero, f->flag.hash, f->flag.plus, f->flag.minus, f->flag.space);
	printf("Width: %d | Precision: %d | Lenght mod: %d | Conversion: %c\n", f->width, f->precision, f->len_mod, format[f->i]);
	/* create string */
	ft_create_out(f, format);
	
	/* free string? */
	free(f->out_str);
}
