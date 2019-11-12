/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 17:33:10 by jnovotny          #+#    #+#             */
/*   Updated: 2019/11/12 21:02:14 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_format	f;

	ft_bzero(&f, sizeof(t_format));
	va_start(f.list, format);
	while(format[f.i] != '\0')
	{
		if(format[f.i] == '%' && format[f.i + 1] != '%')
			ft_parse(&f, format);
		else if (format[f.i] == '%' && format[f.i + 1] == '%')
		{
			f.out_len = f.out_len + write(1, "%", 1);
			f.i = f.i + 2;
		}
		else
		{
			f.out_len = f.out_len + write(1, &format[f.i], 1);
			f.i++;
		}
	}
	va_end(f.list);
	/* assign ret value to smth and clear struct? */
	return(f.out_len);
}
