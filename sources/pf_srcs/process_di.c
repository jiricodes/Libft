/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:09:48 by jnovotny          #+#    #+#             */
/*   Updated: 2021/08/04 11:42:21 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** d, i Conversion
** The int argument is converted to signed decimal notation.
** The precision, if any, gives the minimum number of digits that must appear;
** if the converted value requires fewer digits, it is padded on the left with
** zeros. The default precision is 1.
** When 0 is printed with an explicit precision 0, the output is empty.
*/

void	ft_process_di(t_format *f)
{
	long	nb;
	int		sign;

	nb = va_arg(f->list, long);
	f->i++;
	if (f->len_mod == j)
		f->out_str = nb == LONG_MIN ? ft_strdup("-9223372036854775808") \
			: ft_ultoa(nb);
	else if (f->len_mod == l || f->len_mod == ll || f->len_mod == z)
		f->out_str = ft_ltoa(nb);
	else if (f->len_mod == L || f->len_mod == nomod)
		f->out_str = ft_ltoa((int)nb);
	else if (f->len_mod == h)
		f->out_str = ft_ltoa((short)nb);
	else if (f->len_mod == hh)
		f->out_str = ft_ltoa((char)nb);
	else
		ft_error(f);
	f->current_length = ft_strlen(f->out_str);
	ft_print_di(f);
}

void	ft_print_di(t_format *f)
{
	char	c;
	size_t	l;

	ft_prec_di(f);
	ft_add_sign(f);
	l = ft_strlen(f->out_str);
	if (f->width > (int)f->current_length)
	{
		c = f->flag.zero ? '0' : ' ';
		if (f->flag.minus)
		{
			add_string_to_buffer(f, f->out_str, l);
			add_n_chars_to_buffer(f, c, (size_t)(f->width - f->current_length));
			// f->out_len += write(1, f->out_str, ft_strlen(f->out_str));
			// while ((f->width--) - ft_strlen(f->out_str) > 0)
			// 	f->out_len += write(1, &c, 1);
		}
		else
		{
			add_n_chars_to_buffer(f, c, (size_t)(f->width - f->current_length));
			add_string_to_buffer(f, f->out_str, l);
			
			// while ((f->width--) - ft_strlen(f->out_str) > 0)
			// 	f->out_len += write(1, &c, 1);
			// f->out_len += write(1, f->out_str, ft_strlen(f->out_str));
		}
		f->current_length = f->width;
	}
	else
		add_string_to_buffer(f, f->out_str, l);
		// f->out_len += write(1, f->out_str, ft_strlen(f->out_str));
}

/*
** Precision and Width for 'di'
*/

void	ft_prec_di(t_format *f)
{
	// char	*tmp;
	// char	*res;
	size_t	len;

	ft_sign(f);
	if (f->out_str[0] == '0' && f->precision == 0)
		f->out_str[0] = '\0';
	else if (f->precision > (int)f->current_length)
	{
		len = f->precision - (int)f->current_length;
		add_n_chars_to_buffer(f, '0', len);
		f->current_length += len;
		// tmp = ft_strnew(len);
		// ft_memset((void *)tmp, 48, len);
		// res = ft_strjoin(tmp, f->out_str);
		// free(f->out_str);
		// free(tmp);
		// f->out_str = res;
	}
}

void	ft_sign(t_format *f)
{
	char	*tmp;

	if (f->out_str[0] == '-')
	{
		tmp = ft_strdup(f->out_str + 1);
		free(f->out_str);
		f->out_str = tmp;
		f->flag.plus = 0;
		f->flag.sign = -1;
	}
	else
		f->flag.sign = 1;
}

void	ft_add_sign(t_format *f)
{
	char	*tmp;
	char	*res;
	char	sign;

	if ((f->flag.plus || f->flag.sign == -1 || f->flag.space) && !f->flag.zero)
	{
		tmp = ft_strnew(1);
		tmp[0] = f->flag.plus ? '+' : ' ';
		f->flag.sign == -1 ? tmp[0] = '-' : 0;
		res = ft_strjoin(tmp, f->out_str);
		free(f->out_str);
		free(tmp);
		f->out_str = res;
	}
	else if ((f->flag.plus || f->flag.sign == -1 || \
		f->flag.space) && f->flag.zero)
	{
		sign = f->flag.plus ? '+' : ' ';
		f->flag.sign == -1 ? sign = '-' : 0;
		f->out_len += write(1, &sign, 1);
		f->width ? f->width-- : 0;
	}
}
