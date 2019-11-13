/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:28:51 by jnovotny          #+#    #+#             */
/*   Updated: 2019/11/13 20:46:42 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** f Conversion
** The double argument is rounded and converted to decimal notation
** in the style [-]ddd.ddd, where the number of digits after
** the decimal-point character is equal to the precision specification.
** If the precision is missing, it is taken as 6; if the precision is
** explicitly zero, no decimal-point character appears.
** If a decimal point appears, at least one digit appears before it.
*/

void	ft_process_f(t_format *f)
{
	long double nbl;
	double nb;

	if (f->len_mod == L)
	{
		nbl = (long double)va_arg(f->list, long double);
		f->out_str = ft_lftoa(nbl, f->precision == -1 ? 6 : f->precision);
	}
	else
	{
		nb = (double)va_arg(f->list, double);
		f->out_str = ft_lftoa(nb, f->precision == -1 ? 6 : f->precision);
	}
	ft_print_f(f);
	f->i++;
}

void	ft_print_f(t_format *f)
{
	char c;

	if (f->width > (int)ft_strlen(f->out_str))
	{
		c = f->flag.zero ? '0' : ' '; 
		if(f->flag.minus)
		{
			f->out_len += write(1, f->out_str, ft_strlen(f->out_str));
			while((f->width--) - ft_strlen(f->out_str) > 0)
				 f->out_len += write(1, &c, 1);
		}
		else
		{
			while((f->width--) - ft_strlen(f->out_str) > 0)
				 f->out_len += write(1, &c, 1);
			f->out_len += write(1, f->out_str, ft_strlen(f->out_str));
		}
	}
	else
		f->out_len += write(1, f->out_str, ft_strlen(f->out_str));
}
