/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 12:14:13 by jnovotny          #+#    #+#             */
/*   Updated: 2019/11/15 12:48:39 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** The void * pointer argument is printed in hexadecimal
** (as if by %#x or %#lx).
*/

void	ft_process_p(t_format *f)
{
	long unsigned int nb;

	nb = (long unsigned int)va_arg(f->list, void*);
	f->out_str = ft_ultoa_base(nb, 16, 0);
	f->i++;
	ft_print_p(f);
}

void	ft_print_p(t_format *f)
{
	char c;
	
	ft_hash_p(f);
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

void	ft_hash_p(t_format *f)
{
	char	*tmp;
	char	*res;

	tmp = ft_strnew(2);
	tmp[0] = '0';
	tmp[1] = 'x';
	res = ft_strjoin(tmp, f->out_str);
	free(f->out_str);
	free(tmp);
	f->out_str = res;
}
