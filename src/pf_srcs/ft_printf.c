/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnovotny <jnovotny@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 17:33:10 by jnovotny          #+#    #+#             */
/*   Updated: 2021/08/04 13:26:17 by jnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_dump(t_format *f, const char *format)
{
	int			len;

	len = 0;
	while (format[f->i + len] != '%' && format[f->i + len] != '{' && \
			format[f->i + len] != '\0')
	{
		len++;
	}
	add_string_to_buffer(f, &format[f->i], len);
	f->i += len;
}

int	ft_printf(const char *format, ...)
{
	t_format	f;

	ft_bzero(&f, sizeof(t_format));
	va_start(f.list, format);
	f.fd = 1;
	while (format[f.i] != '\0')
	{
		if (format[f.i] == '%')
			ft_parse(&f, format);
		else if (format[f.i] == '{')
			ft_settings(&f, format);
		else
			ft_dump(&f, format);
	}
	flush_buffer_to_fd(&f);
	va_end(f.list);
	return (f.out_len);
}
