/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:09:48 by jnovotny          #+#    #+#             */
/*   Updated: 2019/11/12 20:57:10 by jnovotny         ###   ########.fr       */
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
	/* check lenght & redirect*/
	if (f->len_mod == L)
		ft_error(f);
	else if (f->len_mod == nomod)
		ft_print_di(f);
	
	
	
	
	/* */
}

void	ft_print_di(t_format *f)
{
	/* conversion to string */
	f->out_str = ft_itoa(va_arg(f->list, int));
	f->i++;
	f->flag.minus ? f->flag.zero = 0 : 0;
	f->precision >= 0 ? f->flag.zero = 0 : 0;
	/* check precision and width */
	ft_prec_di(f);
	ft_add_sign(f);
	if (f->width > (int)ft_strlen(f->out_str))
	{
		if(f->flag.minus)
		{
			f->out_len += write(1, f->out_str, ft_strlen(f->out_str));
			while(f->width-- > 0)
				 f->out_len += write(1, " ", 1);
		}
		else
		{
			while(f->width-- > 0)
				 f->out_len += write(1, " ", 1);
			f->out_len += write(1, f->out_str, ft_strlen(f->out_str));
		}
	}
}

/*
** Precision and Width for 'di'
*/

void	ft_prec_di(t_format *f)
{
	char	*tmp;
	char	*res;

	ft_sign(f);
	if (f->out_str[0] == '0' && f->precision == 0)
		f->out_str[0] = '\0';
	else if (f->precision > (int)ft_strlen(f->out_str))
	{
		tmp = ft_strnew(f->precision - ft_strlen(f->out_str));
		ft_memset((void*)tmp + f->width, 48, ft_strlen(tmp));
		res = ft_strjoin(tmp, f->out_str);
		free(f->out_str);
		free(tmp);
		f->out_str = res;
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
	char *tmp;
	char *res;

	if (f->flag.plus || f->flag.sign == -1 || f->flag.space)
	{
		tmp = ft_strnew(1);
		tmp[0] = f->flag.plus ? '+' : ' ';
		f->flag.sign == -1 ? tmp[0] = '-' : 0;
		res = ft_strjoin(tmp, f->out_str);
		free(f->out_str);
		free(tmp);
		f->out_str = res;
	}
}